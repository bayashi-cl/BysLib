#pragma once
#include "edge.hpp"
#include "../core/stdlib.hpp"
#include "../core/const.hpp"
#include "../utility/change.hpp"

namespace bys {
struct WarshallFloyd {
    int n_node;
    vector<vector<ll>> cost;
    vector<vector<int>> prev;

    WarshallFloyd(const EdgeList& graph, int n_node)
        : n_node(n_node), cost(n_node, vector(n_node, LINF)), prev(n_node, vector(n_node, -1)) {
        for (auto&& e : graph) cost[e.from][e.to] = e.cost;
        for (int i = 0; i < n_node; ++i) cost[i][i] = 0;
        for (int i = 0; i < n_node; ++i) {
            for (int j = 0; j < n_node; ++j) {
                prev[i][j] = i;
            }
        }
        search();
    }

    void search() {
        for (int k = 0; k < n_node; k++) {
            for (int i = 0; i < n_node; i++) {
                for (int j = 0; j < n_node; j++) {
                    if (chmin(cost[i][j], cost[i][k] + cost[k][j])) {
                        prev[i][j] = prev[k][j];
                    }
                }
            }
        }
    }
    vector<int> path(int from, int to) {
        vector<int> res;
        for (int now = to; now != from; now = prev[from][now]) {
            res.push_back(now);
        }
        res.push_back(from);
        std::reverse(res.begin(), res.end());
        return res;
    }
};
}  // namespace bys
