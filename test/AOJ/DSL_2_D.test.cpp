#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/dual_segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    DualSegmentTree<i32, Update<i32>> seg(n, (1LL << 31) - 1);
    for (UV : irange(q)) {
        auto c = scanner.read<i32>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<i32, 3>();
            seg.apply(s, t + 1, x);
        } else {
            auto i = scanner.read<i32>();
            print(seg[i]);
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
