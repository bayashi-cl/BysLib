#pragma once
#include "utility/fixpoint.hpp"
#include "edge.hpp"
namespace bys {
Adj make_directed_tree(const Adj& graph, int root = 0) {
    Adj res(graph.size());
    FixPoint dfs([&](auto&& self, int now, int prev = -1) -> void {
        for (auto&& nxt : graph[now]) {
            if (nxt.to != prev) {
                res[now].push_back(nxt);
                self(nxt.to, now);
            }
        }
    });
    dfs(root);
    return res;
}
}  // namespace bys
