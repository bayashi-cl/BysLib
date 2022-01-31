#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#define ERROR 1e-8
#include "../../core/core.hpp"
#include "../../geometry/polygon.hpp"

namespace bys {
void Solver::solve() {
    auto n = scanner.read<int>();
    geo::Polygon p(scanner.readvec<geo::Point<ld>>(n));
    print(p.area());
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
