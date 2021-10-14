//------------------------------------------------------------------
//
//     Some convenient Boost definitions.
//
//     Bob Tuzun
//

#pragma once

#include <string>
#include <any>
#include <map>
#include <memory>
#include "boost/config.hpp"
#include "boost/graph_adjacency_list.hpp"

#include "UtilCommon/CppDatatypes.h"

namespace DT = Util_Common::Datatypes;

namespace Math_Common::Graph_Theory {

   using DirectedGraph = boost::adjacency_list<vecS, vecS, directedS>;
   using BidirectionalGraph = boost::adjacency_list<vecS, vecS, bidirectionalS>;
   using UndirectedGraph = boost::adjacency_list<vecS, vecS, undirectedS>;

} // namespace Math_Common::Graph_Theory

