#pragma once
#include "../core/stdlib.hpp"
#include "edge.hpp"
namespace bys {
AdjacencyList make_rooted(const AdjacencyList& graph, int root) {
    auto n = graph.size();
    std::vector<bool> seen(n);
    AdjacencyList res(n, graph.n_edge() / 2);
    vector<int> stack({root});
    while (!stack.empty()) {
        auto now = stack.back();
        stack.pop_back();
        seen[now] = true;
        for (auto&& nxt : graph[now]) {
            if (seen[nxt.dest]) continue;
            res.add_edge(nxt);
            stack.push_back(nxt.dest);
        }
    }
    return res;
}
}  // namespace bys
