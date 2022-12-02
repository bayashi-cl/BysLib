#pragma once
#include <stack>
#include <vector>

#include "graph.hpp"

namespace bys {
template <class E, class V = typename E::vertex_type> std::vector<bool> reachable(AdjacencyList<E> const& graph, V source) {
    std::vector<bool> seen(graph.size());
    std::stack<V> st;
    st.push(source);
    while (not st.empty()) {
        auto top = st.top();
        st.pop();
        seen[top] = true;
        for (auto&& e : graph[top]) {
            if (not seen[e.dest]) {
                st.push(e.dest);
            }
        }
    }
    return seen;
}
}  // namespace bys
