#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 1e-8
#include "../../core/core.hpp"
#include "../../geometry/line.hpp"

namespace bys {
void Solver::solve() {
    auto [p1, p2] = input<geo::Point<ld>, 2>();
    geo::Line l(p1, p2);
    auto q = input<int>();
    for (int i = 0; i < q; ++i) {
        auto p = input<geo::Point<ld>>();
        print(geo::projection(p, l));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
