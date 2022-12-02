#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../byslib/ds/union_find.hpp"
#include "../../byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [n, q] = scanner.read<i32, 2>();
    auto que = scanner.readvec<array<i32, 3>>(q);
    UnionFindTree uft(n);
    for (auto&& [t, u, v] : que) {
        if (t == 0) {
            uft.unite(u, v);
        } else {
            print(uft.same(u, v) ? 1 : 0);
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
