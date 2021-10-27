#pragma once
#include <atcoder/dsu>

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

struct Dijkstra {
    int n_node;
    vector<int> prev;
    vector<ll> cost;

    Dijkstra(Adj& graph, int start, ll err_val = -1)
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

struct WarshallFloyd {
    int n_node;
    vector<vector<ll>> cost;
    vector<int> prev;

    WarshallFloyd(const Adj& graph)
        : n_node(graph.size()), cost(n_node, vector<ll>(n_node, LINF)) {
        for (int i = 0; i < n_node; ++i) {
            for (auto e : graph[i]) cost[i][e.to] = e.cost;
        }
        for (int i = 0; i < n_node; ++i) cost[i][i] = 0;
        search();
    }

    void search() {
        for (int k = 0; k < n_node; k++) {
            for (int i = 0; i < n_node; i++) {
                for (int j = 0; j < n_node; j++) {
                    chmin(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
};

struct Kruskal {
    int n_node;
    vector<Edge> mst;
    ll cost = 0;
    Kruskal(vector<Edge>& edges, int n_tree = 1) : n_node(edges.size()) {
        sort(edges.begin(), edges.end());
        search(edges, n_tree);
    }
    void search(const vector<Edge>& edges, int n_tree) {
        atcoder::dsu uft(n_node);
        int sz = n_node;
        for (auto&& e : edges) {
            if (uft.same(e.from, e.to)) continue;
            uft.merge(e.from, e.to);
            mst.push_back(e);
            cost += e.cost;
            --sz;
            if (sz == n_tree) return;
        }
    }
};
}  // namespace bys
