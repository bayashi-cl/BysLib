#pragma once
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "../utility/change.hpp"
#include "edge.hpp"

namespace bys {
struct BellmanFord {
    const EdgeList& graph;
    int n_node;
    vector<ll> cost;
    bool negative_cycle;

    BellmanFord(const EdgeList& graph, int n_node, int start) : graph(graph), n_node(n_node), cost(n_node, LINF) {
        negative_cycle = search(start);
    }

    bool search(int start) {
        cost[start] = 0;
        for (int i = 0; i < n_node - 1; ++i) relaxing();
        return relaxing();
    }

   private:
    bool relaxing() {
        bool res = false;
        for (auto&& e : graph) {
            if (cost[e.from] == LINF) continue;
            if (chmin(cost[e.to], cost[e.from] + e.cost)) res = true;
        }
        return res;
    }
};
}  // namespace bys
