#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../core/core.hpp"
// -------------------------------------
#include "../../algebra/monoid.hpp"
#include "../../data/segment_tree.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<ll>(n);
    SegmentTree<Add<ll>> seg(a);
    for (UV : irange(q)) {
        auto [t, l, r] = scanner.read<int, 3>();
        if (t == 0) {
            seg.update(l, seg[l] + r);

        } else {
            print(seg.query(l, r));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
