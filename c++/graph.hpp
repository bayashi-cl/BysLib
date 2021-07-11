#ifndef BYS_GRAPH
#define BYS_GRAPH 1

#include <atcoder/dsu>

#include "bys.hpp"

namespace bys {

/**
 * @brief ダイクストラ法による最短経路探索
 * 構築後にDijkstra.search()を実行する
 * O(|E| log|N|)
 * @param graph 隣接グラフ
 */
struct Dijkstra {
    using Edge = std::pair<ll, int>;  // (cost, node)
    using Adj = vector<vector<Edge>>;
    Adj graph;
    vector<ll> cost;
    vector<int> prev;
    int n_node;

    Dijkstra(const Adj& graph) : graph(graph) {
        n_node = graph.size();
        cost.resize(n_node, LINF);
        prev.resize(n_node, -1);
    }

    /**
     * @brief 探索
     * コストはself.costに格納される。
     * @param start 探索開始点
     */
    void search(int start) {
        std::priority_queue<Edge, vector<Edge>, std::greater<Edge>> que;
        cost[start] = 0;
        que.push(Edge(0, start));

        while (!que.empty()) {
            auto [top_cost, top_node] = que.top();
            que.pop();
            if (cost[top_node] < top_cost) continue;
            for (auto [adj_cost, adj_node] : graph[top_node]) {
                ll temp_cost = cost[top_node] + adj_cost;
                if (temp_cost < cost[adj_node]) {
                    cost[adj_node] = temp_cost;
                    prev[adj_node] = top_node;
                    que.push(Edge(temp_cost, adj_node));
                }
            }
        }
    }

    /**
     * @brief 経路復元
     * @param to
     * @return vector<int>
     */
    vector<int> path_finder(int to) {
        assert(to <= n_node);
        vector<int> path;
        while (to != -1) {
            path.push_back(to);
            to = prev[to];
        }
        std::reverse(std::begin(path), std::end(path));
        return path;
    }

    ll get_cost(int i) {
        ll res = cost[i];
        if (res == LINF) res = -1;
        return res;
    }
};

struct BellmanFord {
    using Edge = std::pair<ll, std::pair<int, int>>;
    int n_node;
    vector<Edge> graph;
    vector<ll> cost;

    BellmanFord(vector<Edge> graph, int n_node) : graph(graph), n_node(n_node) {
        cost.resize(n_node, INF);
    }

    bool search(int start) {
        for (int i = 0; i < n_node - 1; i++) relaxing();
        return !relaxing();
    }

   private:
    bool relaxing() {
        bool res = false;
        for (auto [dist, node] : graph) {
            if (cost[node.first] == LINF) continue;
            if (chmin(cost[node.second], cost[node.first] + dist)) res = true;
        }
        return res;
    }
};

struct WarshallFloyd {
    using Edge = std::pair<ll, int>;
    using Adj = vector<vector<Edge>>;

    int n_node;
    vector<vector<ll>> cost;
    vector<int> prev;

    WarshallFloyd(const Adj& graph) : n_node(graph.size()) {
        cost.resize(n_node, vector<ll>(n_node, LINF));
        prev.resize(n_node, -1);

        for (int i = 0; i < n_node; i++) {
            for (auto [dist, j] : graph[i]) cost[i][j] = dist;
        }
        for (int i = 0; i < n_node; i++) cost[i][i] = 0;
    }

    void search() {
        for (int k = 0; k < n_node; k++) {
            for (int i = 0; i < n_node; i++) {
                for (int j = 0; j < n_node; j++) {
                    if (chmin(cost[i][j], cost[i][k] + cost[k][j])) prev[j] = k;
                }
            }
        }
    }

    vector<int> path_finder(int to) {
        assert(to <= n_node);
        vector<int> path;
        while (to != -1) {
            path.push_back(to);
            to = prev[to];
        }
        std::reverse(std::begin(path), std::end(path));
        return path;
    }
};

struct Kruskal {
    using Edge = pair<ll, pair<int, int>>;
    vector<Edge> graph;
    vector<Edge> mst;
    int n_node;

    Kruskal(vector<Edge> graph, int n_node) : graph(graph), n_node(n_node){};

    ll search() {
        sort(std::begin(graph), std::end(graph));
        ll cost = 0;
        atcoder::dsu uft(n_node);
        for (auto&& e : graph) {
            auto [dist, node] = e;
            auto [from, to] = node;
            if (uft.same(from, to)) continue;
            uft.merge(from, to);
            mst.push_back(e);
            cost += dist;
        }
        return cost;
    }
};

}  // namespace bys
#endif
