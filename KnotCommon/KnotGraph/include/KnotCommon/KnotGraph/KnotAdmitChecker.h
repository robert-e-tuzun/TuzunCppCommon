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

      virtual void init(const std::vector<DT::VecInt32>& conTable);
      virtual DT::Int32 numLoops(const DT::VecInt32& cts);
      virtual bool admitsKnot(const DT::VecInt32& cts);

   private:
      void initLoopVars();
      DT::Int32 numEndpointsInNextLoop(const DT::VecInt32& cts);
      std::pair<DT::Int32, DT::Int32>
           findFirstUnusedEndpoint(const DT::VecInt32& cts);
      std::pair<DT::Int32, DT::Int32>
           findEndpointAdjacentTo(DT::Int32 vertex, DT::Int32 loc);

      DT::Int32 numVertices_;

      std::vector<DT::VecInt32> partners4_;
      std::vector<DT::VecInt32> conTable_;

      std::deque<std::deque<bool> > isEndpointUsed_;
};

} // namespace Knot_Common::Knot_Graph

