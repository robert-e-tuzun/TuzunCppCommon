//--------------------------------------------------------------------
//
//     Test Lexicographic class.
//
//     Bob Tuzun
//
//--------------------------------------------------------------------

#define BOOST_TEST_MODULE testLexicographic
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <any>

#include "MathCommon/Combin/Lexicographic.h"

namespace DT = Util_Common::Datatypes;

//--------------------------------------------------------------------

std::vector<DT::VecInt32>
getLexicos(const DT::VecInt32& minDigits, const DT::VecInt32& maxDigits)
{
   Math_Common::Combin::Lexicographic lex;
   lex.init(minDigits, maxDigits);

   std::vector<DT::VecInt32> lexicos;

   bool done = false;
   do {
      lex.findNext();
      DT::VecInt32 lexico = lex.getCurDigits();
      lexicos.push_back(lexico);
      done = lex.atLastLex();
   }
   while (! done);

   return lexicos;
}

//--------------------------------------------------------------------

bool lexicosAreValid(const std::vector<DT::VecInt32>& lexicos,
            const DT::VecInt32& minDigits, const DT::VecInt32& maxDigits)
{
   DT::Int32 numDigits = minDigits.size();
   for (const auto& lexico : lexicos)
      for (DT::Int32 i=0; i<numDigits; ++i)
         if ((lexico[i] < minDigits[i]) || (lexico[i] > maxDigits[i]))
            return false;

   return true;
}

//--------------------------------------------------------------------

bool isSortedAndNoDuplicates(std::vector<DT::VecInt32>& lexicos)
{
   bool isSorted = std::is_sorted(lexicos.begin(), lexicos.end());
   if (! isSorted)
      return false;

   DT::UInt32 sizeBefore = lexicos.size();
   lexicos.erase(unique(lexicos.begin(), lexicos.end()), lexicos.end());
   DT::UInt32 sizeAfter = lexicos.size();

   return (sizeBefore == sizeAfter);
}

//--------------------------------------------------------------------

bool hasCorrectNumberOfLexicos(const std::vector<DT::VecInt32>& lexicos,
            const DT::VecInt32& minDigits, const DT::VecInt32& maxDigits)
{
   DT::Int32 numDigits = minDigits.size();
   DT::UInt32 size = 1;
   for (DT::Int32 i=0; i<numDigits; ++i)
      size *= maxDigits[i] - minDigits[i] + 1;

   return (lexicos.size() == size);
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE( lexTests )

BOOST_AUTO_TEST_CASE( checkLexicos )
{
   std::vector<DT::VecInt32> allMinDigits({{ 0, 0, 0, 0, 0 }, {1, 1, 1},
                                           { 1, 2, 3, 4 }});
   std::vector<DT::VecInt32> allMaxDigits({{ 9, 9, 9, 9, 9 }, {1, 3, 4},
                                           { 8, 7, 6, 5 }});

   DT::Int32 numTests = allMinDigits.size();
   for (DT::Int32 i=0; i<numTests; ++i) {
      DT::VecInt32 minDigits = allMinDigits[i];
      DT::VecInt32 maxDigits = allMaxDigits[i];
      std::vector<DT::VecInt32> lexicos = getLexicos(minDigits, maxDigits);

      BOOST_TEST( lexicosAreValid(lexicos, minDigits, maxDigits) );
      BOOST_TEST( isSortedAndNoDuplicates(lexicos) );
      BOOST_TEST( hasCorrectNumberOfLexicos(lexicos, minDigits, maxDigits) );
   }
}

//--------------------------------------------------------------------

BOOST_AUTO_TEST_CASE( checkIncrementDigit )
{
   DT::VecInt32 minDigits({ 0, 1, 2, 3, 4 });
   DT::VecInt32 maxDigits({ 9, 1, 7, 6, 5 });
   Math_Common::Combin::Lexicographic lex;
   lex.init(minDigits, maxDigits);

   DT::VecInt32 digits({ 5, 1, 7, 5, 5});
   lex.setDigitsTo(digits);

   lex.incrementDigit(3);
   BOOST_TEST( (lex.getCurDigits() == DT::VecInt32({5, 1, 7, 6, 4})) );

   lex.incrementDigit(2);
   BOOST_TEST( (lex.getCurDigits() == DT::VecInt32({6, 1, 2, 3, 4})) );
}

BOOST_AUTO_TEST_SUITE_END()

