#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "core/core.hpp"
#include "data/cumulative_sum.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = input<int, 2>();
    auto a = input<ll>(n);
    CumulativeSum cs(a);
    cs.construct();
    for (int i = 0; i < q; ++i) {
        auto [l, r] = input<int, 2>();
        print(cs.sum(l, r));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
