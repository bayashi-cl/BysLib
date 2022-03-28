#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include "../../algebra/monoid.hpp"
#include "../../core/core.hpp"
#include "../../data/segment_tree.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    SegmentTree<Add<int>> seg(n);
    for (UV : irange(q)) {
        auto [t, x, y] = scanner.read<int, 3>();
        if (t == 0) {
            seg.update(x - 1, seg[x - 1] + y);

        } else {
            print(seg.query(x - 1, y));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
