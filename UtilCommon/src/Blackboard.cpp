//------------------------------------------------------------------
//
//     Barest-bones generalized blackboard (implementation).
//
//     Bob Tuzun
//

#include "UtilCommon/Blackboard.h"

namespace DT = Util_Common::Datatypes;

namespace Util_Common {

//------------------------------------------------------------------

Blackboard::Blackboard()
{
   initialize();
}

//------------------------------------------------------------------

Blackboard::Blackboard(const Blackboard &rhs)
{
   mapToObjects_ = rhs.mapToObjects_;
}

//------------------------------------------------------------------

Blackboard &Blackboard::operator=(const Blackboard &rhs)
{
   if (this != &rhs)
      mapToObjects_ = rhs.mapToObjects_;

   return *this;
}

//------------------------------------------------------------------

Blackboard::~Blackboard()
{
   mapToObjects_.clear();
}

//------------------------------------------------------------------
//
//    Initialize blackboard.
//

void Blackboard::initialize()
{
   mapToObjects_.clear();
}

//------------------------------------------------------------------
//
//    Add object to blackboard if the key does not exist within the
//    map.
//

void Blackboard::addObject(std::any blackboardObject, const DT::String& key)
{
   mapToObjects_.insert(std::pair<DT::String, std::any>
                           (key, blackboardObject));
}

//------------------------------------------------------------------
//
//    Remove object from blackboard if the key exists within the map.
//

void Blackboard::removeObject(const DT::String& key)
{
   mapToObjects_.erase(key);
}

//------------------------------------------------------------------
//
//    Get object from blackboard if key exists.  If key does not
//    exist, return a null pointer.
//

std::any Blackboard::getObject(const DT::String& key)
{
   bool found = (mapToObjects_.find(key) != mapToObjects_.end());
   if (found)
      return mapToObjects_.at(key);

   return nullptr;
}

//------------------------------------------------------------------

} // namespace Util_Common

