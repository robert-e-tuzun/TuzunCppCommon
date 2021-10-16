//--------------------------------------------------------------------
//
//     Test BinomCoeffTable class.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testBinomCoeffTable
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "MathCommon/Combin/BinomCoeffTable.h"

namespace DT = Util_Common::Datatypes;

BOOST_AUTO_TEST_SUITE( binomTests )

BOOST_AUTO_TEST_CASE( positiveArguments )
{
   DT::Int32 nmax = 9;
   Math_Common::Combin::BinomCoeffTable bn;
   bn.init(nmax);

   BOOST_TEST( bn.getBinom(5, 2) == 10 );
   BOOST_TEST( bn.getBinom(8, 3) == 56 );
   BOOST_TEST( bn.getBinom(8, 9) == 0 );
   BOOST_TEST( bn.getBinom(7, -1) == 0 );
}

BOOST_AUTO_TEST_CASE( negativeArguments )
{
   DT::Int32 nmax = 9;
   Math_Common::Combin::BinomCoeffTable bn;
   bn.init(nmax);

   BOOST_TEST( bn.getBinom(-5, 2) == 15 );
   BOOST_TEST( bn.getBinom(-4, -7) == -20 );
   BOOST_TEST( bn.getBinom(-7, -5) == 0 );
}

BOOST_AUTO_TEST_CASE( vanDerMonde )
{
   DT::Int32 nmax = 9;
   Math_Common::Combin::BinomCoeffTable bn;
   bn.init(nmax);

   DT::Int32 n = 4;
   DT::Int32 m = 5;
   DT::Int32 r = 3;

   DT::Int32 sum = 0;
   for (DT::Int32 k=0; k<=n; ++k) {
      sum += bn.getBinom(n, k)*bn.getBinom(m,r-k);
   }

   BOOST_TEST( sum == bn.getBinom(n+m, r) );
}

BOOST_AUTO_TEST_SUITE_END()

