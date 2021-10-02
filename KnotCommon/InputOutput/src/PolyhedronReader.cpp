//----------------------------------------------------------------
//
//     Conway polyhedron reader (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "KnotCommon/InputOutput/EmbedReader.h"
#include "KnotCommon/InputOutput/getNumPolyh.h"

#include "KnotCommon/InputOutput/PolyhedronReader.h"

namespace DT = Tuzun_Util::Datatypes;

namespace Knot_Common::Input_Output {

//----------------------------------------------------------------

PolyhedronReader::PolyhedronReader()
{
}

//----------------------------------------------------------------

PolyhedronReader::~PolyhedronReader()
{
}

//----------------------------------------------------------------

void PolyhedronReader::setPrefix(const DT::String& prefix)
{
   conTableReader_->setPrefix(prefix);
}

//----------------------------------------------------------------

void PolyhedronReader::prepareForUse(DT::Int32 numVertices,
        const DT::String& dirPathPolyhData)
{
   numVertices_ = numVertices;
   dirPathPolyhData_ = dirPathPolyhData;
   openPolyhedronDataFile();
}

//----------------------------------------------------------------

void PolyhedronReader::openPolyhedronDataFile()
{
   conTableReader_ = std::make_shared<EmbedReader>();
   conTableReader_->init(numVertices_, dirPathPolyhData_);
}

//----------------------------------------------------------------

DT::Int32 PolyhedronReader::getNumPolyhedra()
{
   DT::String prefix = "NumNonCSPolyh";
   numPolyh_ = getNumPolyh(dirPathPolyhData_, prefix, numVertices_);
   return numPolyh_;
}

//----------------------------------------------------------------

std::vector<DT::VecInt32> PolyhedronReader::getConTable(DT::Int32 polyhNum)
{
   return conTableReader_->readPolyh(polyhNum);
}

//----------------------------------------------------------------

} // namespace Knot_Common::Input_Output

