#pragma once

#include "bys.hpp"

namespace bys {
struct Edge {
    int from, to;
    ll cost;
    // 重みなし単頂点
    Edge(int to) : from(-1), to(to), cost(1) {}
    // 重み付き単頂点
    Edge(int to, ll cost) : from(-1), to(to), cost(cost) {}
    // 重み付き両頂点
    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
    bool operator<(const Edge& rh) const { return cost < rh.cost; }
    friend std::ostream& operator>>(std::ostream& os, const Edge& e) {
        return os << e.from << " - " << e.to << ": " << e.cost;
    }
};
using Adj = vector<vector<Edge>>;
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

struct DeapthFirstSearch {
    const Adj& graph;
    vector<bool> seen;
    vector<int> pre_order;
    vector<int> post_order;
    vector<int> tour;

    DeapthFirstSearch(const Adj& graph, int start)
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

struct ZeroOneBFS {
    int n_node;
    vector<int> cost;
    vector<int> prev;

    ZeroOneBFS(Adj& graph, int start, int err_val = -1)
        : n_node(graph.size()), cost(n_node, INF), prev(n_node, -1) {
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
