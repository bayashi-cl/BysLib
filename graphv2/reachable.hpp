#pragma once
#include "../core/stdlib.hpp"
#include "edge.hpp"
namespace bys {
std::vector<bool> reachable(const AdjacencyList& graph, std::size_t source) {
    std::vector<bool> res(graph.size());
    std::stack<std::size_t> stack;
    stack.push(source);
    res[source] = true;
    while (not stack.empty()) {
        auto top = stack.top();
        stack.pop();
        for (auto&& nxt : graph[top]) {
            if (not res[nxt.dest]) {
                stack.push(nxt.dest);
                res[nxt.dest] = true;
            }
        }
    }
    return res;
}
}  // namespace bys
