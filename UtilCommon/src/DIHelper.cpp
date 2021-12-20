//------------------------------------------------------------------
//
//     Non-template dependency injection helper functions.
//
//     Bob Tuzun
//

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <any>
#include <memory>
#include <algorithm>

#include "UtilCommon/DIHelper.h"

//----------------------------------------------------------------

namespace Util_Common::DI {

//----------------------------------------------------------------

void addExistingDependency(
  DepMap& depMap, const DT::String& className, const std::any& dependency)
{
   depMap[className] = dependency;
}

//----------------------------------------------------------------

DepMap createDependencyMap(const DepMap& depMapAll,
                           const DT::VecString& dependencyNames)
{
   DepMap depMap;
   for (const auto& name : dependencyNames)
      depMap[name] = depMapAll.at(name);

   return depMap;
}

//----------------------------------------------------------------

DepMapMap createDependencyMaps(
   const DepMap& depMapAll, const std::unordered_map<DT::String, DT::VecString>& nameMap)
{
   DepMapMap depMaps;

   for (const auto& [className, dependencyNames] : nameMap) {
      DepMap depMap = createDependencyMap(depMapAll, dependencyNames);
      depMaps[className] = depMap;
   }

   return depMaps;
}

//----------------------------------------------------------------

} // namespace Util_Common::DI

