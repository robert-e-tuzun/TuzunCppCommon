//------------------------------------------------------------------
//
//     C++ defined data types (definition).
//
//     Bob Tuzun
//

#pragma once

#include <vector>
#include <string>

namespace Util_Common::Datatypes {

   using Int16 = short int;
   using UInt16 = unsigned short int;
   using Int32 = int;
   using UInt32 = unsigned int;
   using Int64 = long long int;
   using UInt64 = unsigned long long int;

   using Real32 = float;
   using Real64 = double;

   using String = std::string;

   using VecInt16 = std::vector<Int16>;
   using VecUInt16 = std::vector<UInt16>;
   using VecInt32 = std::vector<Int32>;
   using VecUInt32 = std::vector<UInt32>;
   using VecInt64 = std::vector<Int64>;
   using VecUInt64 = std::vector<UInt64>;

   using VecVecInt16 = std::vector<VecInt16>;
   using VecVecUInt16 = std::vector<VecUInt16>;
   using VecVecInt32 = std::vector<VecInt32>;
   using VecVecUInt32 = std::vector<VecUInt32>;
   using VecVecInt64 = std::vector<VecInt64>;
   using VecVecUInt64 = std::vector<VecUInt64>;

   using VecReal32 = std::vector<Real32>;
   using VecReal64 = std::vector<Real64>;

   using VecVecReal32 = std::vector<VecReal32>;
   using VecVecReal64 = std::vector<VecReal64>;

   using VecString = std::vector<String>;

   using VecVecString = std::vector<VecString>;

} // namespace Util_Common::Datatypes

