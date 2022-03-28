#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../algebra/mapping.hpp"
#include "../../algebra/monoid.hpp"
#include "../../core/core.hpp"
#include "../../data/lazy_segment_tree.hpp"
#include "../../math/modint.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<Mint>(n);
    LazySegmentTree<Add<Mint>, Affine<Mint>> seg(a);
    for (UV : irange(q)) {
        auto t = scanner.read<int>();
        if (t == 0) {
            auto [l, r, b, c] = scanner.read<int, 4>();
            seg.apply(l, r, {b, c});
        } else {
            auto [l, r] = scanner.read<int, 2>();
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
