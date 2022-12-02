#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#define ERROR 1e-8

#include "../../byslib/geometry/polygon.hpp"
#include "../../byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto n = scanner.read<int>();
    geo::Polygon p(scanner.readvec<geo::Point<f128>>(n));
    print(p.area());
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
