#pragma once
#include "edge.hpp"
namespace bys {
template <class E, typename std::enable_if_t<is_edge_v<E>, std::nullptr_t> = nullptr>
AdjacencyList from_parent(const std::vector<E>& prev) {
    int n = prev.size();
    EdgeList edges(n);
    for (int i = 0; i < n; ++i) {
        auto e = prev[i];
        if (e.dest != i) {
            edges.push_back(i, e);
            std::swap(e.dest, i);
            edges.push_back(i, e);
        }
    }
    return AdjacencyList(edges);
}
AdjacencyList from_parent(const std::vector<int>& prev) {
    int n = prev.size();
    EdgeList edges(n);
    for (int i = 0; i < n; ++i) {
        if (prev[i] != i) {
            edges.emplace_back(i, prev[i]);
            edges.emplace_back(prev[i], i);
        }
    }
    return AdjacencyList(edges);
}

//! @brief 根付き木に変換
template <class E>
CSRMatrix<E> rooted(const CSRMatrix<E>& graph, int root) {
    auto n = graph.size();
    std::vector<bool> seen(n);
    COOMatrix<E> res(n);
    vector<int> stack({root});
    while (!stack.empty()) {
        auto now = stack.back();
        stack.pop_back();
        seen[now] = true;
        for (auto&& nxt : graph[now]) {
            if (seen[nxt.dest]) continue;
            res.add_edge(nxt);
            stack.push_back(nxt.dest);
        }
    }
    return res;
}
template <class E>
std::vector<E> root_path(const std::vector<E> prev, int to) {
    std::vector<E> res;
    while (prev[to].dest != to) {
        res.push_back(prev[to]);
        to = prev[to].dest;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
}  // namespace bys
