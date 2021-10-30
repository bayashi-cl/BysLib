#pragma once
#include "byslib/graph/edge.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct Dijkstra {
    int n_node;
    vector<int> prev;
    vector<ll> cost;

    Dijkstra(const Adj& graph, int start, ll err_val = -1)
        : n_node(graph.size()), prev(n_node, -1), cost(n_node, LINF) {
        search(graph, start);
        std::replace(cost.begin(), cost.end(), LINF, err_val);
    }

    void search(const Adj& graph, int start) {
        using Node = std::pair<ll, int>;
        std::priority_queue<Node, vector<Node>, std::greater<Node>> que;
        cost[start] = 0;
        que.push({0, start});
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            if (cost[top.second] < top.first) continue;
            for (auto&& next : graph[top.second]) {
                ll next_cost = cost[top.second] + next.cost;
                if (next_cost < cost[next.to]) {
                    cost[next.to] = next_cost;
                    prev[next.to] = top.second;
                    que.push({next_cost, next.to});
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
