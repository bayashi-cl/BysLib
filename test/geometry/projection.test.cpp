#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 1e-8
#include "../../core/core.hpp"
#include "../../geometry/line.hpp"

namespace bys {
void Solver::solve() {
    auto [p1, p2] = scanner.read<geo::Point<ld>, 2>();
    geo::Line l(p1, p2);
    auto q = scanner.read<int>();
    for (int i = 0; i < q; ++i) {
        auto p = scanner.read<geo::Point<ld>>();
        print(geo::projection(p, l));
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
