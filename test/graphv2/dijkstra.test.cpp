#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "core/core.hpp"
#include "byslib/graphv2/dijkstra.hpp"

namespace bys {
void Solver::solve() {
    auto [n, m, s, t] = scanner.read<int, 4>();
    AdjacencyList graph(n, m);
    for (int i = 0; i < m; ++i) {
        auto [s, t, d] = scanner.read<int, 3>();
        graph.add_edge(s, t, d);
    }
    auto res = dijkstra(graph, s);
    if (res.cost[t] == LINF) {
        print(-1);
    } else {
        auto path = res.path(t);
        int y = path.size();
        print(res.cost[t], y - 1);
        for (int i = 0; i < y - 1; ++i) print(path[i], path[i + 1]);
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
