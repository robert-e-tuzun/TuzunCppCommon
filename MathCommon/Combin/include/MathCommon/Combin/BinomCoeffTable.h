//------------------------------------------------------------------
//
//     Compute and store binomial coefficients (definition).
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Math_Common::Combin {

class BinomCoeffTable
{
   public:
      BinomCoeffTable();
      BinomCoeffTable(const BinomCoeffTable& rhs);
      BinomCoeffTable& operator=(const BinomCoeffTable& rhs);
      ~BinomCoeffTable();

      void init(DT::Int32 nmax_x);
      DT::Int32 getBinom(DT::Int32 n, DT::Int32 k);

   private:
      DT::Int32 nmax_;

      std::vector<DT::VecInt32> binom_;
};

} // namespace Math_Common::Combin

