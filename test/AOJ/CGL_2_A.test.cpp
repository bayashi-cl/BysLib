#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include "byslib/geometry/line.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto q = scanner.read<int>();
    for (int i = 0; i < q; ++i) {
        auto [p0, p1, p2, p3] = scanner.read<geo::Point<i64>, 4>();
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

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
