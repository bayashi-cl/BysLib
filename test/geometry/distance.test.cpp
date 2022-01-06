#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 1e-8
#include "../../core/core.hpp"
#include "../../geometry/line.hpp"

namespace bys {
void Solver::solve() {
    auto q = input<int>();
    for (int i = 0; i < q; ++i) {
        auto [p0, p1, p2, p3] = input<geo::Point<ld>, 4>();
        geo::Segment s1(p0, p1), s2(p2, p3);
        print(geo::distance(s1, s2));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
