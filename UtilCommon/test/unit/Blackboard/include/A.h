//----------------------------------------------------------------
//
//     Class A (definition).
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

class A {
   public:
      A();
      DT::Int32 getA();

   private:
      DT::Int32 i_;
};

