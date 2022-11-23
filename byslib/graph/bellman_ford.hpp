#pragma once
#include "../core/const.hpp"
#include "../utility/change.hpp"
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
template <class E>
std::vector<typename E::weight_type> bellman_ford(EdgeList<E> const& edges,
                                                  typename E::vertex_type source) {
    using W = typename E::weight_type;
    std::vector cost(edges.size(), get_inf<W>());
    int n = edges.size();
    cost[source] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto&& [src, id, e] : edges) {
            if (is_inf(cost[src])) continue;
            chmin(cost[e.dest], cost[src] + e.weight);
        }
    }
    std::vector<bool> neg_cycle(n);
    for (int i = 0; i < n; ++i) {
        for (auto&& [src, id, e] : edges) {
            if (is_inf(cost[src])) continue;
            if (chmin(cost[e.dest], cost[src] + e.weight) || neg_cycle[src])
                neg_cycle[e.dest] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (neg_cycle[i]) cost[i] = -get_inf<W>();
    }
    return cost;
}
}  // namespace bys
