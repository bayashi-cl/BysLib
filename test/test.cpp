#include "byslib/geometry/line.hpp"
// #include "byslib/integer.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
void Solver::solve() {
    geo::Point<double> a(0, 0), b(3, 0), c(5, 5), d(5, -2);

    geo::Segment s1(a, b), s2(c, d);
    cout << std::boolalpha;
    // print(geo::is_cross(s1, s2));
    print(geo::cross_point(s1, s2));
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
