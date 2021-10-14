//---------------------------------------------------------------
//
//     Class of speedometrically traversed vector.
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Math_Common::Combin {

class Lexicographic {
   public:
      Lexicographic(const DT::VecInt32& minDigits_x,
                   const DT::VecInt32& maxDigits_x);
      Lexicographic(const DT::VecInt32& maxDigits_x);
      Lexicographic();
      Lexicographic(const Lexicographic& rhs);
      Lexicographic& operator=(const Lexicographic& rhs);
      ~Lexicographic();

      void goToBeginning();
      void findNext();
      void incrementDigit(int Digit);
      void setDigitsTo(const DT::VecInt32& digits_x);
      bool atLast() const;
      DT::VecInt32 getCurDigits() const;

      std::string output() const;

   private:
      bool atBeginning_;

      int numDigits_;

      DT::VecInt32 minDigits_;
      DT::VecInt32 maxDigits_;
      DT::VecInt32 digits_;
};

} // namespace Math_Common::Combin

