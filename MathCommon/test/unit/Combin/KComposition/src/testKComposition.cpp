//--------------------------------------------------------------------
//
//     Test KComposition class.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testKComposition
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "MathCommon/Combin/BinomCoeffTable.h"
#include "MathCommon/Combin/KComposition.h"

namespace DT = Util_Common::Datatypes;

//--------------------------------------------------------------------

std::vector<DT::VecInt32> getKComps(DT::Int32 k, DT::Int32 n)
{
   Math_Common::Combin::KComposition kc;
   kc.init(k, n);

   std::vector<DT::VecInt32> comps;

   bool done = false;
   do {
      kc.findNextComposition();
      DT::VecInt32 comp = kc.getComposition();
      comps.push_back(comp);
      done = kc.atLastComposition();
   }
   while (! done);

   return comps;
}

//--------------------------------------------------------------------

std::vector<DT::VecInt32> getKCompsInterrupt(DT::Int32 k, DT::Int32 n,
      DT::Int32 interruptIndex)
{
   Math_Common::Combin::KComposition kc1;
   kc1.init(k, n);

   std::vector<DT::VecInt32> comps;

//     Get compositions up to interrupt.
   bool done = false;
   DT::Int32 index = 0;
   DT::VecInt32 state;
   do {
      index++;
      kc1.findNextComposition();
      DT::VecInt32 comp = kc1.getComposition();
      comps.push_back(comp);

      bool atLast = kc1.atLastComposition();
      bool atInterrupt = (index == interruptIndex);
      if (atInterrupt)
         state = kc1.getState();
      done = (atLast || atInterrupt);
   }
   while (! done);

//     Get compositions after interrupt.
   Math_Common::Combin::KComposition kc2;
   kc2.setState(state);

   done = false;
   do {
      kc2.findNextComposition();
      DT::VecInt32 comp = kc2.getComposition();
      comps.push_back(comp);

      done = kc2.atLastComposition();
   }
   while (! done);

   return comps;
}

//--------------------------------------------------------------------

bool allEntriesNonNegative(const std::vector<DT::VecInt32>& comps)
{
   for (const auto& comp : comps)
      for (DT::Int32 e : comp)
         if (e < 0)
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

bool isSortedAndNoDuplicates(std::vector<DT::VecInt32>& comps)
{
   bool isSorted = std::is_sorted(comps.begin(), comps.end());
   if (! isSorted)
      return false;

   DT::UInt32 sizeBefore = comps.size();
   comps.erase(unique(comps.begin(), comps.end()), comps.end());
   DT::UInt32 sizeAfter = comps.size();

   return (sizeBefore == sizeAfter);
}

//--------------------------------------------------------------------

bool hasCorrectNumberOfComps(DT::Int32 k, DT::Int32 n,
          std::vector<DT::VecInt32>& comps)
{
   Math_Common::Combin::BinomCoeffTable bn;
   bn.init(n+k-1);

   DT::UInt32 size = comps.size();
   return (size == bn.getBinom(n+k-1, k-1));
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE( kCompositionTests )

BOOST_AUTO_TEST_CASE( checkComps )
{
   std::vector<DT::VecInt32> testParams( { { 5, 9 }, { 6, 0 }, { 12, 8 } } );

   for (const auto& params : testParams) {
      DT::Int32 k = params[0];
      DT::Int32 n = params[1];
      std::vector<DT::VecInt32> comps = getKComps(k, n);;

      BOOST_TEST( allEntriesNonNegative(comps) );
      BOOST_TEST( entriesSumToN(n, comps) );
      BOOST_TEST( isSortedAndNoDuplicates(comps) );
      BOOST_TEST( hasCorrectNumberOfComps(k, n, comps) );
   }
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE( validateInterrupt )
{
   std::vector<DT::VecInt32> testParams( { { 5, 9 }, { 12, 8 } } );

   DT::Int32 interruptIndex = 10;
   for (const auto& params : testParams) {
      DT::Int32 k = params[0];
      DT::Int32 n = params[1];
      std::vector<DT::VecInt32> comps1 = getKComps(k, n);;
      std::vector<DT::VecInt32> comps2 =
            getKCompsInterrupt(k, n, interruptIndex);

      BOOST_TEST( comps1 == comps2 );
   }
}

BOOST_AUTO_TEST_SUITE_END()

