#pragma once
#include "../core/stdlib.hpp"

namespace bys {
struct Edge {
    int from, to;
    ll cost;

    //! @brief 重みなし単頂点
    Edge(int to) : from(-1), to(to), cost(1) {}
    //! @brief 重み付き単頂点
    Edge(int to, ll cost) : from(-1), to(to), cost(cost) {}
    //! @brief 重み付き両頂点
    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
    bool operator<(const Edge& rh) const { return cost < rh.cost; }
    friend std::ostream& operator<<(std::ostream& os, const Edge& e) { return os << e.from << " - " << e.to << ": " << e.cost; }
};
using Adj = vector<vector<Edge>>;
using EdgeList = vector<Edge>;
}  // namespace bys
