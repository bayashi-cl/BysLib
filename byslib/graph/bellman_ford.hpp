#pragma once
// #include "byslib/graph/edge.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct BellmanFord {
    using Edge = std::pair<ll, std::pair<int, int>>;
    int n_node;
    vector<Edge> graph;
    vector<ll> cost;

    BellmanFord(vector<Edge> graph, int n_node) : graph(graph), n_node(n_node) {
        cost.resize(n_node, INF);
    }

    bool search(int start) {
        for (int i = 0; i < n_node - 1; i++) relaxing();
        return !relaxing();
    }

   private:
    bool relaxing() {
        bool res = false;
        for (auto [dist, node] : graph) {
            if (cost[node.first] == LINF) continue;
            if (chmin(cost[node.second], cost[node.first] + dist)) res = true;
        }
        return res;
    }
};
}  // namespace bys
