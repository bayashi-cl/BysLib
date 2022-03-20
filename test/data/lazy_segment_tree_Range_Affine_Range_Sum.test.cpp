#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../acl/acl.hpp"
#include "../../core/core.hpp"
#include "../../data/lazy_segment_tree.hpp"
#include "../../monoid/mapping_modint.hpp"
#include "../../monoid/monoid_modint.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<mint>(n);
    LazySegmentTree<AddModint<mint>, AffineModint<mint>, Mapping<AddModint<mint>, AffineModint<mint>>> seg(a);
    for (UV : irange(q)) {
        auto t = scanner.read<int>();
        if (t == 0) {
            auto [l, r] = scanner.read<int, 2>();
            auto [b, c] = scanner.read<mint, 2>();
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
