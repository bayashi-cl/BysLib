#pragma once
/**
 * @file warshall_floyd.hpp
 * @author bayashi_cl
 * @brief Warshall Floyd
 */
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "../utility/change.hpp"
#include "edge.hpp"
#include "result.hpp"

namespace bys {
/**
 * @brief Warshall Floyd
 *
 * O(VE)
 *
 * @param graph 辺リスト
 */
APSPResult warshall_floyd(const std::vector<Edge>& graph, std::size_t n_node) {
    APSPResult res(n_node);
    for (auto&& e : graph) res.cost[e.src][e.dest] = e.weight;
    for (std::size_t i = 0; i < n_node; ++i) res.cost[i][i] = 0;
    for (std::size_t i = 0; i < n_node; ++i) {
        for (std::size_t j = 0; j < n_node; ++j) {
            res.prev[i][j] = i;
        }
    }
    for (std::size_t k = 0; k < n_node; k++) {
        for (std::size_t i = 0; i < n_node; i++) {
            for (std::size_t j = 0; j < n_node; j++) {
                if (res.cost[i][k] == LINF || res.cost[k][j] == LINF) continue;
                if (chmin(res.cost[i][j], res.cost[i][k] + res.cost[k][j])) {
                    res.prev[i][j] = res.prev[k][j];
                }
            }
        }
    }
    return res;
}
}  // namespace bys
