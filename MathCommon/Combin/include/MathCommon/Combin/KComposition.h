//------------------------------------------------------------------
//
//     Compute members of a sequence of k-compositions of n.
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Math_Common::Combin {

class KComposition
{
   public:
      KComposition();
      KComposition(const KComposition& rhs);
      KComposition& operator=(const KComposition& rhs);
      ~KComposition();

      void init(DT::Int32 k_x, DT::Int32 n_x);
      void findNextComposition();
      DT::VecInt32 getComposition();
      bool atLastComposition();

//     The next two functions allow one to re-start a calculation somewhere
//     not at the beginning of a sequence of compositions.
      DT::VecInt32 getState();
      void setState(const DT::VecInt32& state);

   private:
      DT::Int32 k_;
      DT::Int32 n_;

      bool isFirstEntry_;
      bool isLastEntry_;

      DT::VecInt32 array_;
};

} // namespace Math_Common::Combin

