#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "byslib/core/core.hpp"
#include "byslib/data/cumulative_sum.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<ll>(n);
    CumulativeSum cs(a);
    cs.construct();
    for (int i = 0; i < q; ++i) {
        auto [l, r] = scanner.read<int, 2>();
        print(cs.sum(l, r));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
