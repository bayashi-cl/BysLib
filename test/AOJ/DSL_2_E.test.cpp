#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/dual_segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    DualSegmentTree<i32, Add<i32>> seg(n, 0);
    for (UV : irange(q)) {
        auto c = scanner.read<i32>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<i32_1, i32, i32>();
            seg.apply(s, t, x);
        } else {
            auto i = scanner.read<i32_1>();
            print(seg[i]);
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
