#pragma once
#include "core/stdlib.hpp"
namespace bys {
struct Edge {
    int dest;
};
struct WEdge : Edge {
    int cost;
};
struct BEdge {};
struct BWEdge {};

}  // namespace bys
