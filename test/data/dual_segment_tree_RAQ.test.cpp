#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E"
#include "../../algebra/monoid.hpp"
#include "../../core/core.hpp"
#include "../../data/dual_segment_tree.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    DualSegmentTree<int, Add<int>> seg(n, 0);
    for (UV : irange(q)) {
        auto c = scanner.read<int>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<Int1, int, int>();
            seg.apply(s, t, x);
        } else {
            auto i = scanner.read<Int1>();
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
