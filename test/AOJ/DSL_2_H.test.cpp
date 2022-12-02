#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/lazy_segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    vector<i64> init(n);
    LazySegmentTree<Min<i64>, Add<i64>> seg(init);
    for (UV : irange(q)) {
        auto c = scanner.read<i32>();
        if (c == 0) {
            auto [s, t, x] = scanner.read<i32, 3>();
            seg.apply(s, t + 1, x);
        } else {
            auto [s, t] = scanner.read<i32, 2>();
            print(seg.query(s, t + 1));
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
