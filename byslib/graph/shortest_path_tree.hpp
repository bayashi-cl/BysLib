#pragma once
#include "graph.hpp"
#include "tree.hpp"
namespace bys {
template <class E>
Tree<E> shortest_path_tree(AdjacencyList<E> const& graph, std::vector<typename E::weight_type> const& cost,
                           typename E::vertex_type source) {
    using W = typename E::weight_type;
    using V = typename E::vertex_type;
    Tree<E> res(graph.size());

    std::stack<V> st;
    st.push(source);
    while (not st.empty()) {
        auto top = st.top();
        st.pop();
        for (auto&& nxt : graph[top]) {
            if (is_inf(res[nxt.dest].weight) and cost[top] + nxt.weight == cost[nxt.dest]) {
                st.push(nxt.dest);
                res[nxt.dest] = nxt;
            }
        }
    }
    return res;
}
}  // namespace bys
