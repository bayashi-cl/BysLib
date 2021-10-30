#pragma once
#include "byslib/graph/edge.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct WarshallFloyd {
    int n_node;
    vector<vector<ll>> cost;
    vector<int> prev;

    WarshallFloyd(const Adj& graph)
        : n_node(graph.size()), cost(n_node, vector<ll>(n_node, LINF)) {
        for (int i = 0; i < n_node; ++i) {
            for (auto e : graph[i]) cost[i][e.to] = e.cost;
        }
        for (int i = 0; i < n_node; ++i) cost[i][i] = 0;
        search();
    }

    void search() {
        for (int k = 0; k < n_node; k++) {
            for (int i = 0; i < n_node; i++) {
                for (int j = 0; j < n_node; j++) {
                    chmin(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
};
}  // namespace bys
