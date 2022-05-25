#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#include "../../core/core.hpp"
#include "../../graphv2/kruskal.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e] = scanner.read<int, 2>();
    vector<Edge> elist;
    for (int i = 0; i < e; ++i) {
        auto [s, t, w] = scanner.read<int, 3>();
        elist.emplace_back(s, t, w);
    }
    sort(elist.begin(), elist.end());
    auto [cost, tree] = kruskal(elist, v);
    print(cost);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
