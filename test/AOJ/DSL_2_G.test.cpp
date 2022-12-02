#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/lazy_segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    LazySegmentTree<Add<i64>, Add<i64>> seg(n);
    for (UV : irange(q)) {
        auto c = scanner.read<i32>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<i32, 3>();
            seg.effect(s - 1, t, x);
        } else {
            auto [s, t] = scanner.read<i32, 2>();
            print(seg.fold(s - 1, t));
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
