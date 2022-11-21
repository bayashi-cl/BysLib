#pragma once
#include <queue>
#include <utility>
#include <vector>

#include "edge.hpp"

/**
 * @file dijkstra.hpp
 * @brief Dijkstra
 */
namespace bys {
/**
 * @brief ダイクストラ
 *
 * O(V + Elog(V))
 */
template <class E>
std::vector<ll> dijkstra(const CSRMatrix<E>& graph, int source) {
    using Node = std::pair<ll, std::size_t>;
    std::size_t n = graph.size();
    std::vector<ll> cost(n, LINF);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
    cost[source] = 0;
    que.push({0, source});

    while (!que.empty()) {
        auto [top_cost, top] = que.top();
        que.pop();
        if (cost[top] < top_cost) continue;
        for (auto&& next : graph[top]) {
            ll next_cost = cost[top] + next.weight;
            if (next_cost < cost[next.dest]) {
                cost[next.dest] = next_cost;
                que.push({next_cost, next.dest});
            }
        }
    }
    return cost;
}
}  // namespace bys
