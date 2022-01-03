//----------------------------------------------------------------------
//
//     Connection type knot admission checker.
//
//     Bob Tuzun
//

#pragma once

#include <deque>

#include "KnotCommon/KnotGraph/I_KnotAdmitChecker.h"

namespace Knot_Common::Knot_Graph {

class KnotAdmitChecker : public I_KnotAdmitChecker
{
   public:
      KnotAdmitChecker();
      ~KnotAdmitChecker();

      virtual void init(const DT::VecVecInt32& conTable);
      virtual DT::Int32 numLoops(const DT::VecInt32& cts);
      virtual bool admitsKnot(const DT::VecInt32& cts);
      virtual DT::VecVecInt32 loopsInvolvedVertices(const DT::VecInt32& cts);

   private:
      std::vector<DT::VecVecInt32> loopsForCts(const DT::VecInt32& cts);
      DT::VecVecInt32 nextLoop(const DT::VecInt32& cts);
      void initLoopVars();
      std::pair<DT::Int32, DT::Int32>
           findFirstUnusedEndpoint(const DT::VecInt32& cts);
      std::pair<DT::Int32, DT::Int32>
           findEndpointAdjacentTo(DT::Int32 vertex, DT::Int32 loc);
      DT::VecInt32 involvedVerticesForLoop(const DT::VecVecInt32& loop);

      DT::Int32 numVertices_;

      DT::VecVecInt32 partners4_;
      DT::VecVecInt32 conTable_;

      std::deque<std::deque<bool> > isEndpointUsed_;
};

} // namespace Knot_Common::Knot_Graph

