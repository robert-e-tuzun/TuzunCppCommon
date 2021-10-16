//------------------------------------------------------------------
//
//     Compute members of a sequence of k-compositions of n (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "MathCommon/Combin/KComposition.h"

namespace Math_Common::Combin {

//-------------------------------------------------------------------

KComposition::KComposition()
{
}

//-------------------------------------------------------------------
//
//     Copy constructor for deep copy.
//

KComposition::KComposition(const KComposition& rhs)
{
   k_ = rhs.k_;
   n_ = rhs.n_;

   isFirstEntry_ = rhs.isFirstEntry_;
   isLastEntry_ = rhs.isLastEntry_;

   array_ = rhs.array_;
}

//-------------------------------------------------------------------
//
//     Assignment operator for deep copy.
//

KComposition& KComposition::operator=(const KComposition& rhs)
{
   if (this != &rhs) {
      k_ = rhs.k_;
      n_ = rhs.n_;

      isFirstEntry_ = rhs.isFirstEntry_;
      isLastEntry_ = rhs.isLastEntry_;

      array_ = rhs.array_;
   }

   return *this;
}

//-------------------------------------------------------------------

KComposition::~KComposition()
{
   array_.clear();
}

//-------------------------------------------------------------------

void KComposition::init(DT::Int32 k_x, DT::Int32 n_x)
{
   k_ = k_x;
   n_ = n_x;

   array_.clear();
   array_.assign(k_, 0);

   isFirstEntry_ = true;
}

//-------------------------------------------------------------------

void KComposition::findNextComposition()
{
   if (isFirstEntry_) {
      array_[k_-1] = n_;
      for (DT::Int32 i=0; i<(k_-1); ++i)
         array_[i] = 0;

      isFirstEntry_ = false;
   }
   else {
      DT::Int32 pos = k_ - 1;   // Find position of last non-zero element.
      while ((pos > 0) && (array_[pos] == 0))
         pos--;

      if (pos > 0) {
         array_[pos-1]++;
         for (DT::Int32 i=pos; i<k_-1; ++i)  // Fill out elements pos -
            array_[i] = 0;                   // k_-2 with zeros.

         DT::Int32 sum = 0;              // Find sum of first k_-1 elements.
         for (DT::Int32 i=0; i<pos; ++i)
            sum += array_[i];

         array_[k_-1] = n_ - sum;   // Set last element so that total sum is n.
      }
   }

   isLastEntry_ = (array_[0] == n_);
}

//-------------------------------------------------------------------

DT::VecInt32 KComposition::getComposition()
{
   return DT::VecInt32(array_);
}

//-------------------------------------------------------------------

bool KComposition::atLastComposition()
{
   return isLastEntry_;
}

//-------------------------------------------------------------------

DT::VecInt32 KComposition::getState()
{
   DT::VecInt32 state = array_;

   return DT::VecInt32(state);
}

//-------------------------------------------------------------------

void KComposition::setState(const DT::VecInt32& state)
{
   array_ = state;

   k_ = state.size();

   n_ = 0;
   for (DT::Int32 entry : array_)
      n_ += entry;

   isFirstEntry_ = false;
}

//-------------------------------------------------------------------

} // namespace Math_Common::Combin

