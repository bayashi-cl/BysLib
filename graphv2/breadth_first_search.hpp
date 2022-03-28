#pragma once
#include "../core/const.hpp"
#include "../core/macro.hpp"
#include "../core/stdlib.hpp"
#include "edge.hpp"
#include "result.hpp"
/**
 * @file breadth_first_search.hpp
 * @author bayashi_cl
 * @brief Breadth First Search
 *
 * 幅優先探索
 */
namespace bys {
/**
 * @brief 幅優先探索
 *
 * O(V + E)
 *
 * @param graph AdjacencyList or DynamicAdjacencyList
 * @param source 始点
 * @return SSSPResult
 * @todo 多始点対応
 */
template <class Adj>
SSSPResult breadth_first_search(const Adj& graph, std::size_t source) {
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
/**
 * @brief 01BFS
 *
 * O(V + E)
 *
 * @param graph AdjacencyList or DynamicAdjacencyList
 * @param source 始点
 * @return SSSPResult
 */
template <class Adj>
SSSPResult zero_one_bfs(const Adj& graph, std::size_t source) {
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
