//--------------------------------------------------------------------
//
//     Test sortByRank function.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testSortByRank
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "UtilCommon/sortByRank.h"

namespace DT = Util_Common::Datatypes;

BOOST_AUTO_TEST_CASE( sortByRanksTest )
{
   DT::VecInt32 array1 = { 43, 21, 67, 9 };
   DT::VecInt32 ranks = { 2, 1, 3, 0 };
   
   Util_Common::sortByRank<DT::Int32>(array1, ranks);
   BOOST_TEST( (array1 == DT::VecInt32({ 9, 21, 43, 67 })));

   DT::VecString array2 = { "is", "time", "Now", "the" };
   ranks = { 1, 3, 0, 2 };

   Util_Common::sortByRank<DT::String>(array2, ranks);
   BOOST_TEST( (array2 == DT::VecString({ "Now", "is", "the", "time" })));
}

