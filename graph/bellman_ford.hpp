#pragma once
#include "edge.hpp"
#include "byslib/core/stdlib.hpp"
#include "byslib/core/const.hpp"
#include "byslib/utility/change.hpp"

namespace bys {
struct BellmanFord {
    // using Edge = std::pair<ll, std::pair<int, int>>;
    // vector<Edge> graph;
    const EdgeList& graph;
    int n_node;
    vector<ll> cost;

    BellmanFord(vector<Edge> graph, int n_node, int start) : graph(graph), n_node(n_node), cost(n_node, INF) { search(start); }

    bool search(int start) {
        for (int i = 0; i < n_node - 1; ++i) relaxing();
        return !relaxing();
    }

   private:
    bool relaxing() {
        bool res = false;
        // for (auto [dist, node] : graph) {
        //     if (cost[node.first] == LINF) continue;
        //     if (chmin(cost[node.second], cost[node.first] + dist)) res = true;
        // }
        for (auto&& e : graph) {
            if (cost[e.from] == LINF) continue;
            if (chmin(cost[e.to], cost[e.from] + e.cost)) res = true;
        }
        return res;
    }
};
}  // namespace bys
