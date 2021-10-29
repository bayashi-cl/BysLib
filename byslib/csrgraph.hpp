#pragma once
#include "bys.hpp"

namespace bys {
struct Edge {
    int from, to;
    ll cost;
    Edge() {}
    Edge(int from, int to, ll cost = 1LL) : from(from), to(to), cost(cost) {}
    bool operator<(const Edge& rh) const { return cost < rh.cost; }
    bool operator>(const Edge& rh) const { return cost > rh.cost; }
    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        return os << e.from << "-" << e.to << " " << e.cost;
    }
};

template <class T>
struct CSRMatrix {
    int n_node;
    vector<int> index;
    vector<pair<T, int>> data;  // {value, column_index}
    explicit CSRMatrix(int n_node, std::vector<Edge>& edges)
        : n_node(n_node), index(n_node + 1), data(edges.size()) {
        for (auto e : edges) index[e.from + 1]++;
        std::partial_sum(index.begin(), index.end(), index.begin());
        auto counter = index;
        for (auto e : edges) data[counter[e.from]++] = {e.cost, e.to};
    }
    uint size() { return n_node; }
};

template <class T>
pair<vector<ll>, vector<int>> dijkstra(CSRMatrix<T>& graph, int start) {
    using E = pair<ll, int>;
    int n_node = graph.size();
    vector<ll> cost(n_node, LINF);
    cost[start] = 0;
    vector<int> prev(n_node, -1);
    std::priority_queue<E, vector<E>, std::greater<E>> que;
    que.push({0LL, start});
    while (!que.empty()) {
        auto [from_cost, from] = que.top();
        que.pop();
        if (cost[from] < from_cost) continue;
        for (int i = graph.index[from]; i < graph.index[from + 1]; ++i) {
            auto [to_cost, to] = graph.data[i];
            ll temp_cost = cost[from] + to_cost;
            if (temp_cost < cost[to]) {
                cost[to] = temp_cost;
                prev[to] = from;
                que.push({temp_cost, to});
            }
        }
    }
    std::replace(std::begin(cost), std::end(cost), LINF, -1);
    return {cost, prev};
}
vector<int> path_finder(vector<int>& prev, int to) {
    vector<int> path;
    while (to != -1) {
        path.push_back(to);
        to = prev[to];
    }
    reverse(std::begin(path), std::end(path));
    return path;
}
}  // namespace bys
