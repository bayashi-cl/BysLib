#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "byslib/core/core.hpp"
#include "byslib/math/prime.hpp"

namespace bys {
void Solver::solve() {
    auto n = scanner.read<int>();
    cout << n << ": ";
    print(prime_factorize(n));
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve();
    return 0;
}
