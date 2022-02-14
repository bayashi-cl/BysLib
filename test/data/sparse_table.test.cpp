#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "byslib/core/core.hpp"
#include "byslib/utility/range.hpp"
#include "byslib/utility/change.hpp"
#include "byslib/data/sparse_table.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    auto a = scanner.readvec<int>(n);
    SparseTable<int> st(a, [](int a, int b) { return min(a, b); });
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
