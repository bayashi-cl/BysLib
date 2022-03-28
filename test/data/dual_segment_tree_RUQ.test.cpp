#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"
#include "../../algebra/monoid.hpp"
#include "../../core/core.hpp"
#include "../../data/dual_segment_tree.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    DualSegmentTree<int, Update<int>> seg(n, (1LL << 31) - 1);
    for (UV : irange(q)) {
        auto c = scanner.read<int>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<int, 3>();
            seg.apply(s, t + 1, x);
        } else {
            auto i = scanner.read<int>();
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
