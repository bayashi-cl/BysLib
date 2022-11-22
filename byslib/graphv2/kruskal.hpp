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
std::pair<ll, Elist> kruskal(const Elist& elist, int n_node, int n_tree = 1) {
    assert(std::is_sorted(elist.begin(), elist.end()));
    UnionFindTree uft(n_node);
    ll cost = 0;
    Elist mst;
    for (auto&& e : elist) {
        if (uft.unite(e.src, e.dest)) {
            cost += e.weight;
            mst.push_back(e);
            if (--n_node == n_tree) break;
        }
    }
    return {cost, mst};
}
}  // namespace bys
