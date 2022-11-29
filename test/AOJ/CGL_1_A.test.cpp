#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 1e-8
#include "byslib/geometry/line.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [p1, p2] = scanner.read<geo::Point<f128>, 2>();
    geo::Line l(p1, p2);
    auto q = scanner.read<i32>();
    for (int i = 0; i < q; ++i) {
        auto p = scanner.read<geo::Point<f128>>();
        print(geo::projection(p, l));
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
