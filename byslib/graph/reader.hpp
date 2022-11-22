#pragma once
#include "../core/io.hpp"
#include "../core/stdlib.hpp"
#include "graph.hpp"
/**
 * @file reader.hpp
 * @brief Reader
 *
 * グラフ入力
 */
namespace bys {
//! @brief 重みなし隣接リスト
auto read_adj_uv(std::size_t n, std::size_t m, bool directed = false, int index = 1) {
    EdgeList<Edge<int>> edges(n);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v] = scanner.read<int, 2>();
        u -= index;
        v -= index;
        if (directed) {
            edges.add_edge(u, v);
        } else {
            edges.add_undirected_edge(u, v);
        }
    }
    return edges.adj();
}
//! @brief 重みつき隣接リスト
auto read_adj_uvc(std::size_t n, std::size_t m, bool directed = false, int index = 1) {
    EdgeList<Edge<long long>> edges(n);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v, c] = scanner.read<int, int, ll>();
        u -= index;
        v -= index;
        if (directed) {
            edges.add_edge(u, v, c);
        } else {
            edges.add_undirected_edge(u, v, c);
        }
    }
    return edges.adj();
}
}  // namespace bys
