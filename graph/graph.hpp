#pragma once

#include "edge.hpp"

namespace bys {
template <class E>
struct EdgeList : public COOMatrix<E> {
    using edge_type = E;
    using vertex_type = typename edge_type::vertex_type;
    using weight_type = typename edge_type::weight_type;
    using super = COOMatrix<E>;
    using super::COOMatrix;

    void add_edge(edge_type& edge) { super::push_back(edge.src, std::forward<edge_type>(edge)); }
    void add_edge(vertex_type src, vertex_type dest, weight_type weight = 1) { super::push_back(src, {src, dest, weight}); }
    void add_undirected_edge(vertex_type u, vertex_type v, weight_type weight = 1) {
        super::push_back(u, {u, v, weight});
        super::push_back(v, {v, u, weight});
    }
    auto adj() const { return CSRMatrix<edge_type>(*this); }
};
using EList = EdgeList<Edge<>>;

template <class E>
using AdjacencyList = CSRMatrix<E>;
using AdjList = AdjacencyList<Edge<>>;
}  // namespace bys
