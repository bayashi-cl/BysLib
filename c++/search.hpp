#pragma once

#include "bys.hpp"

namespace bys {

struct BreadthFirstSearch {
    using Adj = vector<vector<int>>;

    Adj graph;
    int n_node;

    BreadthFirstSearch(Adj graph) : graph(graph), n_node(graph.size()) {}

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

    DeapthFirstSearch(Adj graph) : graph(graph) {}

    void search(int now, int from = -1) {
        pre_order.push_back(now);
        for (int to : graph[now]) {
            if (to == from) continue;
            search(to, now);
        }
        post_order.push_back(now);
    }
};

}  // namespace bys
