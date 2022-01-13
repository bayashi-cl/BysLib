#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"
#include "../../core/core.hpp"
#include "../../graph/warshall_floyd.hpp"
#include "../../graph/reader.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e] = scanner.read<int, 2>();
    auto graph = read_elist_uvc(e, 0);
    WarshallFloyd wf(graph, v);
    for (int i : Range(v)) {
        if (wf.cost[i][i] < 0) EXIT("NEGATIVE CYCLE");
    }
    auto dump = [&](ll x) -> string { return x >= (ll)INF * 100 ? "INF" : std::to_string(x); };

    for (auto&& e : wf.cost) {
        std::for_each(e.begin(), std::prev(e.end()), [&](ll x) { cout << dump(x) << " "; });
        cout << dump(e.back()) << endl;
    }
}
}  // namespace bys
int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
