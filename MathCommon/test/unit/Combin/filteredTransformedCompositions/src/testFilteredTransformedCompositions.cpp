//--------------------------------------------------------------------
//
//     Test filteredTransformedCompositions function.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testFilteredTransformedCompositions
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "MathCommon/Combin/KComposition.h"
#include "MathCommon/Combin/filteredTransformedCompositions.h"

namespace DT = Util_Common::Datatypes;

//--------------------------------------------------------------------

std::vector<DT::VecInt32>
getFiltTransfComps(Math_Common::Combin::FiltTransfArgs& args)
{
   std::vector<DT::VecInt32> comps;

   bool done = false;
   do {
      std::vector<DT::VecInt32> compsCur =
         Math_Common::Combin::filteredTransformedCompositions(args);
      comps.insert(comps.end(), compsCur.begin(), compsCur.end());
      done = args.atLastComposition;
   }
   while (! done);

   return comps;
}

//--------------------------------------------------------------------

bool allEntriesNonNegativeEven(const std::vector<DT::VecInt32>& comps)
{
   for (const auto& comp : comps)
      for (DT::Int32 e : comp)
         if ((e < 0) || ((e%2) != 0))
            return false;

   return true;
}

//--------------------------------------------------------------------

bool entriesSumToN(DT::Int32 n, const std::vector<DT::VecInt32>& comps)
{
   for (const auto& comp : comps) {
      DT::Int32 sum = 0;
      for (DT::Int32 e : comp)
         sum += e;

      if (sum != n)
         return false;
   }

   return true;
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE( filtTransfTests )

BOOST_AUTO_TEST_CASE( allEvens1 )
{
//     All compositions let through, transformed by multiplying each entry by 2.
   Math_Common::Combin::FiltTransfArgs args;
   args.k = 5;
   args.n = 6;
   args.maxNumCompositionsGenerated = 10;
   args.prevComposition = { -1 };
   args.filterFunction = [](const DT::VecInt32& comp)
          {
             return true;
          };
   args.transformationFunction = [](const DT::VecInt32& comp)
          {
             DT::VecInt32 newComp(comp);
             for (DT::Int32& e : newComp)
                e *= 2;

             return newComp;
          };
   args.atLastComposition = false;

   std::vector<DT::VecInt32> comps1 = getFiltTransfComps(args);

//     Only compositions with all even entries let through, identity
//     transformation.
   args.k = 5;
   args.n = 12;
   args.maxNumCompositionsGenerated = 20;
   args.prevComposition = { -1 };
   args.filterFunction = [](const DT::VecInt32& comp)
          {
             for (DT::Int32 e : comp)
                if ((e%2) == 1)
                   return false;

             return true;
          };
   args.transformationFunction = [](const DT::VecInt32& comp)
          {
             return comp;
          };
   args.atLastComposition = false;

   std::vector<DT::VecInt32> comps2 = getFiltTransfComps(args);

//     The two filter-transform schemes should yield identical results, and
//     all entries should be even and should sum to n = 12.
   BOOST_TEST( allEntriesNonNegativeEven(comps1) );
   BOOST_TEST( entriesSumToN(args.n, comps1) );
   BOOST_TEST( comps1 == comps2 );
}

BOOST_AUTO_TEST_SUITE_END()

