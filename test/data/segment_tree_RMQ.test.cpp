#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include "../../core/core.hpp"
#include "../../data/segment_tree.hpp"
#include "../../math/algebra.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    SegmentTree<Min<int>> seg(n);
    for (UV : irange(q)) {
        auto [t, x, y] = scanner.read<int, 3>();
        if (t == 0) {
            seg.update(x, y);

        } else {
            print(seg.query(x, y + 1));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
