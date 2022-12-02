#pragma once
#include "../ds/union_find.hpp"
#include "graph.hpp"

namespace bys {
template <class E> auto kruskal(EdgesCOO<E> elist) {
    elist.sort();
    UnionFindTree uf(elist.size());
    EdgesCOO<E> res(elist.size());
    typename E::weight_type cost = 0;
    for (auto e : elist) {
        if (uf.unite(e.src, e.dest)) {
            cost += e.weight;
            res.add_edge(e);
        }
    }
    return std::make_pair(cost, res);
}
}  // namespace bys
