//------------------------------------------------------------------
//
//     Function template for sorting a std::vector of some type using
//     a table of precomputed ranks.
//
//     Bob Tuzun
//

#pragma once

#include <vector>
#include <algorithm>

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Util_Common {

template <typename T>
void sortByRank(std::vector<T>& vecT, const DT::VecInt32& ranksIn)
{
//     If vector is already sorted, return.
   if (std::is_sorted(ranksIn.begin(), ranksIn.end()))
         return;

//     Perform loop to sort vector by rank.  The copied ranks array is
//     sorted at the same time as vecT.
   DT::VecInt32 ranks(ranksIn);

   DT::Int32 locNonSort = -1;
   DT::Int32 sizeArr = ranks.size();
   bool isSorted = false;
   do {
//     Determine first location of non-sortedness.
      for (DT::Int32 i=locNonSort+1; i<sizeArr; ++i) {
         if (ranks[i] != i) {
            locNonSort = i;
            break;
         }
      }

//     Perform swaps involving first non-sorted element location (locNonSort)
//     until that location has the element of the same rank.
//     Each swap places element at locNonSort in the position of its rank,
//     i.e., in the proper place for sorted order.
      do {
         DT::Int32 curRank = ranks[locNonSort];
         std::swap(vecT[locNonSort], vecT[curRank]);
         std::swap(ranks[locNonSort], ranks[curRank]);
      }
      while (ranks[locNonSort] != locNonSort);
   
      isSorted = std::is_sorted(ranks.begin()+locNonSort, ranks.end());
   }
   while (! isSorted);
}

} // namespace Util_Common

