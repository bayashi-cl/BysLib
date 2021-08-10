#pragma once

#include "bys.hpp"

namespace bys {

struct BreadthFirstSearch {
    using Adj = vector<vector<int>>;
    Adj graph;
    int n_node;
    vector<int> prev;

    BreadthFirstSearch(Adj graph)
        : graph(graph), n_node(graph.size()), prev(n_node, -1) {}

    vector<int> search(int start) {
        vector<int> cost(n_node, INF);
        cost[start] = 0;
        std::queue<int> que;
        que.push(start);

        while (!que.empty()) {
            int from = que.front();
            que.pop();
            for (int to : graph[from]) {
                if (cost[to] == INF) {
                    cost[to] = cost[from] + 1;
                    que.push(to);
                }
            }
        }
        return cost;
    }
};

struct DeapthFirstSearch {
    using Adj = vector<vector<int>>;
    Adj graph;
    vector<int> pre_order;
    vector<int> post_order;
    vector<int> tour;
    vector<bool> seen;

    DeapthFirstSearch(Adj graph) : graph(graph), seen(graph.size()) {}

    void search(int now) {
        seen[now] = true;
        pre_order.push_back(now);
        tour.push_back(now);
        for (int to : graph[now]) {
            if (seen[to]) continue;
            search(to);
            tour.push_back(now);
        }
        post_order.push_back(now);
    }
};

struct ZeroOneBFS {
    using Adj = vector<vector<pair<int, int>>>;

    Adj graph;
    int n_node;
    vector<int> cost;

    ZeroOneBFS(Adj& adj)
        : graph(adj), n_node(graph.size()), cost(n_node, INF) {}

    void search(int start) {
        std::deque<int> que;
        cost[start] = 0;
        que.push_back(start);
        while (!que.empty()) {
            int now = que.front();
            que.pop_front();
            for (auto [zo, to] : graph[now]) {
                int dist = cost[now] + zo;
                if (dist >= cost[to]) continue;
                cost[to] = dist;
                if (zo == 0) {
                    que.push_front(to);
                } else {
                    que.push_back(to);
                }
            }
        }
    }
};

}  // namespace bys
