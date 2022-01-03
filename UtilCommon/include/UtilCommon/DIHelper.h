//------------------------------------------------------------------
//
//     Header only library for dependency injection helper functions.
//
//     Bob Tuzun
//

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <any>
#include <memory>
#include <algorithm>

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

using DepMap = std::unordered_map<DT::String, std::any>;
using DepMapMap = std::unordered_map<DT::String, DepMap>;

//----------------------------------------------------------------

namespace Util_Common::DI {

template <typename ClassType>
std::shared_ptr<ClassType> getDependency(
   const DepMap& depMap, const DT::String& className, DT::Int32 depNum)
{
   std::stringstream s;
   s << className << "_" << depNum;

   std::any depAny = depMap.at(s.str());
   return std::any_cast<std::shared_ptr<ClassType> >(depAny);
}

//----------------------------------------------------------------

template <typename ClassPtrType, typename ClassType>
void createAndAddDependency(
  DepMap& depMap, const DT::String& className, DT::Int32 howMany)
{
   for (DT::Int32 i=0; i<howMany; ++i) {
      std::stringstream s;
      s << className << "_" << i;

      std::shared_ptr<ClassPtrType> dependency = std::make_shared<ClassType>();
      depMap[s.str()] = dependency;
   }
}

//----------------------------------------------------------------

void addExistingDependency(
  DepMap& depMap, const DepMap& depMapThis, const DT::String& dependencyName);

DepMap createDependencyMap(const DepMap& depMapAll,
                           const DT::VecString& dependencyNames);

DepMapMap createDependencyMaps(
   const DepMap& depMapAll, const std::unordered_map<DT::String, DT::VecString>& nameMap);

//----------------------------------------------------------------

} // namespace Util_Common::DI

