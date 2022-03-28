#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"
#include "../../core/core.hpp"
#include "../../math/euclid.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"
namespace bys {
void Solver::solve() {
    auto [a, b] = scanner.read<int, 2>();
    auto [d, x, y] = ext_gcd(a, b);
    print(x, y);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
