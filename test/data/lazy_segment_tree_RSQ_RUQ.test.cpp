#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"
#include "../../core/core.hpp"
#include "../../data/lazy_segment_tree.hpp"
#include "../../monoid/monoid.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    LazySegmentTree<Add<int>, Update<int>> seg(n);
    for ([[maybe_unused]] int i : irange(q)) {
        auto c = scanner.read<int>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<int, 3>();
            seg.apply(s, t + 1, x);
        } else {
            auto [s, t] = scanner.read<int, 2>();
            print(seg.query(s, t + 1));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
