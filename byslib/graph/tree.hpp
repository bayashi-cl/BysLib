#pragma once
#include "edge.hpp"
#include "graph.hpp"

namespace bys {
template <class E> struct Tree : std::vector<E> {
    static_assert(is_edge_v<E>, "E is not Edge");
    using super = std::vector<E>;
    using super::vector;
    using V = typename E::vertex_type;

    std::vector<E> path(V to) const {
        std::vector<E> res;
        while (super::operator[](to).src != -1) {
            auto prev = super::operator[](to);
            to = prev.src;
            res.emplace_back(prev);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
    AdjacencyList<E> adj() const {
        EdgeList<E> elist;
        for (auto&& e : *this) {
            if (e.src != -1) elist.add_edge(e);
        }
        return elist.adj();
    }
};
}  // namespace bys
