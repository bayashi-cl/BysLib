---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: data/sparse_table.hpp
    title: data/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/edge.hpp
    title: graphv2/edge.hpp
  - icon: ':heavy_check_mark:'
    path: math/algebra.hpp
    title: math/algebra.hpp
  - icon: ':heavy_check_mark:'
    path: utility/fixpoint.hpp
    title: utility/fixpoint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cmath>\n#include <complex>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\nnamespace bys {\nstruct Edge {\n    std::size_t src, dest;\n    ll weight;\n\
    \    Edge() {}\n    Edge(std::size_t src, std::size_t dest, ll weight = 1) : src(src),\
    \ dest(dest), weight(weight) {}\n    bool operator<(const Edge& rh) const { return\
    \ weight < rh.weight; }\n    operator int() const { return dest; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Edge& e) {\n        return\
    \ os << \"{\" << e.src << \" -> \" << e.dest << \": \" << e.weight << \"}\";\n\
    \    }\n};\nstruct DynamicAdjacencyList {\n    std::vector<std::vector<Edge>>\
    \ data;\n    DynamicAdjacencyList(std::size_t n) : data(n, vector<Edge>()), _n(n)\
    \ {}\n    std::vector<vector<Edge>>::reference operator[](std::size_t i) { return\
    \ *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
    \ operator[](std::size_t i) const { return *(data.cbegin() + i); }\n    void add_edge(const\
    \ Edge& e) { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\nstruct\
    \ AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m) : _n(n), _m(m),\
    \ index(n + 1), _build_flg(m == 0) { buf.reserve(m); }\n\n    struct AdjacencyRange\
    \ {\n        using iterator = std::vector<Edge>::const_iterator;\n        using\
    \ reference = std::vector<Edge>::const_reference;\n        iterator _begin, _end;\n\
    \        iterator begin() const { return _begin; }\n        iterator end() const\
    \ { return _end; }\n        reference operator[](std::size_t i) const { return\
    \ *(_begin + i); }\n        std::size_t size() const { return std::distance(_begin,\
    \ _end); }\n        bool empty() const { return size() == 0; }\n    };\n    AdjacencyRange\
    \ operator[](std::size_t i) const {\n        return AdjacencyRange{data.begin()\
    \ + index[i], data.begin() + index[i + 1]};\n    }\n\n    void build() {\n   \
    \     std::partial_sum(index.begin(), index.end(), index.begin());\n        data.resize(_m);\n\
    \        for (auto&& e : buf) data[--index[e.src]] = e;\n        _build_flg =\
    \ true;\n    }\n    void add_edge(const Edge& e) {\n        ++index[e.src];\n\
    \        buf.emplace_back(e);\n        if (buf.size() == _m) build();\n    }\n\
    \    void add_edge(std::size_t src, std::size_t dest, ll weight = 1) { add_edge(Edge(src,\
    \ dest, weight)); }\n    std::size_t size() const { return _n; }\n    std::size_t\
    \ n_edge() const { return _m; }\n    bool build_flg() const { return _build_flg;\
    \ }\n\n   private:\n    std::size_t _n, _m;\n    std::vector<Edge> buf, data;\n\
    \    std::vector<std::size_t> index;\n    bool _build_flg;\n};\n}  // namespace\
    \ bys\nnamespace bys {\ntemplate <class A>\nclass SparseTable {\n    using T =\
    \ typename A::value_type;\n    int n;\n    std::vector<int> lookup;\n    std::vector<std::vector<T>>\
    \ table;\n\n   public:\n    SparseTable() {}\n    SparseTable(const std::vector<T>&\
    \ v) { build(v); }\n\n    void build(const std::vector<T>& v) {\n        n = v.size();\n\
    \        lookup.resize(n + 1);\n\n        for (int i = 2; i < n + 1; ++i) lookup[i]\
    \ = lookup[i >> 1] + 1;\n        int max_k = lookup.back();\n        table.assign(max_k\
    \ + 1, std::vector<T>(n));\n        std::copy(v.begin(), v.end(), table[0].begin());\n\
    \        for (int i = 1; i <= max_k; ++i) {\n            for (int j = 0; j <=\
    \ n - (1 << i); ++j) {\n                table[i][j] = A::op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= n);\n        int w = r -\
    \ l;\n        return A::op(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n#include <utility>\nnamespace bys {\ntemplate\
    \ <typename F>\nstruct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\ntemplate <typename F>\ninline FixPoint<std::decay_t<F>> fix(F&& f)\
    \ {\n    return std::forward<std::decay_t<F>>(f);\n}\n}  // namespace bys\nnamespace\
    \ bys {\ntemplate <class T>\nstruct Add {\n    using value_type = T;\n    static\
    \ constexpr T op(T a, T b) { return a + b; }\n    static constexpr T id{0};\n\
    };\ntemplate <class T>\nstruct Min {\n    using value_type = T;\n    static constexpr\
    \ T op(T a, T b) { return std::min(a, b); }\n    static constexpr T id{std::numeric_limits<T>::max()};\n\
    };\ntemplate <class T>\nstruct Max {\n    using value_type = T;\n    static constexpr\
    \ T op(T a, T b) { return std::max(a, b); }\n    static constexpr T id{std::numeric_limits<T>::min()};\n\
    };\n}  // namespace bys\n\nnamespace bys {\nclass LowestCommonAncestor {\n   \
    \ struct Vertex {\n        int id, depath;\n        bool operator<(const Vertex&\
    \ rh) const { return depath < rh.depath; }\n    };\n    std::size_t n;\n    SparseTable<Min<Vertex>>\
    \ st;\n    std::vector<int> pos;\n\n   public:\n    LowestCommonAncestor(const\
    \ AdjacencyList& graph, int root) : n(graph.size()), pos(n) {\n        std::vector<Vertex>\
    \ euler_tour;\n        euler_tour.reserve(2 * n - 1);\n        FixPoint([&](auto&&\
    \ self, int now, int prev, int deapth) -> void {\n            pos[now] = euler_tour.size();\n\
    \            euler_tour.push_back({now, deapth});\n\n            for (auto&& nxt\
    \ : graph[now]) {\n                if (int(nxt.dest) == prev) continue;\n    \
    \            self(nxt.dest, now, deapth + 1);\n                euler_tour.push_back({now,\
    \ deapth});\n            }\n        })(root, -1, 0);\n        st.build(euler_tour);\n\
    \    }\n    int lca(std::size_t a, std::size_t b) {\n        assert(a < n);\n\
    \        assert(b < n);\n        if (pos[a] > pos[b]) std::swap(a, b);\n     \
    \   return st.query(pos[a], pos[b]).id;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"edge.hpp\"\n#include \"../data/sparse_table.hpp\"\
    \n#include \"../utility/fixpoint.hpp\"\n#include \"../math/algebra.hpp\"\n\nnamespace\
    \ bys {\nclass LowestCommonAncestor {\n    struct Vertex {\n        int id, depath;\n\
    \        bool operator<(const Vertex& rh) const { return depath < rh.depath; }\n\
    \    };\n    std::size_t n;\n    SparseTable<Min<Vertex>> st;\n    std::vector<int>\
    \ pos;\n\n   public:\n    LowestCommonAncestor(const AdjacencyList& graph, int\
    \ root) : n(graph.size()), pos(n) {\n        std::vector<Vertex> euler_tour;\n\
    \        euler_tour.reserve(2 * n - 1);\n        FixPoint([&](auto&& self, int\
    \ now, int prev, int deapth) -> void {\n            pos[now] = euler_tour.size();\n\
    \            euler_tour.push_back({now, deapth});\n\n            for (auto&& nxt\
    \ : graph[now]) {\n                if (int(nxt.dest) == prev) continue;\n    \
    \            self(nxt.dest, now, deapth + 1);\n                euler_tour.push_back({now,\
    \ deapth});\n            }\n        })(root, -1, 0);\n        st.build(euler_tour);\n\
    \    }\n    int lca(std::size_t a, std::size_t b) {\n        assert(a < n);\n\
    \        assert(b < n);\n        if (pos[a] > pos[b]) std::swap(a, b);\n     \
    \   return st.query(pos[a], pos[b]).id;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - graphv2/edge.hpp
  - core/stdlib.hpp
  - data/sparse_table.hpp
  - utility/fixpoint.hpp
  - math/algebra.hpp
  isVerificationFile: false
  path: graphv2/lca.hpp
  requiredBy: []
  timestamp: '2022-02-26 15:15:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/lca.test.cpp
documentation_of: graphv2/lca.hpp
layout: document
redirect_from:
- /library/graphv2/lca.hpp
- /library/graphv2/lca.hpp.html
title: graphv2/lca.hpp
---
