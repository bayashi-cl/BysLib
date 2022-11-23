#pragma once
#include <stack>

#include "../utility/fixpoint.hpp"
#include "graph.hpp"

namespace bys {
template <class E>
auto dfs(AdjacencyList<E> const& graph, typename E::vertex_type source) {
    using V = typename E::vertex_type;
    std::vector<bool> seen(graph.size());
    std::vector<V> res;
    std::stack<V> st;
    st.push(source);
    while (not st.empty()) {
        auto top = st.top();
        st.pop();
        seen[top] = true;
        res.push_back(top);
        for (auto&& e : graph[top]) {
            if (not seen[e.dest]) {
                st.push(e.dest);
            }
        }
    }
}
template <class E>
auto pre_order(const AdjacencyList<E>& graph) {
    using V = typename E::vertex_type;
    int n = graph.size();
    std::vector<bool> seen(n);
    std::vector<V> res;
    FixPoint pre_dfs([&](auto&& self, V now) -> void {
        seen[now] = true;
        res.push_back(now);
        for (auto&& e : graph[now]) {
            if (not seen[e.dest]) self(e.dest);
        }
    });
    for (int i = 0; i < n; ++i) {
        if (not seen[i]) pre_dfs(i);
    }
    return res;
}

// std::vector<int> in_order(const AdjacencyList& graph, int source);
template <class E>
auto post_order(const AdjacencyList<E>& graph) {
    using V = typename E::vertex_type;
    int n = graph.size();
    std::vector<bool> seen(n);
    std::vector<V> res;
    FixPoint post_dfs([&](auto&& self, V now) -> void {
        seen[now] = true;
        for (auto&& e : graph[now]) {
            if (not seen[e.dest]) self(e.dest);
        }
        res.push_back(now);
    });
    for (int i = 0; i < n; ++i) {
        if (not seen[i]) post_dfs(i);
    }
    return res;
}
// std::vector<int> euler_tour(const AdjacencyList& graph, int source);
}  // namespace bys
