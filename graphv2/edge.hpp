#pragma once
#include "../core/stdlib.hpp"
/**
 * @file edge.hpp
 * @author bayashi_cl
 * @brief Edge
 * @todo concept
 */
namespace bys {
//! @brief 辺
struct Edge {
    std::size_t src, dest;
    ll weight;
    Edge() {}
    Edge(std::size_t src, std::size_t dest, ll weight = 1) : src(src), dest(dest), weight(weight) {}
    bool operator<(const Edge& rh) const { return weight < rh.weight; }
    operator int() const { return dest; }
    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        return os << "{" << e.src << " -> " << e.dest << ": " << e.weight << "}";
    }
};
//! @brief 隣接リスト
struct DynamicAdjacencyList {
    std::vector<std::vector<Edge>> data;
    DynamicAdjacencyList(std::size_t n) : data(n, vector<Edge>()), _n(n) {}
    std::vector<vector<Edge>>::reference operator[](std::size_t i) { return *(data.begin() + i); }
    const std::vector<vector<Edge>>::const_reference operator[](std::size_t i) const { return *(data.cbegin() + i); }
    void add_edge(const Edge& e) { data[e.src].push_back(e); }
    void add_edge(std::size_t src, std::size_t dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }
    std::size_t size() const { return _n; }

   private:
    std::size_t _n;
};
/**
 * @brief 隣接リスト
 *
 * CSR形式
 * See: https://qiita.com/Nachia/items/d420c08b333296f54526
 */
struct AdjacencyList {
    AdjacencyList(std::size_t n, std::size_t m) : _n(n), _m(m), index(n + 1), _build_flg(m == 0) { buf.reserve(m); }

    struct AdjacencyRange {
        using iterator = std::vector<Edge>::const_iterator;
        using reference = std::vector<Edge>::const_reference;
        iterator _begin, _end;
        iterator begin() const { return _begin; }
        iterator end() const { return _end; }
        reference operator[](std::size_t i) const { return *(_begin + i); }
        std::size_t size() const { return std::distance(_begin, _end); }
        bool empty() const { return size() == 0; }
    };
    AdjacencyRange operator[](std::size_t i) const {
        return AdjacencyRange{data.begin() + index[i], data.begin() + index[i + 1]};
    }

    void build() {
        std::partial_sum(index.begin(), index.end(), index.begin());
        data.resize(_m);
        for (auto&& e : buf) data[--index[e.src]] = e;
        _build_flg = true;
    }
    void add_edge(const Edge& e) {
        ++index[e.src];
        buf.emplace_back(e);
        if (buf.size() == _m) build();
    }
    void add_edge(std::size_t src, std::size_t dest, ll weight = 1) { add_edge(Edge(src, dest, weight)); }
    std::size_t size() const { return _n; }
    std::size_t n_edge() const { return _m; }
    bool build_flg() const { return _build_flg; }

   private:
    std::size_t _n, _m;
    std::vector<Edge> buf, data;
    std::vector<std::size_t> index;
    bool _build_flg;
};
}  // namespace bys
