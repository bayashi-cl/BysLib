#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_A"
#include "byslib/ds/imos.hpp"
#include "byslib/template.hpp"
namespace bys {
void Solver::solve() {
    auto [n, t] = scanner.read<int, 2>();
    Imos<i32> imos(t + 1);

    for (UV : irange(n)) {
        auto [l, r] = scanner.read<i32, 2>();
        imos.add(l, r, 1);
    }
    auto res = imos.build();
    print(*std::max_element(res.begin(), res.end()));
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
