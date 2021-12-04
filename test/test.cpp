// #include "byslib/geometry/line.hpp"
#include "byslib/integer.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
void Solver::solve() {
    Osa_K osa_k(36);
    // print(osa_k.divisor(1));
    // print(osa_k.divisor(2));
    // print(osa_k.divisor(12));
    // print(osa_k.divisor(17));
    print(osa_k.divisor(36));
    print(make_divisor(36));
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
