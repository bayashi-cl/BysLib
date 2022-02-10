#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include "byslib/core/core.hpp"
#include "byslib/utility/range.hpp"
#include "byslib/utility/change.hpp"
#include "byslib/data/binary_indexed_tree.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    BinaryIndexedTree<ll> bit(n);
    for (UV : irange(q)) {
        auto [com, x, y] = scanner.read<int, Int1, int>();
        if (com == 0) {
            bit.add(x, y);
        } else if (com == 1) {
            print(bit.sum(x, y));
        } else {
            throw RE;
        }
    }
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
