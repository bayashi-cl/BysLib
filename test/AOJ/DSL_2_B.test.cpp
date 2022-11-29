#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "byslib/ds/binary_indexed_tree.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    FenwickTree<i32> fw(n);
    for (UV : irange(q)) {
        auto com = scanner.read<i32>();
        if (com == 1) {
            auto [i, x] = scanner.read<i32_1, 2>();
            fw.set(i, fw[i] + x);
        } else {
            auto [l, r] = scanner.read<i32_1, i32>();
            print(fw.fold(l, r));
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
