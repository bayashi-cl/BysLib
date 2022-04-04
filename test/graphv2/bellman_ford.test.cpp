#define PROBLEM "https://atcoder.jp/contests/abc137/tasks/abc137_e"
#include "../../core/core.hpp"
#include "../../graphv2/bellman_ford.hpp"
#include "../../graphv2/edge.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, m, p] = scanner.read<int, 3>();
    vector<Edge> edges;
    for (UV : irange(m)) {
        auto [a, b, c] = scanner.read<Int1, Int1, int>();
        edges.emplace_back(a, b, -c + p);
    }
    auto res = bellman_ford(edges, n, 0);
    if (res.cost[n - 1] == -LINF) {
        print(-1);
    } else {
        print(max(-res.cost[n - 1], 0LL));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
