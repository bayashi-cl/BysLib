#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "byslib/ds/binary_indexed_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    auto a = scanner.readvec<i64>(n);
    FenwickTree<i64> fw(a);
    for (UV : irange(q)) {
        auto [t, l, r] = scanner.read<i32, 3>();
        if (t == 0) {
            fw.set(l, fw[l] + r);
        } else {
            print(fw.fold(l, r));
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
