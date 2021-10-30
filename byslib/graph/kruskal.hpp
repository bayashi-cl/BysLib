#pragma once
#include <atcoder/dsu>

#include "byslib/graph/edge.hpp"
#include "byslib/template/bys.hpp"

namespace bys {
struct Kruskal {
    int n_node;
    vector<Edge> mst;
    ll cost = 0;
    Kruskal(vector<Edge>& edges, int n_tree = 1) : n_node(edges.size()) {
        sort(edges.begin(), edges.end());
        search(edges, n_tree);
    }
    void search(const vector<Edge>& edges, int n_tree) {
        atcoder::dsu uft(n_node);
        int sz = n_node;
        for (auto&& e : edges) {
            if (uft.same(e.from, e.to)) continue;
            uft.merge(e.from, e.to);
            mst.push_back(e);
            cost += e.cost;
            --sz;
            if (sz == n_tree) return;
        }
    }
};
}  // namespace bys
