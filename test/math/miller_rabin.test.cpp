#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include "byslib/core/core.hpp"
// -------------------------------------
#include "byslib/math/prime.hpp"

namespace bys {
void Solver::solve() {
    auto x = scanner.read<ll>();
    print(x, is_prime(x) ? 1 : 0);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(bys::scanner.read<int>());
    return 0;
}
