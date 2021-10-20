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

std::vector<DT::VecInt32> filteredTransformedCompositions(FiltTransfArgs& args)
{
   std::vector<DT::VecInt32> results;
   if (args.atLastComposition)
      return results;

//     Initialize the composition object.
   KComposition kComp;
   bool startAtBeginning = (args.prevComposition[0] == -1);
   if (startAtBeginning) {
      kComp.init(args.k, args.n);
      args.atLastComposition = false;
   }
   else
      kComp.setState(args.prevComposition);

//     Perform the calculation, filtering, and transformation.
   DT::Int32 numCompositions = 0;
   bool done = false;
   do {
      kComp.findNextComposition();
      DT::VecInt32 comp = kComp.getComposition();

//     Only if the composition satisfies the filter, perform the transformation.
      if (args.filterFunction(comp)) {
         DT::VecInt32 result = args.transformationFunction(comp);
         results.push_back(result);
         numCompositions++;
         args.prevComposition = comp;
      }

      args.atLastComposition = kComp.atLastComposition();
      done = (args.atLastComposition ||
              (numCompositions == args.maxNumCompositionsGenerated));
   }
   while (! done);

   return results;
}

//-------------------------------------------------------------------

} // namespace Math_Common::Combin

