#pragma once
#include "../core/io.hpp"
#include "../core/stdlib.hpp"
#include "edge.hpp"
/**
 * @file reader.hpp
 * @brief Reader
 *
 * グラフ入力
 */
namespace bys {
//! @brief 重みなし隣接リスト
auto read_adj_uv(std::size_t n, std::size_t m, bool directed = false, int index = 1) {
    EList edges(n);
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
    EList edges(n);
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
// //! @brief 重みなし隣接リスト（木）
// AdjacencyList read_tree_uv(std::size_t n, bool directed = false, int index = 1) { return read_adj_uv(n, n - 1, directed,
// index); }
// //! @brief 重みつき隣接リスト（木）
// AdjacencyList read_tree_uvc(std::size_t n, bool directed = false, int index = 1) {
//     return read_adj_uvc(n, n - 1, directed, index);
// }

}  // namespace bys
