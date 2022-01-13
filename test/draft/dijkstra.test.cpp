#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include "core/core.hpp"
#include "graph/reader.hpp"
#include "draft/dijkstra.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e, r] = scanner.read<int, 3>();
    auto graph = read_adj_uvc(v, e, true, 0);
    Dijkstra dij(graph, r);
    for (int i = 0; i < v; ++i) print(dij.cost_str(i));
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
