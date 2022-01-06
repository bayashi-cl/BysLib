#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "core/core.hpp"
#include "graph/lca.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = input<int, 2>();
    auto p = input<int>(n - 1);
    Adj graph(n);
    for (int i = 0; i < n - 1; ++i) {
        graph[p[i]].push_back({i + 1});
        graph[i + 1].push_back(p[i]);
    }
    LowestCommonAncestor lca(graph);
    for (int i = 0; i < q; ++i) {
        auto [u, v] = input<int, 2>();
        print(lca.lca(u, v));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
