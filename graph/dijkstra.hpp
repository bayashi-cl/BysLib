#pragma once
#include "graph.hpp"
namespace bys {
template <class E>
auto dijkstra(AdjacencyList<E> const& graph, typename E::vertex_type source) {
    using V = typename E::vertex_type;
    using W = typename E::weight_type;
    using Node = std::pair<W, V>;
    std::vector<W> cost(graph.size(), get_inf<W>());
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
    cost[source] = 0;
    que.emplace(0, source);
    while (not que.empty()) {
        auto [top_cost, top] = que.top();
        que.pop();
        if (cost[top] < top_cost) continue;
        for (auto&& next : graph[top]) {
            auto next_cost = cost[top] + next.weight;
            if (next_cost < cost[next.dest]) {
                cost[next.dest] = next_cost;
                que.emplace(next_cost, next.dest);
            }
        }
    }
    return cost;
}
}  // namespace bys
