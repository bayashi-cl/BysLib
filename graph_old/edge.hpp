#pragma once
#include <iostream>

#include "../core/const.hpp"
#include "../core/stdlib.hpp"
#include "../sparse/csr.hpp"

namespace bys {
template <class WeightType = std::int64_t, class VertexType = std::size_t>
struct Edge {
    using weight_type = WeightType;
    using vertex_type = VertexType;
    vertex_type src, dest;
    weight_type weight;
    static constexpr weight_type inf = get_inf<weight_type>();

    Edge() : src(-1), dest(-1), weight(inf) {}
    Edge(vertex_type src_, vertex_type dest_, weight_type weight_ = 1) : src(src_), dest(dest_), weight(weight_) {}

    bool operator<(const Edge& other) const { return weight < other.weight; }
    friend std::ostream& operator<<(std::ostream& os, Edge const& e) {
        return os << '{' << e.src << " -> " << e.dest << ": " << e.weight << '}';
    }
};
template <class InfoType, class WeightType = std::int64_t, class VertexType = std::size_t>
struct InfoEdge : Edge<WeightType, VertexType> {
    using info_type = InfoType;
    using super = Edge<WeightType, VertexType>;
    using super::Edge;
    using typename super::vertex_type;
    using typename super::weight_type;

    info_type info;
    InfoEdge(vertex_type src_, vertex_type dest_, weight_type weight_ = 1, info_type info_ = info_type())
        : super(src_, dest_, weight_), info(info_) {}
};

template <class E = Edge<>>
struct EdgeList : public COOMatrix<E> {
    using edge_type = E;
    using vertex_type = typename edge_type::vertex_type;
    using weight_type = typename edge_type::weight_type;
    using super = COOMatrix<E>;
    using super::COOMatrix;

    void add_edge(edge_type&& edge) { super::push_back(edge.src, std::forward<edge_type>(edge)); }
    void add_edge(vertex_type src, vertex_type dest, weight_type weight = 1) { super::push_back(src, {src, dest, weight}); }
    void add_undirected_edge(vertex_type u, vertex_type v, weight_type weight = 1) {
        super::push_back(u, {u, v, weight});
        super::push_back(v, {v, u, weight});
    }
    auto adj() const { return CSRMatrix<edge_type>(*this); }
};
using EList = EdgeList<Edge<long long>>;

template <class E = Edge<>>
using AdjacencyList = CSRMatrix<E>;
using Adj = AdjacencyList<>;
}  // namespace bys
