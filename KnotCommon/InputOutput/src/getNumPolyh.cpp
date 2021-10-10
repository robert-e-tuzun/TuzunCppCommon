//----------------------------------------------------------------
//
//     Read in number of Conway polyhedra for a given number of vertices
//     (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "KnotCommon/InputOutput/getNumPolyh.h"

namespace DT = Util_Common::Datatypes;

namespace Knot_Common::Input_Output {

DT::Int32 getNumPolyh(const DT::String& dirPathPolyhData,
                      const DT::String& prefix, DT::Int32 numVertices)
{
   std::stringstream s;
   s << dirPathPolyhData << prefix << "."
     << std::setfill('0') << std::setw(2) << numVertices;

   std::fstream fileNumPolyh;
   fileNumPolyh.open(s.str().c_str(), std::ios::in);
   bool opened = fileNumPolyh.is_open();
   if (! opened) {
      std::cout << "File " << s.str() << " not opened in GetNumPolyh."
                << std::endl;
      abort();
   }

   DT::Int32 numPolyh;
   fileNumPolyh >> numPolyh;
   fileNumPolyh.close();

   return numPolyh;
}

} // namespace Knot_Common::Input_Output

