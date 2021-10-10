//----------------------------------------------------------------------
//
//     Conway polyhedron reader.
//
//     Bob Tuzun
//

#pragma once

#include "KnotCommon/InputOutput/EmbedReader.h"
#include "KnotCommon/InputOutput/I_PolyhedronReader.h"

namespace DT = Util_Common::Datatypes;

namespace Knot_Common::Input_Output {

class PolyhedronReader : public I_PolyhedronReader
{
   public:
      PolyhedronReader();
      ~PolyhedronReader();

      virtual void setPrefix(const DT::String& prefix);
      virtual void prepareForUse(DT::Int32 numVertices,
               const DT::String& dirPathPolyhData);
      virtual DT::Int32 getNumPolyhedra();
      virtual std::vector<DT::VecInt32> getConTable(DT::Int32 polyhNum);

   private:
      void openPolyhedronDataFile();

      DT::Int32 numPolyh_;
      DT::Int32 numVertices_;

      DT::String dirPathPolyhData_;

      std::shared_ptr<Knot_Common::Input_Output::EmbedReader> conTableReader_;
};

} // namespace Knot_Common::Input_Output

