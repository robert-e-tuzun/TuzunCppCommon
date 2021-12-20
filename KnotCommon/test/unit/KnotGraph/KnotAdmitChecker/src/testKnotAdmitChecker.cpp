//--------------------------------------------------------------------
//
//     Test KnotAdmitChecker class.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testKnotAdmitChecker
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "KnotCommon/InputOutput/PolyhedronReader.h"
#include "KnotCommon/KnotGraph/KnotAdmitChecker.h"

namespace DT = Util_Common::Datatypes;

//--------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE( knotAdmitTests )

BOOST_AUTO_TEST_CASE( check6 )
{
   DT::Int32 numVertices = 6;
   DT::String dirPathPolyhData = "/home/bob/RESEARCH/finalknots/polyh/data/";
   Knot_Common::Input_Output::PolyhedronReader pr;
   pr.prepareForUse(numVertices, dirPathPolyhData);
   std::vector<DT::VecInt32> conTable = pr.getConTable(0);

   Knot_Common::Knot_Graph::KnotAdmitChecker kac;
   kac.init(conTable);

   std::vector<DT::VecInt32> testParams( { { 1, 1, 1, 1, 1, 1 },
                                           { 2, 1, 1, 1, 1, 1 },
                                           { 2, 2, 1, 1, 1, 1 },
                                           { 2, 3, 1, 1, 1, 1 },
                                           { 3, 1, 1, 1, 1, 1 },
                                           { 3, 3, 1, 1, 1, 1 }
                                         } );
   DT::VecInt32 expected = { 3, 2, 1, 1, 2, 1 };

   DT::Int32 numTests = expected.size();
   for (DT::Int32 i=0; i<numTests; ++i) {
      DT::VecInt32 cts = testParams[i];
      BOOST_TEST( kac.numLoops(cts) == expected[i] );
      BOOST_TEST( kac.admitsKnot(cts) == (expected[i] == 1) );
   }
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE( check8 )
{
   DT::Int32 numVertices = 8;
   DT::String dirPathPolyhData = "/home/bob/RESEARCH/finalknots/polyh/data/";
   Knot_Common::Input_Output::PolyhedronReader pr;
   pr.prepareForUse(numVertices, dirPathPolyhData);
   std::vector<DT::VecInt32> conTable = pr.getConTable(0);

   Knot_Common::Knot_Graph::KnotAdmitChecker kac;
   kac.init(conTable);

   std::vector<DT::VecInt32> testParams( { { 1, 1, 1, 1, 1, 1, 1, 1 } } );
   DT::VecInt32 expected = { 1 };

   DT::Int32 numTests = expected.size();
   for (DT::Int32 i=0; i<numTests; ++i) {
      DT::VecInt32 cts = testParams[i];
      BOOST_TEST( kac.numLoops(cts) == expected[i] );
      BOOST_TEST( kac.admitsKnot(cts) == (expected[i] == 1) );
   }
}

BOOST_AUTO_TEST_SUITE_END()

