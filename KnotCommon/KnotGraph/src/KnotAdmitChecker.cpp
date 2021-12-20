//----------------------------------------------------------------
//
//     Connection type knot admission checker (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "KnotCommon/KnotGraph/KnotAdmitChecker.h"

namespace Knot_Common::Knot_Graph {

//----------------------------------------------------------------

KnotAdmitChecker::KnotAdmitChecker()
{
   partners4_ = { { 2, 3, 0, 1 }, { 1, 0, 3, 2 }, { 3, 2, 1, 0 } };
}

//----------------------------------------------------------------

KnotAdmitChecker::~KnotAdmitChecker()
{
}

//----------------------------------------------------------------

void KnotAdmitChecker::init(const std::vector<DT::VecInt32>& conTable)
{
   conTable_ = conTable;
   numVertices_ = conTable_.size();
}

//----------------------------------------------------------------

DT::Int32 KnotAdmitChecker::numLoops(const DT::VecInt32& cts)
{
   DT::Int32 numLoopsIn = 0;
   DT::Int32 numEndpointsUsed = 0;
   initLoopVars();

   bool done = false;
   do {
      numEndpointsUsed += numEndpointsInNextLoop(cts);
      numLoopsIn++;
      done = (numEndpointsUsed == 4*numVertices_);
   }
   while (! done);

   return numLoopsIn;
}

//----------------------------------------------------------------

void KnotAdmitChecker::initLoopVars()
{
   std::deque<bool> row = { false, false, false, false };
   isEndpointUsed_.clear();
   for (DT::Int32 i=0; i<numVertices_; ++i)
      isEndpointUsed_.push_back(row);
}

//----------------------------------------------------------------

DT::Int32 KnotAdmitChecker::numEndpointsInNextLoop(const DT::VecInt32& cts)
{
   auto [startVertex, startLoc] = findFirstUnusedEndpoint(cts);
   DT::Int32 curVertex = startVertex;
   DT::Int32 curLoc = startLoc;

   DT::Int32 numEndpointsInLoop = 0;
   bool done = false;
   do {
//     Set previous vertex to current and count in loop.
      isEndpointUsed_[curVertex][curLoc] = true;
      DT::Int32 prevVertex = curVertex;
      DT::Int32 prevLoc = curLoc;
      numEndpointsInLoop++;

//     Find partner location within vertex given ct and count in loop.
      DT::Int32 partnerLoc = partners4_[cts[prevVertex]-1][prevLoc];
      isEndpointUsed_[prevVertex][partnerLoc] = true;
      numEndpointsInLoop++;

//     Find connection of partner location to outside vertex.
      auto ep = findEndpointAdjacentTo(prevVertex, partnerLoc);
      curVertex = ep.first;
      curLoc = ep.second;
      done = ((curVertex == startVertex) && (curLoc == startLoc));
   }
   while (! done);

   return numEndpointsInLoop;
}

//----------------------------------------------------------------

std::pair<DT::Int32, DT::Int32>
KnotAdmitChecker::findFirstUnusedEndpoint(const DT::VecInt32& cts)
{
   DT::Int32 i = -1;
   for (const auto& row : isEndpointUsed_) {
      i++;

      DT::Int32 j = -1;
      for (bool b : row) {
         j++;
         if (! b)
            return std::pair<DT::Int32, DT::Int32>( { i, j } );
      }
   }

//     Should never reach here.  This statement is here only to suppress
//     compiler warnings.
   return std::pair<DT::Int32, DT::Int32>( { -1, -1 } );
}

//----------------------------------------------------------------

std::pair<DT::Int32, DT::Int32>
KnotAdmitChecker::findEndpointAdjacentTo(DT::Int32 vertex, DT::Int32 loc)
{
   DT::Int32 adjacentVertex = conTable_[vertex][loc];

   DT::Int32 adjacentLoc = -1;
   for (DT::Int32 j=0; j<conTable_[vertex].size(); ++j)
      if (conTable_[adjacentVertex][j] == vertex) {
         adjacentLoc = j;
         break;
      }

   return std::pair<DT::Int32, DT::Int32>( { adjacentVertex, adjacentLoc } );
}

//----------------------------------------------------------------

bool KnotAdmitChecker::admitsKnot(const DT::VecInt32& cts)
{
   return (numLoops(cts) == 1);
}

//----------------------------------------------------------------

} // namespace Knot_Common::Knot_Graph

