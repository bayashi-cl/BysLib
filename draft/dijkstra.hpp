#include "../core/stdlib.hpp"
#include "../graph/edge.hpp"

namespace bys {
struct Dijkstra {
    const Adj& graph;
    int n_node;
    vector<int> prev;
    vector<std::optional<ll>> cost;
    Dijkstra(const Adj& graph, int start) : graph(graph), n_node(graph.size()), prev(n_node, -1), cost(n_node) { search(start); }

    void search(int start) {
        using Node = std::pair<ll, int>;
        std::priority_queue<Node, vector<Node>, std::greater<Node>> que;
        cost[start] = 0;
        que.push({0, start});
        while (!que.empty()) {
            auto [c, now] = que.top();
            que.pop();
            if (cost[now].has_value() && cost[now] < c) continue;
            for (auto&& next : graph[now]) {
                ll next_cost = cost[now].value() + next.cost;
                if (!cost[next.to].has_value() || next_cost < cost[next.to].value()) {
                    cost[next.to] = next_cost;
                    prev[next.to] = now;
                    que.push({next_cost, next.to});
                }
            }
        }
    }
    string cost_str(int i, const string& err = "INF") const {
        if (cost[i].has_value()) {
            return std::to_string(cost[i].value());
        } else {
            return err;
        }
    }
};
}  // namespace bys
