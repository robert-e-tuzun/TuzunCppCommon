//------------------------------------------------------------------
//
//     Barest-bones generalized blackboard (interface).
//
//     Bob Tuzun
//

#pragma once

#include <string>
#include <any>
#include <map>

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Util_Common {

class I_Blackboard {
   public:
      virtual ~I_Blackboard() {};

      virtual void initialize() = 0;
      virtual void
           addObject(std::any blackboardObject, const DT::String& key) = 0;
      virtual void removeObject(const DT::String& key) = 0;
      virtual std::any getObject(const DT::String& key) = 0;

   private:
};

using BlackboardPtr = std::shared_ptr<I_Blackboard>;

} // namespace Util_Common

