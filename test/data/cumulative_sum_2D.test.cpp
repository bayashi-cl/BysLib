#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_B"
#include "../../core/core.hpp"
#include "../../data/cumulative_sum.hpp"
#include "../../utility/change.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto n = scanner.read<int>();
    CumulativeSum2D<int> cs(1002, 1002);
    for (UV : irange(n)) {
        auto [x1, y1, x2, y2] = scanner.read<int, 4>();
        cs.add(x1, y1, 1);
        cs.add(x1, y2, -1);
        cs.add(x2, y1, -1);
        cs.add(x2, y2, 1);
    }
    cs.construct();
    int ans = 0;
    for (int i : irange(1001)) {
        for (int j : irange(1001)) {
            chmax(ans, cs.get(i, j));
        }
    }
    print(ans);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
