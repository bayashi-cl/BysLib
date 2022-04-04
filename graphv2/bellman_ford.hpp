#pragma once
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "../utility/change.hpp"
#include "edge.hpp"
#include "result.hpp"
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
SSSPResult bellman_ford(const std::vector<Edge>& elist, int n_node, int source) {
    SSSPResult res(n_node, source);
    int n = elist.size();
    res.cost[source] = 0;
    for (int i = 0; i < n_node - 1; ++i) {
        for (auto&& e : elist) {
            if (res.cost[e.src] >= LINF) continue;
            chmin(res.cost[e.dest], res.cost[e.src] + e.weight);
        }
    }
    std::vector<bool> neg_cycle(n);
    for (int i = 0; i < n; ++i) {
        for (auto&& e : elist) {
            if (res.cost[e.src] >= LINF) continue;
            if (chmin(res.cost[e.dest], res.cost[e.src] + e.weight) || neg_cycle[e.src]) neg_cycle[e.dest] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (neg_cycle[i]) res.cost[i] = -LINF;
    }
    return res;
}
}  // namespace bys
