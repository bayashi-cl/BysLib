#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "byslib/algebra/monoid.hpp"
#include "byslib/ds/sparse_table.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    auto a = scanner.readvec<i32>(n);
    SparseTable<Min<i32>> st(a);
    for (UV : irange(q)) {
        auto [l, r] = scanner.read<i32, 2>();
        print(st.fold(l, r));
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
