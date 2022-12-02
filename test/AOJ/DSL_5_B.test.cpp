#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_B"
#include "byslib/ds/imos.hpp"
#include "byslib/template.hpp"
namespace bys {
void Solver::solve() {
    auto n = scanner.read<i32>();
    Imos2D<i32> imos(1001, 1001);

    for (UV : irange(n)) {
        auto [x1, y1, x2, y2] = scanner.read<i32, 4>();
        imos.add(x1, y1, x2 - 1, y2 - 1, 1);
    }
    auto res = imos.build();

    i32 ans = 0;
    for (auto&& r : res) chmax(ans, *std::max_element(r.begin(), r.end()));

    print(ans);
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
