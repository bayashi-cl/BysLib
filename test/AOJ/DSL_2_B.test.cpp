#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    SegmentTree<Add<i32>> seg(n);
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

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
