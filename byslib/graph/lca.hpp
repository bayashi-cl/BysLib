#pragma once
#include "byslib/graph/depth_first.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct LowestCommonAncestor {
    const Adj& graph;
    const int n_node;
    DepthFirstSearch dfs;
    vector<vector<int>> parent;
    int log_size = 1;

    LowestCommonAncestor(const Adj& graph, int root = 0)
        : graph(graph), n_node(graph.size()), dfs(graph, root) {
        while ((1 << log_size) < n_node) ++log_size;
        parent.assign(log_size, vector<int>(n_node, -1));
        parent[0] = dfs.prev;
        for (int i = 0; i < log_size - 1; i++) {
            for (int j = 0; j < n_node; j++) {
                if (parent[i][j] < 0) {
                    parent[i + 1][j] = -1;
                } else {
                    parent[i + 1][j] = parent[i][parent[i][j]];
                }
            }
        }
    }
    int prev(int n, int x) const {
        // nのx個上
        for (int k = 0; k < log_size; k++) {
            if (x >> k & 1) n = parent[k][n];
        }
        return n;
    }
    int lca(int a, int b) const {
        if (dfs.cost[a] < dfs.cost[b]) std::swap(a, b);
        a = prev(a, dfs.cost[a] - dfs.cost[b]);
        if (a == b) return a;
        for (int k = log_size - 1; k >= 0; k--) {
            if (parent[k][a] != parent[k][b]) {
                a = parent[k][a];
                b = parent[k][b];
            }
        }
        return parent[0][a];
    }
};
}  // namespace bys
