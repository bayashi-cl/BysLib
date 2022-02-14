#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../core/core.hpp"
#include "../../utility/range.hpp"
#include "../../utility/change.hpp"
#include "../../data/sparse_table.hpp"
#include "../../math/algebra.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<int>(n);
    SparseTable<Min<int>> st(a);
    for (UV : irange(q)) {
        auto [l, r] = scanner.read<int, 2>();
        print(st.query(l, r));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
