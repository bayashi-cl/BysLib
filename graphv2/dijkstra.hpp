#include "../core/stdlib.hpp"
#include "edge.hpp"
#include "result.hpp"

namespace bys {
SSSPResult dijkstra(const AdjacencyList& graph, int source) {
    using Node = std::pair<ll, std::size_t>;
    std::size_t n = graph.size();
    SSSPResult res(n, source);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> que;
    res.cost[source] = 0;
    que.push({0, source});

    while (!que.empty()) {
        auto [top_cost, top] = que.top();
        que.pop();
        if (res.cost[top] < top_cost) continue;
        for (auto&& next : graph[top]) {
            ll next_cost = res.cost[top] + next.weight;
            if (next_cost < res.cost[next]) {
                res.cost[next] = next_cost;
                res.prev[next] = top;
                que.push({next_cost, next});
            }
        }
    }
    return res;
}
}  // namespace bys
