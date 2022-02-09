#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"
#include "../../core/core.hpp"
#include "../../draft/warshall_floyd.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e] = scanner.read<int, 2>();

    vector<Edge> graph;
    graph.reserve(e);
    for (int i = 0; i < e; ++i) {
        auto [s, t, d] = scanner.read<uint, uint, ll>();
        graph.push_back({s, t, d});
    }
    auto res = warshall_floyd(graph, v);
    for (int i : Range(v)) {
        if (res.cost[i][i] < 0) EXIT("NEGATIVE CYCLE");
    }
    auto dump = [&](ll x) -> string { return x == LINF ? "INF" : std::to_string(x); };

    for (auto&& e : res.cost) {
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
