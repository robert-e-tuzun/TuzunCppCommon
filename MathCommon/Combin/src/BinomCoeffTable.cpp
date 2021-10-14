//------------------------------------------------------------------
//
//     Compute and store binomial coefficients (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "MathCommon/Combin/BinomCoeffTable.h"

namespace Math_Common::Combin {

//-------------------------------------------------------------------

BinomCoeffTable::BinomCoeffTable()
{
   nmax_ = -1;
}

//-------------------------------------------------------------------
//
//     Copy constructor for deep copy.
//

BinomCoeffTable::BinomCoeffTable(const BinomCoeffTable& rhs)
{
   nmax_ = rhs.nmax_;
   binom_ = rhs.binom_;
}

//-------------------------------------------------------------------
//
//     Assignment operator for deep copy.
//

BinomCoeffTable& BinomCoeffTable::operator=(const BinomCoeffTable& rhs)
{
   if (this != &rhs) {
      nmax_ = rhs.nmax_;
      binom_ = rhs.binom_;
   }

   return *this;
}

//-------------------------------------------------------------------

BinomCoeffTable::~BinomCoeffTable()
{
   binom_.clear();
}

//-------------------------------------------------------------------

void BinomCoeffTable::init(DT::Int32 nmax_x)
{
   // Do some idiot-proofing.
   DT::Int32 nmaxPrev = nmax_;
   nmax_ = nmax_x;
   if (nmax_ <= nmaxPrev) {
      nmax_ = nmaxPrev;
      return;
   }

   // Add needed rows to table.
   for (DT::Int32 n=nmaxPrev+1; n<=nmax_; ++n) {
      DT::VecInt32 row;
      row.assign(n+1, 1);  // Now, only middle values need to be changed.

      for (DT::Int32 k=1; k<n; ++k)
         row[k] = binom_[n-1][k] + binom_[n-1][k-1];

      binom_.push_back(row);
   }
}

//-------------------------------------------------------------------

DT::Int32 BinomCoeffTable::getBinom(DT::Int32 n, DT::Int32 k)
{
   if (n >= 0) {
      if ((k >= 0) && (k <= n))
         return binom_[n][k];
      else
         return (DT::Int32) 0;
   }

// If we have reached here, n is negative.

   if (k >= 0) {
      DT::Int32 sign = 1 - 2*(k%2);
      return sign*binom_[-n+k-1][k];
   }
   else if (k <= n) {
      DT::Int32 sign = 1 - 2*((n-k)%2);
      return sign*binom_[-k-1][n-k];
   }

   return (DT::Int32) 0;
}

//-------------------------------------------------------------------

} // namespace Math_Common::Combin

