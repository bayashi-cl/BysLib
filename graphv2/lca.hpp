#pragma once
/**
 * @file lca.hpp
 * @author bayashi_cl
 * @brief Lowest Common Ancestor
 *
 * 最近共通祖先
 */
#include "../algebra/monoid.hpp"
#include "../data/sparse_table.hpp"
#include "../utility/fixpoint.hpp"
#include "edge.hpp"
namespace bys {
/**
 * @brief 最近共通祖先
 *
 * Sparse TableによるEulerTour + RmQ
 * 構築   O(N logN)
 * クエリ O(1)
 */
class LowestCommonAncestor {
    struct Vertex {
        int id, depath;
        bool operator<(const Vertex& rh) const { return depath < rh.depath; }
    };
    std::size_t n;
    SparseTable<Min<Vertex>> st;
    std::vector<int> pos;

   public:
    template <class Adj>
    LowestCommonAncestor(const Adj& graph, int root) : n(graph.size()), pos(n) {
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
    int lca(std::size_t a, std::size_t b) {
        assert(a < n);
        assert(b < n);
        if (pos[a] > pos[b]) std::swap(a, b);
        return st.query(pos[a], pos[b]).id;
    }
};
}  // namespace bys
