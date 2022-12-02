#pragma once
/**
 * @file lca.hpp
 * @brief Lowest Common Ancestor
 *
 * 最近共通祖先
 */
#include "../algebra/monoid.hpp"
#include "../core/int_alias.hpp"
#include "../ds/sparse_table.hpp"
#include "../extension/fixpoint.hpp"
#include "graph.hpp"
namespace bys {
/**
 * @brief 最近共通祖先
 *
 * Sparse TableによるEulerTour + RmQ
 * 構築   O(N logN)
 * クエリ O(1)
 */
template <class E> class LowestCommonAncestor {
    struct Vertex {
        i32 id, depath;
        bool operator<(const Vertex& rh) const { return depath < rh.depath; }
    };
    i32 n;
    SparseTable<Min<Vertex>> st;
    std::vector<i32> pos;

  public:
    LowestCommonAncestor(AdjacencyList<E> const& graph, i32 root) : n(graph.size()), pos(n) {
        std::vector<Vertex> euler_tour;
        euler_tour.reserve(2 * n - 1);
        FixPoint([&](auto&& self, i32 now, i32 prev, i32 deapth) -> void {
            pos[now] = euler_tour.size();
            euler_tour.push_back({now, deapth});

            for (auto&& nxt : graph[now]) {
                if (i32(nxt.dest) == prev) continue;
                self(nxt.dest, now, deapth + 1);
                euler_tour.push_back({now, deapth});
            }
        })(root, -1, 0);
        st.build(euler_tour);
    }
    i32 lca(i32 a, i32 b) {
        assert(a < n);
        assert(b < n);
        if (a == b) return a;
        if (pos[a] > pos[b]) std::swap(a, b);
        return st.query(pos[a], pos[b]).id;
    }
};
}  // namespace bys
