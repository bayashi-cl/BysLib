#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"
#include "byslib/graph/warshall_floyd.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e] = scanner.read<i32, 2>();

    EdgeList edges(v, directed);
    for (UV : irange(e)) {
        auto [s, t, d] = scanner.read<i32, i32, i64>();
        edges.add_edge(s, t, d);
    }
    auto res = warshall_floyd(edges);
    for (auto&& i : irange(v)) {
        if (res[i][i] < 0) EXIT("NEGATIVE CYCLE");
    }

    for (auto&& ri : res) {
        auto top = true;

        for (auto&& ans : ri) {
            if (top) {
                top = false;
            } else {
                cout << ' ';
            }
            if (is_inf(ans)) {
                cout << "INF";
            } else {
                cout << ans;
            }
        }
        cout << '\n';
    }
}
}  // namespace bys
// NEGATIVE_CYCLE
// NEGATIVE_CYCLE
int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
