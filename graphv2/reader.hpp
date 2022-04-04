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
AdjacencyList read_adj_uv(std::size_t n, std::size_t m, bool directed = false, int index = 1) {
    AdjacencyList graph(n, directed ? m : 2 * m);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v] = scanner.read<int, 2>();
        u -= index;
        v -= index;
        graph.add_edge(u, v);
        if (!directed) graph.add_edge(v, u);
    }
    return graph;
}
//! @brief 重みつき隣接リスト
AdjacencyList read_adj_uvc(std::size_t n, std::size_t m, bool directed = false, int index = 1) {
    AdjacencyList graph(n, directed ? m : 2 * m);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v, c] = scanner.read<int, int, ll>();
        u -= index;
        v -= index;
        graph.add_edge(u, v, c);
        if (!directed) graph.add_edge(v, u, c);
    }
    return graph;
}
//! @brief 重みなし隣接リスト（木）
AdjacencyList read_tree_uv(std::size_t n, bool directed = false, int index = 1) { return read_adj_uv(n, n - 1, directed, index); }
//! @brief 重みつき隣接リスト（木）
AdjacencyList read_tree_uvc(std::size_t n, bool directed = false, int index = 1) {
    return read_adj_uvc(n, n - 1, directed, index);
}
//! @brief 重みなし辺リスト
vector<Edge> read_elist_uv(std::size_t m, int index = 1) {
    vector<Edge> elist;
    elist.reserve(m);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v] = scanner.read<int, 2>();
        u -= index;
        v -= index;
        elist.emplace_back(Edge(u, v, 1));
    }
    return elist;
}
//! @brief 重みつき辺リスト
vector<Edge> read_elist_uvc(std::size_t m, int index = 1) {
    vector<Edge> elist;
    elist.reserve(m);
    for (std::size_t i = 0; i < m; ++i) {
        auto [u, v, c] = scanner.read<int, int, ll>();
        u -= index;
        v -= index;
        elist.emplace_back(Edge(u, v, c));
    }
    return elist;
}
}  // namespace bys
