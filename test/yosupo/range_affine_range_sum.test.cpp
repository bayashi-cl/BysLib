#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "byslib/algebra/modint.hpp"
#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/lazy_segment_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    auto a = scanner.readvec<Mint>(n);
    LazySegmentTree<Add<Mint>, Affine<Mint>> seg(a);
    for (UV : irange(q)) {
        auto t = scanner.read<i32>();
        if (t == 0) {
            auto [l, r, b, c] = scanner.read<i32, 4>();
            seg.effect(l, r, {b, c});
        } else {
            auto [l, r] = scanner.read<i32, 2>();
            print(seg.fold(l, r));
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
