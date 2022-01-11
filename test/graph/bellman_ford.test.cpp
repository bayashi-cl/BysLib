#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"
#include "../../core/core.hpp"
#include "../../graph/bellman_ford.hpp"
#include "../../graph/reader.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e, r] = input<int, 3>();
    auto graph = read_elist_uvc(e, 0);
    BellmanFord bf(graph, v, r);
    if (bf.negative_cycle) EXIT("NEGATIVE CYCLE");
    for (auto&& e : bf.cost) print(e == LINF ? "INF" : std::to_string(e));
}
}  // namespace bys
int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
