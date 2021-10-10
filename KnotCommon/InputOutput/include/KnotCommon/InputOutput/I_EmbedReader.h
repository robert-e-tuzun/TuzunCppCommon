//----------------------------------------------------------------------
//
//     Read in embedding data for Conway polyhedra (interface).
//
//     Bob Tuzun
//

#pragma once

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Knot_Common::Input_Output {

class I_EmbedReader
{
   public:
      virtual ~I_EmbedReader() {};

      virtual void init(DT::Int32 numVertices_x,
                const DT::String& dirPathPolyhData) = 0;
      virtual void setPrefix(const DT::String& prefix_x) = 0;
      virtual std::vector<DT::VecInt32> readNext() = 0;
      virtual std::vector<DT::VecInt32> readPolyh(DT::Int32 polyhNum) = 0;

   private:
};

} // namespace Knot_Common::Input_Output

