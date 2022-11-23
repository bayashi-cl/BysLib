#pragma once
/**
 * @file warshall_floyd.hpp
 * @brief Warshall Floyd
 */
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "../utility/change.hpp"
#include "edge.hpp"

namespace bys {
/**
 * @brief Warshall Floyd
 *
 * O(V^3)
 *
 * @param graph 辺リスト
 */
std::vector<std::vector<ll>> warshall_floyd(const COOMatrix<Edge>& graph) {
    int n = graph.size();
    vector cost(n, vector<ll>(n, LINF));
    for (auto&& [src, id, e] : graph) chmin(cost[src][e.dest], e.weight);
    for (int i = 0; i < n; ++i) cost[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][k] == LINF or cost[k][j] == LINF) continue;
                chmin(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    return cost;
}
}  // namespace bys
