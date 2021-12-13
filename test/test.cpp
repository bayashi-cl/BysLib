// #include "byslib/geometry/line.hpp"
// #include "byslib/integer.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
void Solver::solve() { print(IT); }
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(3);
    return 0;
}
