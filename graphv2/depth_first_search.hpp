#pragma once
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
    std::vector<int> prev, cost;
    std::vector<std::size_t> pre_order, post_order, euler_tour;
    DepthFirstSearch(const Adj& graph, std::size_t root) : _graph(graph), _n(graph.size()), prev(_n, -1), cost(_n, -1) {
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
            if (cost[next] != -1) continue;
            cost[next] = cost[now] + 1;
            prev[next] = now;
            search(next.dest);
            euler_tour.emplace_back(now);
        }
        post_order.emplace_back(now);
    }
};
}  // namespace bys
