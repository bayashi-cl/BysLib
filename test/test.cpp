#include "byslib/geometry/line.hpp"
// #include "byslib/integer.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
void Solver::solve() {
    print("aa");
    print.send("ss", 314);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
