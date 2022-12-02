#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#include "byslib/ds/union_find.hpp"
#include "byslib/template.hpp"
namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    UnionFindTree uf(n);
    for (UV : irange(q)) {
        auto [com, x, y] = scanner.read<i32, 3>();
        if (com == 0) {
            uf.unite(x, y);
        } else {
            print(uf.same(x, y) ? 1 : 0);
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
