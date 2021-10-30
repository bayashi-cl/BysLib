#pragma once
#include "byslib/graph/edge.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct DepthFirstSearch {
    const Adj& graph;
    vector<bool> seen;
    vector<int> pre_order;
    vector<int> post_order;
    vector<int> tour;

    DepthFirstSearch(const Adj& graph, int start)
        : graph(graph), seen(graph.size()) {
        search(start);
    }

    void search(int now) {
        seen[now] = true;
        pre_order.push_back(now);
        tour.push_back(now);
        for (auto&& to : graph[now]) {
            if (seen[to.to]) continue;
            search(to.to);
            tour.push_back(now);
        }
        post_order.push_back(now);
    }
};
}  // namespace bys
