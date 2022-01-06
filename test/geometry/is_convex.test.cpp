#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"
#include "../../core/core.hpp"
#include "../../geometry/polygon.hpp"

namespace bys {
void Solver::solve() {
    auto n = input<int>();
    geo::Polygon p(input<geo::Point<ld>>(n));
    print(p.is_convex() ? 1 : 0);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
