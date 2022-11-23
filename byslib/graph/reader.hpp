#pragma once
#include "../core/alias.hpp"
#include "../core/io.hpp"
#include "graph.hpp"

/**
 * @file reader.hpp
 * @brief Reader
 *
 * グラフ入力
 */
namespace bys {
//! @brief 重みなし隣接リスト
auto read_adj_uv(i32 n, i32 m, bool directed = false, i32 index = 1) {
    EdgeList<Edge<i32>> edges(n);
    for (i32 i = 0; i < m; ++i) {
        auto [u, v] = scanner.read<i32, 2>();
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
auto read_adj_uvc(i32 n, i32 m, bool directed = false, i32 index = 1) {
    EdgeList<Edge<i64>> edges(n);
    for (i32 i = 0; i < m; ++i) {
        auto [u, v, c] = scanner.read<i32, i32, i64>();
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
