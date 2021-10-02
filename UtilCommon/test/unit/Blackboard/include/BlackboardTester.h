//--------------------------------------------------------------------
//
//     Test Blackboard class (definition).
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#pragma once

#include "UtilCommon/I_Blackboard.h"

namespace DT = Util_Common::Datatypes;

class BlackboardTester {
   public:
      BlackboardTester(std::shared_ptr<Util_Common::I_Blackboard> blkbdPtr);
      void init(std::shared_ptr<Util_Common::I_Blackboard> blkbdPtr);
      DT::Int32 get_i() const;

   private:
      DT::Int32 i_;
};

