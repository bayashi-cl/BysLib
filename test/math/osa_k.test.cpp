#define PROBLEM "https://atcoder.jp/contests/abc215/tasks/abc215_d"
#include "../../core/core.hpp"
#include "../../math/osa_k.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [n, m] = scanner.read<int, 2>();
    auto a = scanner.read<int>(n);
    Osa_K osa_k(100000);
    set<int> forbid;
    for (auto&& ai : a) {
        for (auto&& [k, v] : osa_k.factorize(ai)) forbid.insert(k);
    }
    vector<int> ans;
    for (int i : Range(1, m + 1)) {
        bool flg = true;
        for (auto&& [k, v] : osa_k.factorize(i)) {
            if (forbid.find(k) != forbid.end()) {
                flg = false;
                break;
            }
        }
        if (flg) ans.push_back(i);
    }
    print(ans.size());
    for (auto&& e : ans) print(e);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
