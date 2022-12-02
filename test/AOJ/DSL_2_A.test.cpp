#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../byslib/algebra/monoid.hpp"
#include "../../byslib/ds/segment_tree.hpp"
#include "../../byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<int, 2>();
    SegmentTree<Min<int>> seg(n);
    for (UV : irange(q)) {
        auto [t, x, y] = scanner.read<int, 3>();
        if (t == 0) {
            seg.update(x, y);

        } else {
            print(seg.fold(x, y + 1));
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
