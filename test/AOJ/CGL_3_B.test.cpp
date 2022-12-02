#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"
#include "../../byslib/geometry/polygon.hpp"
#include "../../byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto n = scanner.read<int>();
    geo::Polygon p(scanner.readvec<geo::Point<i64>>(n));
    print(p.is_convex() ? 1 : 0);
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
