#pragma once
#include "../core/stdlib.hpp"
#include "../data/union_find.hpp"
#include "edge.hpp"

namespace bys {
struct Kruskal {
    int n_node;
    EdgeList mst;
    ll cost = 0;
    Kruskal(EdgeList& edges, int n_node, int n_tree = 1) : n_node(n_node) {
        sort(edges.begin(), edges.end());
        search(edges, n_tree);
    }
    void search(const EdgeList& edges, int n_tree) {
        UnionFindTree uft(n_node);
        int sz = n_node;
        for (auto&& e : edges) {
            if (uft.same(e.from, e.to)) continue;
            uft.unite(e.from, e.to);
            mst.push_back(e);
            cost += e.cost;
            --sz;
            if (sz == n_tree) return;
        }
    }
};
}  // namespace bys
