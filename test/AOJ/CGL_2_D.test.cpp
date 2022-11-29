#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 1e-8
#include "byslib/geometry/line.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto q = scanner.read<i32>();
    for (int i = 0; i < q; ++i) {
        auto [p0, p1, p2, p3] = scanner.read<geo::Point<f128>, 4>();
        geo::Segment s1(p0, p1), s2(p2, p3);
        print(geo::distance(s1, s2));
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
