//----------------------------------------------------------------
//
//     Read in number of Conway polyhedra for a given number of vertices.
//
//     Bob Tuzun
//

#pragma once

#include "TuzunUtil/CppDatatypes.h"

namespace DT = Tuzun_Util::Datatypes;

namespace Knot_Common::Input_Output {

DT::Int32 getNumPolyh(const DT::String& dirPathPolyhData,
                const DT::String& prefix, DT::Int32 numVertices);

}

