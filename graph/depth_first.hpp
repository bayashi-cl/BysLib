#pragma once
#include "edge.hpp"
#include "../core/stdlib.hpp"

namespace bys {
struct DepthFirstSearch {
    const Adj& graph;
    int n_node;
    vector<int> cost;
    vector<int> pre_order;
    vector<int> post_order;
    vector<int> tour;
    vector<int> prev;

    DepthFirstSearch(const Adj& graph, int start) : graph(graph), n_node(graph.size()), cost(n_node, -1), prev(n_node, -1) {
        cost[start] = 0;
        search(start);
    }
    DepthFirstSearch(const Adj& graph) : graph(graph), n_node(graph.size()), cost(n_node, -1), prev(n_node, -1) {}

    void crawl() {
        for (int i = 0; i < n_node; ++i) {
            if (cost[i] == -1) {
                cost[i] = 0;
                search(i);
            }
        }
    }

    void search(int now) {
        // cost[now] = true;
        pre_order.push_back(now);
        tour.push_back(now);
        for (auto&& to : graph[now]) {
            if (cost[to.to] != -1) continue;
            cost[to.to] = cost[now] + 1;
            prev[to.to] = now;
            search(to.to);
            tour.push_back(now);
        }
        post_order.push_back(now);
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
