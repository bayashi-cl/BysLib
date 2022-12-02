#pragma once
#include "../core/constant.hpp"
#include "../core/int_alias.hpp"
#include "../extension/change.hpp"
#include "graph.hpp"
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
 * @return inf -> 到達不可, -inf -> 負閉路
 */
template <class E> std::vector<typename E::weight_type> bellman_ford(EdgesCOO<E> const& edges, typename E::vertex_type source) {
    using W = typename E::weight_type;
    std::vector cost(edges.size(), get_inf<W>());
    i32 n = edges.size();
    cost[source] = 0;
    for (i32 i = 0; i < n - 1; ++i) {
        for (auto&& e : edges) {
            if (is_inf(cost[e.src])) continue;
            chmin(cost[e.dest], cost[e.src] + e.weight);
        }
    }
    std::vector<bool> neg_cycle(n);
    for (i32 i = 0; i < n; ++i) {
        for (auto&& e : edges) {
            if (is_inf(cost[e.src])) continue;
            if (chmin(cost[e.dest], cost[e.src] + e.weight) || neg_cycle[e.src]) neg_cycle[e.dest] = true;
        }
    }
    for (i32 i = 0; i < n; ++i) {
        if (neg_cycle[i]) cost[i] = -get_inf<W>();
    }
    return cost;
}
}  // namespace bys
