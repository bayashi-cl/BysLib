#pragma once
#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "edge.hpp"
/**
 * @file depth_first_search.hpp
 * @brief Depth First Search
 *
 * 深さ優先探索
 */
namespace bys {
template <class Adj>
class DepthFirstSearch {
    const Adj& _graph;
    const std::size_t _n;

   public:
    std::vector<int> prev;
    std::vector<ll> cost;
    std::vector<std::size_t> pre_order, post_order, euler_tour;
    DepthFirstSearch(const Adj& graph, std::size_t root) : _graph(graph), _n(graph.size()), prev(_n, -1), cost(_n, LINF) {
        pre_order.reserve(_n);
        post_order.reserve(_n);
        euler_tour.reserve(2 * _n - 1);
        cost[root] = 0;
        search(root);
    }
    DepthFirstSearch(const Adj& graph) : _graph(graph), _n(graph.size()), prev(_n, -1), cost(_n, -1) {
        pre_order.reserve(_n);
        post_order.reserve(_n);
        euler_tour.reserve(2 * _n - 1);
    }

    void crawl() {
        for (std::size_t i = 0; i < _n; ++i) {
            if (cost[i] == -1) {
                cost[i] = 0;
                search(i);
            }
        }
    }
    void search(std::size_t now) {
        pre_order.emplace_back(now);
        euler_tour.emplace_back(now);
        for (auto&& next : _graph[now]) {
            if (cost[next] != LINF) continue;
            cost[next] = cost[now] + next.weight;
            prev[next] = now;
            search(next.dest);
            euler_tour.emplace_back(now);
        }
        post_order.emplace_back(now);
    }

    ll dist(std::size_t s, std::size_t t, std::size_t lca) {
        assert(cost[s] != LINF);
        assert(cost[t] != LINF);
        assert(cost[lca] != LINF);
        return cost[s] + cost[t] - 2 * cost[lca];
    }
};
}  // namespace bys
