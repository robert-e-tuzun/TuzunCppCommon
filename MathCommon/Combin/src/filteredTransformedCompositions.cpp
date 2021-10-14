//------------------------------------------------------------------
//
//     Compute some members of a sequence of k-compositions of n with
//     some condition as implemented in a filter, and perform some
//     transformation of the compositions (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

#include "MathCommon/Combin/KComposition.h"
#include "MathCommon/Combin/filteredTransformedCompositions.h"

namespace Math_Common::Combin {

//-------------------------------------------------------------------

bool filteredTransformedCompositions(DT::Int32 k, DT::Int32 n,
      DT::Int32 maxNumCompositionsGenerated, DT::VecInt32& prevComposition,
      std::function<bool(const DT::VecInt32&)> filterFunction,
      std::function<DT::VecInt32(const DT::VecInt32&)> transformationFunction,
      std::vector<DT::VecInt32>& results)
{
//     Initialize the composition object.
   KComposition kComp;
   bool startAtBeginning = (prevComposition[0] == -1);
   if (startAtBeginning)
      kComp.init(k, n);
   else
      kComp.setState(prevComposition);

//     Perform the calculation, filtering, and transformation.
   DT::Int32 numCompositions = 0;
   bool done = false;
   bool atLastComposition = false;
   do {
      kComp.findNextComposition();
      DT::VecInt32 comp = kComp.getComposition();

//     Only if the composition satisfies the filter, perform the transformation.
      if (filterFunction(comp)) {
         DT::VecInt32 result = transformationFunction(comp);
         results.push_back(result);
         numCompositions++;
         prevComposition = comp;
      }

      atLastComposition = kComp.atLastComposition();
      done = (atLastComposition ||
              (numCompositions == maxNumCompositionsGenerated));
   }
   while (! done);

//     Remove unused elements.
   results.erase(results.begin()+numCompositions, results.end());

   return atLastComposition;
}

//-------------------------------------------------------------------

} // namespace Math_Common::Combin

