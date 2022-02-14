#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../core/core.hpp"
#include "../../graphv2/lca.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto p = scanner.readvec<int>(n - 1);
    AdjacencyList graph(n, (n - 1) * 2);
    for (int i = 0; i < n - 1; ++i) {
        graph.add_edge(p[i], i + 1);
        graph.add_edge(i + 1, p[i]);
    }
    LowestCommonAncestor lca(graph, 0);
    for (int i = 0; i < q; ++i) {
        auto [u, v] = scanner.read<int, 2>();
        print(lca.lca(u, v));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
