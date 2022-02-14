#pragma once
#include "edge.hpp"
#include "deapth_first_search.hpp"
#include "../data/sparse_table.hpp"
#include "../utility/fixpoint.hpp"
#include "../math/algebra.hpp"

namespace bys {
class LowestCommonAncestor {
    struct Vertex {
        int id, depath;
        bool operator<(const Vertex& rh) const { return depath < rh.depath; }
    };
    std::size_t n;
    SparseTable<Min<Vertex>> st;
    std::vector<int> pos;

   public:
    LowestCommonAncestor(const AdjacencyList& graph, int root) : n(graph.size()), pos(n) {
        std::vector<Vertex> euler_tour;
        euler_tour.reserve(2 * n - 1);
        FixPoint([&](auto&& self, int now, int prev, int deapth) -> void {
            pos[now] = euler_tour.size();
            euler_tour.push_back({now, deapth});

            for (auto&& nxt : graph[now]) {
                if (int(nxt.dest) == prev) continue;
                self(nxt.dest, now, deapth + 1);
                euler_tour.push_back({now, deapth});
            }
        })(root, -1, 0);
        st.build(euler_tour);
    }
    int lca(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        if (pos[a] > pos[b]) std::swap(a, b);
        return st.query(pos[a], pos[b]).id;
    }
};
}  // namespace bys
