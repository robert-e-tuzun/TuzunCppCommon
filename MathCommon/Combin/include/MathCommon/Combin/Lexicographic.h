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
      Lexicographic();
      Lexicographic(const Lexicographic& rhs);
      Lexicographic& operator=(const Lexicographic& rhs);
      ~Lexicographic();

      void init(const DT::VecInt32& minDigits,
                const DT::VecInt32& maxDigits);
      void init(const DT::VecInt32& maxDigits);
      void goToBeginning();
      void findNext();
      void incrementDigit(DT::Int32 digit);
      void setDigitsTo(const DT::VecInt32& digits_x);
      bool atLastLex() const;
      DT::VecInt32 getCurDigits() const;

      std::string output() const;

   private:
      bool atBeginning_;

      DT::Int32 numDigits_;

      DT::VecInt32 minDigits_;
      DT::VecInt32 maxDigits_;
      DT::VecInt32 digits_;
};

} // namespace Math_Common::Combin

