//------------------------------------------------------------------
//
//     Barest-bones generalized blackboard.
//
//     Bob Tuzun
//

#pragma once

#include <string>
#include <any>
#include <map>
#include <memory>

#include "UtilCommon/CppDatatypes.h"
#include "UtilCommon/I_Blackboard.h"

namespace DT = Util_Common::Datatypes;

namespace Util_Common {

class Blackboard : public I_Blackboard {
   public:
      Blackboard();
      Blackboard(const Blackboard& rhs);
      Blackboard& operator=(const Blackboard& rhs);
      ~Blackboard();

      void initialize();
      void addObject(std::any blackboardObject, const DT::String& key);
      void removeObject(const DT::String& key);
      std::any getObject(const DT::String& key);

   private:
      std::map<DT::String, std::any> mapToObjects_;
};

} // namespace Util_Common

