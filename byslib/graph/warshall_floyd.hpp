#pragma once
/**
 * @file warshall_floyd.hpp
 * @brief Warshall Floyd
 */
#include "../core/const.hpp"
#include "../utility/change.hpp"
#include "graph.hpp"

namespace bys {
/**
 * @brief Warshall Floyd
 *
 * O(V^3)
 *
 * @param graph 辺リスト
 */

template <class E>
std::vector<std::vector<typename E::weight_type>> warshall_floyd(EdgeList<E> const& graph) {
    using W = typename E::weight_type;
    int n = graph.size();
    std::vector cost(n, std::vector(n, get_inf<W>()));
    for (auto&& [src, id, e] : graph) chmin(cost[src][e.dest], e.weight);
    for (int i = 0; i < n; ++i) cost[i][i] = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (is_inf(cost[i][k]) or is_inf([k][j])) continue;
                chmin(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    return cost;
}
}  // namespace bys