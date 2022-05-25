#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../core/core.hpp"
#include "../../graph/dijkstra.hpp"

namespace bys {
void Solver::solve() {
    auto [n, m, s, t] = scanner.read<int, 4>();
    Adj graph(n);
    for (int i = 0; i < m; ++i) {
        auto [a, b, c] = scanner.read<int, 3>();
        graph[a].push_back({b, c});
        // graph[b].push_back({a, c});
    }
    Dijkstra dij(graph, s);
    if (dij.cost[t] == -1) EXIT(-1);
    auto path = dij.path(t);
    int sz = path.size();
    print(dij.cost[t], sz - 1);
    for (int i = 0; i < sz - 1; ++i) print(path[i], path[i + 1]);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
