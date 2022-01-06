#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#include "core/core.hpp"
#include "graph/kruskal.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e] = input<int, 2>();
    EdgeList elist;
    for (int i = 0; i < e; ++i) {
        auto [s, t, w] = input<int, 3>();
        elist.push_back({s, t, w});
    }
    Kruskal kru(elist, v);
    print(kru.cost);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
