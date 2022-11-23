#pragma once
#include "../data/union_find.hpp"
#include "graph.hpp"

namespace bys {
template <class E> auto kruskal(EdgeList<E> elist) {
    elist.sort();
    UnionFindTree uf(elist.size());
    EdgeList<E> res(elist.size());
    typename E::weight_type cost = 0;
    for (auto v : elist) {
        auto e = std::get<2>(v);
        if (uf.unite(e.src, e.dest)) {
            cost += e.weight;
            res.add_edge(e);
        }
    }
    return std::make_pair(cost, res);
}
}  // namespace bys
