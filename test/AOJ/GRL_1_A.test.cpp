#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
#include "byslib/graph/dijkstra.hpp"
#include "byslib/template.hpp"

namespace bys {
void Solver::solve() {
    auto [v, e, r] = scanner.read<i32, 3>();

    EdgeList edges(v, directed);
    for (UV : irange(e)) {
        auto [s, t, d] = scanner.read<i32, i32, i64>();
        edges.add_edge(s, t, d);
    }
    auto graph = edges.build();
    auto res = dijkstra(graph, r);
    for (auto ans : res) {
        if (is_inf(ans)) {
            print("INF");
        } else {
            print(ans);
        }
    }
}
}  // namespace bys

int main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }
