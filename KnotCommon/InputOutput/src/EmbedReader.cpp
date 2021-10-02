//----------------------------------------------------------------
//
//     Read in embedding data for Conway polyhedra (implementation).
//
//     Bob Tuzun
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

#include "KnotCommon/InputOutput/EmbedReader.h"

namespace DT = Tuzun_Util::Datatypes;

namespace Knot_Common::Input_Output {

//----------------------------------------------------------------

EmbedReader::EmbedReader()
{
}

//----------------------------------------------------------------

EmbedReader::~EmbedReader()
{
   if (eFile_.is_open())
      eFile_.close();
}

//----------------------------------------------------------------

void EmbedReader::init(DT::Int32 numVertices_x,
                       const DT::String& dirPathPolyhData_x)
{
   numVertices_ = numVertices_x;
   dirPathPolyhData_ = dirPathPolyhData_x;
   prefix_ = "NonCSEmbed";
   openFile();
}

//----------------------------------------------------------------

void EmbedReader::setPrefix(const DT::String& prefix_x)
{
   prefix_ = prefix_x;
   openFile();
}

//----------------------------------------------------------------

void EmbedReader::openFile()
{
   std::stringstream embedFileName;
   embedFileName << dirPathPolyhData_ << prefix_ << "."
                 << std::setfill('0') << std::setw(2) << numVertices_;

   if (eFile_.is_open())
      eFile_.close();

   eFile_.open(embedFileName.str().c_str(), std::ios::in);
   bool isOpen = eFile_.is_open();
   if (! isOpen) {
      std::cout << "File " << embedFileName.str()
           << " not open in EmbedReader::openFile" << std::endl;
      abort();
   }

   goToBeginning();
}

//----------------------------------------------------------------

void EmbedReader::goToBeginning()
{
   DT::Int32 num_Bytes = 0;
   eFile_.seekg(num_Bytes, std::ios::beg);

   curPolyhNum_ = 0;
}

//----------------------------------------------------------------

std::vector<DT::VecInt32> EmbedReader::readNext()
{
   std::vector<DT::VecInt32> e;
   DT::VecInt32 b(4);
   DT::Int32 n;

   eFile_ >> n;
   for (DT::Int32 i=0; i<n; ++i) {
      eFile_ >> b[0] >> b[1] >> b[2] >> b[3];
      e.push_back(b);
   }

   curPolyhNum_++;

   return std::vector<DT::VecInt32>(e);
}

//----------------------------------------------------------------

std::vector<DT::VecInt32> EmbedReader::readPolyh(DT::Int32 polyhNum)
{
   if (curPolyhNum_ > polyhNum)
      goToBeginning();

   std::vector<DT::VecInt32> embedding;
   for (DT::Int32 i=curPolyhNum_; i<=polyhNum; ++i)
      embedding = readNext();

   return std::vector<DT::VecInt32>(embedding);
}

//----------------------------------------------------------------

} // namespace Knot_Common::Input_Output

