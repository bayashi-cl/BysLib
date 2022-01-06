#define PROBLEM "https://atcoder.jp/contests/abc232/tasks/abc232_d"
#include "core/core.hpp"
#include "utility/grid.hpp"
#include "graph/breadth_first.hpp"

namespace bys {
void Solver::solve() {
    auto [h, w] = input<int, 2>();
    Grid grid(h, w);
    auto c = input<string>(h);

    Adj graph(grid.area());
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (c[i][j] == '#') continue;
            if (grid.contain(i + 1, j) && c[i + 1][j] == '.') {
                graph[grid.index(i, j)].push_back({grid.index(i + 1, j)});
            }
            if (grid.contain(i, j + 1) && c[i][j + 1] == '.') {
                graph[grid.index(i, j)].push_back({grid.index(i, j + 1)});
            }
        }
    }
    BreadthFirstSearch bfs(graph, 0);
    print(*std::max_element(bfs.cost.begin(), bfs.cost.end()) + 1);
}
}  // namespace bys

int main() {
    bys::Solver solver;
    solver.solve(/* bys::input<int>() */);
    return 0;
}
