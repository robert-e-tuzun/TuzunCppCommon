//----------------------------------------------------------------------
//
//     Read in embedding data for Conway polyhedra.
//
//     Bob Tuzun
//

#pragma once

#include <fstream>

#include "KnotCommon/InputOutput/I_EmbedReader.h"

namespace DT = Tuzun_Util::Datatypes;

namespace Knot_Common::Input_Output {

class EmbedReader : public I_EmbedReader
{
   public:
      EmbedReader();
      ~EmbedReader();

      virtual void init(DT::Int32 numVertices_x,
                const DT::String& dirPathPolyhData);
      virtual void setPrefix(const DT::String& prefix_x);
      virtual std::vector<DT::VecInt32> readNext();
      virtual std::vector<DT::VecInt32> readPolyh(DT::Int32 polyhNum);

   private:
      void openFile();
      void goToBeginning();

      DT::Int32 curPolyhNum_;
      DT::Int32 numVertices_;

      DT::String dirPathPolyhData_;
      DT::String prefix_;

      std::fstream eFile_;
};

} // namespace Knot_Common::Input_Output

