//-------------------------------------------------------
//
//     Class of speedometrically traversed vector (implementation).
//     Note: no error checking for bad input.
//
//     Bob Tuzun
//

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

#include "MathCommon/Combin/Lexicographic.h"

namespace Math_Common::Combin {

//-------------------------------------------------------

Lexicographic::Lexicographic()
{
}

//-------------------------------------------------------
//
//     Copy constructor for deep copy.
//

Lexicographic::Lexicographic(const Lexicographic& rhs)
{
   minDigits_ = rhs.minDigits_;
   maxDigits_ = rhs.maxDigits_;
   digits_ = rhs.digits_;

   numDigits_ = rhs.numDigits_;

   atBeginning_ = rhs.atBeginning_;
}

//-------------------------------------------------------

Lexicographic& Lexicographic::operator=(const Lexicographic& rhs)
{
   if (this != &rhs) {
      minDigits_ = rhs.minDigits_;
      maxDigits_ = rhs.maxDigits_;
      digits_ = rhs.digits_;

      numDigits_ = rhs.numDigits_;

      atBeginning_ = rhs.atBeginning_;
   }

   return *this;
}

//-------------------------------------------------------

Lexicographic::~Lexicographic()
{
   minDigits_.clear();
   maxDigits_.clear();
   digits_.clear();
}

//-------------------------------------------------------

void Lexicographic::init(const DT::VecInt32& minDigits,
                         const DT::VecInt32& maxDigits)
{
   minDigits_ = minDigits;
   maxDigits_ = maxDigits;
   numDigits_ = maxDigits_.size();

   goToBeginning();
}

//-------------------------------------------------------

void Lexicographic::init(const DT::VecInt32& maxDigits)
{
   maxDigits_ = maxDigits;
   numDigits_ = maxDigits_.size();
   minDigits_.assign(numDigits_, 0);

   goToBeginning();
}

//-------------------------------------------------------

void Lexicographic::goToBeginning()
{
   atBeginning_ = true;
}

//-------------------------------------------------------

void Lexicographic::findNext()
{
   if (atBeginning_) {
      digits_ = minDigits_;
      atBeginning_ = false;
   }
   else {
      digits_[numDigits_-1]++;

      for (DT::Int32 i=numDigits_-1; i>=1; --i)
         if (digits_[i] > maxDigits_[i]) {
            digits_[i] = minDigits_[i];
            digits_[i-1]++;
         }
   }
}

//-------------------------------------------------------

void Lexicographic::incrementDigit(DT::Int32 digit)
{
//     Increment desired digit.  Working backwards in digit number, if
//     the digit exeeds its maximum value, set the digit to its minimum
//     value and increment previous digit.

   digits_[digit]++;
   for (DT::Int32 i=digit; i>=1; --i)
      if (digits_[i] > maxDigits_[i]) {
         digits_[i] = minDigits_[i];
         digits_[i-1]++;
      }

//     Set later digits equal to their minDigits_.

   for (DT::Int32 i=(digit+1); i<numDigits_; ++i)
      digits_[i] = minDigits_[i];
}

//-------------------------------------------------------

void Lexicographic::setDigitsTo(const DT::VecInt32& digits_x)
{
   digits_ = digits_x;
   atBeginning_ = false;
}

//-------------------------------------------------------

bool Lexicographic::atLastLex() const
{
   return (digits_ == maxDigits_);
}

//-------------------------------------------------------

DT::VecInt32 Lexicographic::getCurDigits() const
{
   return DT::VecInt32(digits_);
}

//-------------------------------------------------------

std::string Lexicographic::output() const
{
   std::stringstream s;
   for (DT::Int32 i=0; i<numDigits_; ++i)
      s << " " << digits_[i];

   return s.str();
}

//-------------------------------------------------------

} // namespace Math_Common::Combin

