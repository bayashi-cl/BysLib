#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#include "byslib/geometry/point.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [p0, p1] = scanner.read<geo::Point<f128>, 2>();
    auto q = scanner.read<int>();
    for (int i = 0; i < q; ++i) {
        auto p2 = scanner.read<geo::Point<f128>>();
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

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
