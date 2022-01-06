#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
#include "../../core/core.hpp"
#include "../../math/prime.hpp"

namespace bys {
void Solver::solve() {
    auto n = input<int>();
    cout << n << ": " << prime_factorize(n) << endl;
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve();
    return 0;
}
