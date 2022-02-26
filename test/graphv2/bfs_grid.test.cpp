#define PROBLEM "https://atcoder.jp/contests/abc232/tasks/abc232_d"
#include "../../core/core.hpp"
#include "../../graphv2/breadth_first_search.hpp"
#include "../../utility/change.hpp"
#include "../../utility/grid.hpp"
#include "../../utility/range.hpp"

namespace bys {
void Solver::solve() {
    auto [h, w] = scanner.read<int, 2>();
    auto c = scanner.readvec<string>(h);
    Grid grid(h, w);

    DynamicAdjacencyList graph(grid.area());
    for (int i : Range(h)) {
        for (int j : Range(w)) {
            if (c[i][j] == '#') continue;
            for (auto [ni, nj] : grid.next2(i, j)) {
                if (c[ni][nj] == '.') graph.add_edge(grid.index(i, j), grid.index(ni, nj));
            }
        }
    }
    auto res = breadth_first_search(graph, 0);
    ll ans = 0;
    for (const auto d : res.cost) {
        if (d != LINF) chmax(ans, d);
    }
    print(ans + 1);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::scanner.read<int>() */);
    return 0;
}
