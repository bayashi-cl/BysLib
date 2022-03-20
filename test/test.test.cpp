#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../core/core.hpp"
#include "../graph/edge.hpp"

namespace bys {
void Solver::solve() {
    Edge e(1, 2, 3);
    DEBUG(e);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve();
    bys::print("Hello World");
    return 0;
}
