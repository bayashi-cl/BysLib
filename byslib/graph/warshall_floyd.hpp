#pragma once
/**
 * @file warshall_floyd.hpp
 * @brief Warshall Floyd
 */
#include "../core/constant.hpp"
#include "../core/int_alias.hpp"
#include "../extension/change.hpp"
#include "graph.hpp"

namespace bys {
/**
 * @brief Warshall Floyd
 *
 * O(V^3)
 *
 * @param graph 辺リスト
 */

template <class E> std::vector<std::vector<typename E::weight_type>> warshall_floyd(EdgesCOO<E> const& graph) {
    using W = typename E::weight_type;
    i32 n = graph.size();
    std::vector cost(n, std::vector(n, get_inf<W>()));
    for (auto&& e : graph) chmin(cost[e.src][e.dest], e.weight);
    for (i32 i = 0; i < n; ++i) cost[i][i] = 0;
    for (i32 k = 0; k < n; k++) {
        for (i32 i = 0; i < n; i++) {
            for (i32 j = 0; j < n; j++) {
                if (is_inf(cost[i][k]) or is_inf(cost[k][j])) continue;
                chmin(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    return cost;
}
}  // namespace bys
