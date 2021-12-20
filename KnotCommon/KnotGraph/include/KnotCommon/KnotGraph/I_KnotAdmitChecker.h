//----------------------------------------------------------------------
//
//     Connection type knot admission checker (interface).
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Knot_Common::Knot_Graph {

class I_KnotAdmitChecker
{
   public:
      virtual ~I_KnotAdmitChecker() {};

      virtual void init(const std::vector<DT::VecInt32>& conTable) = 0;
      virtual DT::Int32 numLoops(const DT::VecInt32& cts) = 0;
      virtual bool admitsKnot(const DT::VecInt32& cts) = 0;
};

} // namespace Knot_Common::Knot_Graph

