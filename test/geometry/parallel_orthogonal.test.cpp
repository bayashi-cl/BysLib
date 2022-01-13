#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include "../../core/core.hpp"
#include "../../geometry/line.hpp"

namespace bys {
void Solver::solve() {
    auto q = scanner.read<int>();
    for (int i = 0; i < q; ++i) {
        auto [p0, p1, p2, p3] = scanner.read<geo::Point<ll>, 4>();
        geo::Line s1(p0, p1), s2(p2, p3);
        if (geo::is_parallel(s1, s2)) {
            print(2);
        } else if (geo::is_vertial(s1, s2)) {
            print(1);
        } else {
            print(0);
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
