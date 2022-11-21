#pragma once
#include "edge.hpp"
namespace bys {
template <class E>
std::vector<E> shortest_path_tree(const CSRMatrix<E>& graph, const std::vector<ll>& cost, int source) {
    std::vector<E> res(graph.size());
    res[source].dest = source;
    res[source].weight = 0LL;
    std::stack<int> st;
    st.push(source);
    while (not st.empty()) {
        auto top = st.top();
        st.pop();
        for (auto&& nxt : graph[top]) {
            if (res[nxt.dest].weight == LINF and cost[top] + nxt.weight == cost[nxt.dest]) {
                st.push(nxt.dest);
                res[nxt.dest] = nxt.with_dest(top);
            }
        }
    }
    return res;
}
template <class E>
std::vector<E> shortest_path(const std::vector<E>& prev, int to) {
    std::vector<E> res;
    while (prev[to].dest != to) {
        res.push_back(prev[to].with_dest(to));
        to = prev[to].dest;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
}  // namespace bys
