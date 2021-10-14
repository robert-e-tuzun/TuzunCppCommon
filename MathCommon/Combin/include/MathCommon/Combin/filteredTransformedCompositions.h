//------------------------------------------------------------------
//
//     Compute some members of a sequence of k-compositions of n with
//     some condition as implemented in a filter, and perform some
//     transformation of the compositions.
//
//     Bob Tuzun
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

namespace Math_Common::Combin {

//-------------------------------------------------------------------

bool filteredTransformedCompositions(DT::Int32 k, DT::Int32 n,
      DT::Int32 maxNumCompositionsGenerated, DT::VecInt32& prevComposition,
      std::function<bool(const DT::VecInt32&)> filterFunction,
      std::function<DT::VecInt32(const DT::VecInt32&)> transformationFunction,
      std::vector<DT::VecInt32>& chunk);

//-------------------------------------------------------------------

} // namespace Math_Common::Combin

