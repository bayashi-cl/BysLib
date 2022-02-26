#pragma once
#include "../core/const.hpp"
#include "../core/macro.hpp"
#include "../core/stdlib.hpp"
#include "edge.hpp"
#include "result.hpp"
namespace bys {
SSSPResult breadth_first_search(const AdjacencyList& graph, std::size_t source) {
    std::size_t n = graph.size();
    SSSPResult res(n, source);
    std::queue<std::size_t> que;
    que.emplace(source);
    res.cost[source] = 0;
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto&& next : graph[top]) {
            if (res.cost[next] == LINF) {
                res.prev[next] = top;
                res.cost[next] = res.cost[top] + 1;
                que.emplace(next.dest);
            }
        }
    }
    return res;
}
SSSPResult zero_one_bfs(const AdjacencyList& graph, std::size_t source) {
    std::size_t n = graph.size();
    SSSPResult res(n, source);
    std::deque<std::size_t> que;
    que.emplace_back(source);
    res.cost[source] = 0;
    while (!que.empty()) {
        auto top = que.front();
        que.pop_front();
        for (auto&& next : graph[top]) {
            ll next_cost = res.cost[top] + next.weight;
            if (next_cost >= res.cost[next]) continue;
            res.cost[next] = next_cost;
            res.prev[next] = top;
            if (next.weight == 0) {
                que.emplace_front(next.dest);
            } else if (next.weight == 1) {
                que.emplace_back(next.dest);
            } else {
                throw RE;
            }
        }
    }
    return res;
}

}  // namespace bys
