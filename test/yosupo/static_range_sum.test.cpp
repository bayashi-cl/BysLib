#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../byslib/ds/cumulative_sum.hpp"
#include "../../byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    auto a = scanner.readvec<i64>(n);
    auto cs = cumsum(a);
    for (int i = 0; i < q; ++i) {
        auto [l, r] = scanner.read<i32, 2>();
        print(cs.fold(l, r));
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
