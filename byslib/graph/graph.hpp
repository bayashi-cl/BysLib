#pragma once

#include "edge.hpp"

namespace bys {
enum class Directed : bool { undirected, directed };
constexpr auto directed = Directed::directed;
constexpr auto undirected = Directed::undirected;

template <class E> class EdgesCSR;

template <class E> class EdgesCOO {
    COOMatrix<E> coo;

  public:
    using edge_type = E;
    using vertex_type = typename edge_type::vertex_type;
    using weight_type = typename edge_type::weight_type;
    Directed directed_kind;

    template <class Itr> class EdgeIterator {
        Itr coo_itr;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = edge_type;
        using reference = edge_type&;
        using pointer = edge_type*;
        using iterator_category = std::bidirectional_iterator_tag;

        EdgeIterator(const Itr& itr) : coo_itr(itr) {}
        auto operator*() { return std::get<2>(*coo_itr); }
        auto operator*() const { return std::get<2>(*coo_itr); }

        EdgeIterator& operator++() noexcept {
            ++coo_itr;
            return *this;
        }
        EdgeIterator& operator--() noexcept {
            --coo_itr;
            return *this;
        }
        bool operator==(EdgeIterator const& other) const { return coo_itr == other.coo_itr; }
        bool operator!=(EdgeIterator const& other) const { return coo_itr != other.coo_itr; }
    };

    EdgesCOO(i32 n, Directed dir) : coo(n, -1), directed_kind(dir) {}
    std::size_t size() const { return coo.shape.first; }
    std::ptrdiff_t ssize() const { return coo.shape.first; }
    std::size_t n_edges() const { return coo.nonzero(); }
    auto begin() const { return EdgeIterator(coo.begin()); }
    auto end() const { return EdgeIterator(coo.end()); }
    void sort() { coo.sort(); }

    void add(edge_type& e) { coo.push_back(e.src, e); }
    void add_edge(vertex_type src, vertex_type dest, weight_type weight = 1) {
        coo.push_back(src, {src, dest, weight});
        if (directed_kind == Directed::undirected) coo.push_back(dest, {dest, src, weight});
    }

    auto build() const { return EdgesCSR<edge_type>(coo, directed_kind); }
};
template <class E> class EdgesCSR : public CSRMatrix<E> {
  public:
    using edge_type = E;
    using vertex_type = typename edge_type::vertex_type;
    using weight_type = typename edge_type::weight_type;
    Directed directed_kind;
    EdgesCSR(const COOMatrix<E>& coo, Directed dir) : CSRMatrix<E>::CSRMatrix(coo), directed_kind(dir) {}
};

using EdgeList = EdgesCOO<Edge<>>;
using AdjList = EdgesCSR<Edge<>>;
}  // namespace bys
