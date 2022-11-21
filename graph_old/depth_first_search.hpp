#pragma once
#include "edge.hpp"
namespace bys {
std::vector<int> pre_order(const AdjacencyList<>& graph, int source = -1);
// std::vector<int> in_order(const AdjacencyList& graph, int source);
// std::vector<int> post_order(const AdjacencyList& graph, int source);
// std::vector<int> euler_tour(const AdjacencyList& graph, int source);
}  // namespace bys
