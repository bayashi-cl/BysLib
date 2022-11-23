#pragma once
#include "edge.hpp"
namespace bys {
template <class E>
std::vector<ll> breadth_first_search(const CSRMatrix<E>& graph, int source) {
    const int n = graph.size();
    vector<ll> cost(n, LINF);
    cost[source] = 0;
    std::queue<int> que;
    que.push(source);
    while (not que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto&& nxt : graph[top]) {
            if (cost[nxt.dest] == LINF) {
                cost[nxt.dest] = cost[top] + 1;
                que.push(nxt.dest);
            }
        }
    }
    return cost;
}
template <class E>
std::vector<ll> zero_one_bfs(const CSRMatrix<E>& graph, int source) {
    int n = graph.size();
    std::vector<ll> cost(n, LINF);
    cost[source] = 0;
    std::deque<int> que;
    que.push_back(source);
    while (not que.empty()) {
        auto top = que.front();
        que.pop_front();
        for (auto&& nxt : graph[top]) {
            if (cost[nxt.dest] == LINF) {
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
