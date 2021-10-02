//--------------------------------------------------------------------
//
//     Test Blackboard class.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testBlackboard
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <any>

#include "UtilCommon/Blackboard.h"
#include "BlackboardTester.h"

namespace DT = Util_Common::Datatypes;

BOOST_AUTO_TEST_CASE( BlackboardRetrieve )
{
//     Inject blackboard into BlackboardTester object.
   Util_Common::BlackboardPtr blkbdPtr =
          std::make_shared<Util_Common::Blackboard>();
   BlackboardTester bt1(blkbdPtr);

//     BlackboardTester object returns its i value, which should be 2.
   DT::Int32 i = bt1.get_i();
   BOOST_TEST( i == 2 );
}

