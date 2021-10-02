//----------------------------------------------------------------------
//
//     Conway polyhedron reader (interface class).
//
//     Bob Tuzun
//

#pragma once

#include "TuzunUtil/CppDatatypes.h"

namespace DT = Tuzun_Util::Datatypes;

namespace Knot_Common::Input_Output {

class I_PolyhedronReader
{
   public:
      virtual ~I_PolyhedronReader() {};

      virtual void setPrefix(const DT::String& prefix) = 0;
      virtual void prepareForUse(DT::Int32 NumVertices,
               const DT::String& dirPathPolyhData) = 0;
      virtual DT::Int32 getNumPolyhedra() = 0;
      virtual std::vector<DT::VecInt32> getConTable(DT::Int32 polyhNum) = 0;

   private:
};

} // namespace Knot_Common::Input_Output

