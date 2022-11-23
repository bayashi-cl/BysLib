#pragma once
#include <queue>

#include "graph.hpp"
namespace bys {
template <class E>
auto bfs(const AdjacencyList<E>& graph, typename E::vertex_type source) {
    using W = typename E::weight_type;
    using V = typename E::vertex_type;
    std::vector<W> cost(graph.size(), get_inf<W>());
    cost[source] = 0;
    std::queue<V> que;
    que.push(source);
    while (not que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto&& nxt : graph[top]) {
            if (is_inf(cost[nxt.dest])) {
                cost[nxt.dest] = cost[top] + 1;
                que.push(nxt.dest);
            }
        }
    }
    return cost;
}

template <class E>
auto zero_one_bfs(const AdjacencyList<E>& graph, typename E::vertex_type source) {
    using W = typename E::weight_type;
    using V = typename E::vertex_type;
    std::vector<W> cost(graph.size(), LINF);
    cost[source] = 0;
    std::deque<V> que;
    que.push_back(source);
    while (not que.empty()) {
        auto top = que.front();
        que.pop_front();
        for (auto&& nxt : graph[top]) {
            if (is_inf(cost[nxt.dest])) {
                cost[nxt.dest] = cost[top] + nxt.weight;
                if (nxt.weight == 0) {
                    que.push_front(nxt.dest);
                } else {
                    que.push_back(nxt.dest);
                }
            }
        }
    }
    return cost;
}
}  // namespace bys
