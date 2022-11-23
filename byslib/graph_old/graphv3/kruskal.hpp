#pragma once
#include "../core/stdlib.hpp"
#include "../data/union_find.hpp"
#include "edge.hpp"
/**
 * @file kruskal.hpp
 * @brief Kruskal
 */
namespace bys {
using Elist = std::vector<Edge>;
/**
 * @brief クラスカル法
 * @param elist ソートされた辺リスト
 * @param n_node 頂点数
 * @param n_tree 最終的な連結成分の個数(optional)
 * @return std::pair<ll, Elist> {コスト, 最小全域木}
 */
std::pair<ll, COOMatrix<Edge>> kruskal(const COOMatrix<Edge>& edges, int n_tree = 1) {
    assert(std::is_sorted(edges.begin(), edges.end()));
    int n = edges.size();
    UnionFindTree uft(n);
    ll cost = 0;
    COOMatrix<Edge> mst(n);
    for (auto&& [src, id, e] : edges) {
        if (uft.unite(src, e.dest)) {
            cost += e.weight;
            mst.push_back(src, e);
            if (--n == n_tree) break;
        }
    }
    return {cost, mst};
}
}  // namespace bys
