#pragma once
#include <queue>
#include <vector>

#include "../core/alias.hpp"
#include "graph.hpp"
/**
 * @file topological_sort.hpp
 * @brief Topological Sort
 */
namespace bys {
/**
 * @brief トポロジカルソート
 *
 * O(V + E)
 */
template <class E> std::vector<i32> topological_sort(AdjacencyList<E> const& graph) {
    using V = typename E::vertex_type;
    auto n = graph.size();
    std::vector<V> res;
    std::vector<i32> degree(n);
    res.reserve(n);
    for (std::size_t i = 0; i < n; ++i) {
        for (auto&& e : graph[i]) ++degree[e.dest];
    }
    std::queue<V> que;
    for (std::size_t i = 0; i < n; ++i) {
        if (degree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        res.emplace_back(top);
        for (auto&& nxt : graph[top]) {
            if (--degree[nxt.dest] == 0) que.push(nxt.dest);
        }
    }
    return res;
}
}  // namespace bys
