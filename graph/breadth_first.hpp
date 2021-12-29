#pragma once
#include "byslib/core/stdlib.hpp"
#include "byslib/core/const.hpp"
#include "edge.hpp"

namespace bys {
struct BreadthFirstSearch {
    int n_node;
    vector<int> prev;
    vector<int> cost;

    BreadthFirstSearch(const Adj& graph, int start, int err_val = -1)
        : n_node(graph.size()), prev(n_node, -1), cost(n_node, INF) {
        search(graph, start);
        std::replace(cost.begin(), cost.end(), INF, err_val);
    }

    void search(const Adj& graph, int start) {
        cost[start] = 0;
        std::queue<int> que;
        que.push(start);
        while (!que.empty()) {
            int from = que.front();
            que.pop();
            for (auto&& to : graph[from]) {
                if (cost[to.to] == INF) {
                    prev[to.to] = from;
                    cost[to.to] = cost[from] + 1;
                    que.push(to.to);
                }
            }
        }
    }
    vector<int> path(int to) {
        assert(to < n_node);
        vector<int> res;
        while (to != -1) {
            res.push_back(to);
            to = prev[to];
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
struct ZeroOneBFS {
    int n_node;
    vector<int> cost;
    vector<int> prev;

    ZeroOneBFS(Adj& graph, int start, int err_val = -1) : n_node(graph.size()), cost(n_node, INF), prev(n_node, -1) {
        search(graph, start);
        std::replace(cost.begin(), cost.end(), INF, err_val);
    }

    void search(const Adj& graph, int start) {
        std::deque<int> que;
        cost[start] = 0;
        que.push_back(start);
        while (!que.empty()) {
            int now = que.front();
            que.pop_front();
            for (auto&& to : graph[now]) {
                int dist = cost[now] + to.cost;
                if (dist >= cost[to.to]) continue;
                cost[to.to] = dist;
                prev[to.to] = now;
                if (to.cost == 0) {
                    que.push_front(to.to);
                } else {
                    que.push_back(to.to);
                }
            }
        }
    }
    vector<int> path(int to) {
        assert(to < n_node);
        vector<int> res;
        while (to != -1) {
            res.push_back(to);
            to = prev[to];
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
}  // namespace bys
