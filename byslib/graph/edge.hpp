#pragma once
#include <cstddef>
#include <iostream>

#include "../core/const.hpp"
#include "../sparse/csr.hpp"

namespace bys {
struct EdgeBase {};

template <class WeightType = long long, class VertexType = std::size_t> struct Edge : EdgeBase {
    using weight_type = WeightType;
    using vertex_type = VertexType;
    vertex_type src, dest;
    weight_type weight;

    Edge() : src(-1), dest(-1), weight(get_inf<weight_type>()) {}
    Edge(vertex_type src_, vertex_type dest_, weight_type weight_ = 1)
        : src(src_), dest(dest_), weight(weight_) {}

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
    InfoEdge(vertex_type src_,
             vertex_type dest_,
             weight_type weight_ = 1,
             info_type info_ = info_type())
        : super(src_, dest_, weight_), info(info_) {}
};

template <class E> constexpr bool is_edge_v = std::is_base_of_v<EdgeBase, E>;
}  // namespace bys
