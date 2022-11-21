#pragma once
#include "../utility/change.hpp"
#include "edge.hpp"
/**
 * @file bellman_ford.hpp
 * @brief Bellman Ford
 */
namespace bys {
/**
 * @brief ベルマンフォード法
 *
 * O(VE)
 *
 * @param elist 辺リスト
 * @param n_node 頂点数
 * @param source 始点
 * @return SSSPResult LINF -> 到達不可, -LINF -> 負閉路
 */
std::vector<ll> bellman_ford(const COOMatrix<Edge>& edges, int source) {
    std::vector<ll> cost(edges.size(), LINF);
    int n = edges.size();
    int m = edges.nonzero();
    cost[source] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto&& [src, id, e] : edges) {
            if (cost[src] >= LINF) continue;
            chmin(cost[e.dest], cost[src] + e.weight);
        }
    }
    std::vector<bool> neg_cycle(n);
    for (int i = 0; i < n; ++i) {
        for (auto&& [src, id, e] : edges) {
            if (cost[src] >= LINF) continue;
            if (chmin(cost[e.dest], cost[src] + e.weight) || neg_cycle[src]) neg_cycle[e.dest] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (neg_cycle[i]) cost[i] = -LINF;
    }
    return cost;
}
}  // namespace bys
