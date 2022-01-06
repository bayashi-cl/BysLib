#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#include "../../core/core.hpp"
#include "../../geometry/point.hpp"

namespace bys {
void Solver::solve() {
    auto [p0, p1] = input<geo::Point<ld>, 2>();
    auto q = input<int>();
    for (int i = 0; i < q; ++i) {
        auto p2 = input<geo::Point<ld>>();
        auto dir = geo::iSP(p0, p1, p2);
        if (dir == geo::Turn::CCW) {
            print("COUNTER_CLOCKWISE");
        } else if (dir == geo::Turn::CW) {
            print("CLOCKWISE");
        } else if (dir == geo::Turn::Back) {
            print("ONLINE_BACK");
        } else if (dir == geo::Turn::Front) {
            print("ONLINE_FRONT");
        } else if (dir == geo::Turn::Middle) {
            print("ON_SEGMENT");
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
