---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: data/sparse_table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: graphv2/edge.hpp
    title: Edge
  - icon: ':x:'
    path: utility/fixpoint.hpp
    title: FixPoint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Lowest Common Ancestor
    links: []
  bundledCode: "/**\n * @file lca.hpp\n * @brief Lowest Common Ancestor\n *\n * \u6700\
    \u8FD1\u5171\u901A\u7956\u5148\n */\n#include <optional>\n#include <utility>\n\
    /**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n\
    \ */\nnamespace bys {\ntemplate <class T>\nstruct Magma {\n    using set_type\
    \ = T;\n    static constexpr set_type operation(set_type a, set_type b);\n   \
    \ static constexpr bool commutative{false};\n};\ntemplate <class T>\nstruct Add\
    \ : Magma<T> {\n    using typename Magma<T>::set_type;\n    static constexpr set_type\
    \ operation(set_type a, set_type b) { return a + b; }\n    static constexpr set_type\
    \ identity{0};\n    static constexpr bool commutative{true};\n};\ntemplate <class\
    \ T>\nstruct Min : Magma<T> {\n    using typename Magma<T>::set_type;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return std::min(a, b);\
    \ }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T>\nstruct Affine : Magma<T> {\n    using set_type = std::pair<T, T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\n}  // namespace bys\n/**\n * @file stdlib.hpp\n * @brief\
    \ STL Template\n */\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\nnamespace bys {\nusing std::array,\
    \ std::vector, std::string, std::set, std::map, std::pair;\nusing std::cin, std::cout,\
    \ std::endl;\nusing std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\
    \n// alias\nusing ll = long long int;\nusing ld = long double;\nusing Pa = pair<int,\
    \ int>;\nusing Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class\
    \ T>\nusing uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing\
    \ umap = std::unordered_map<S, T>;\n}  // namespace bys\n/**\n * @file sparse_table.hpp\n\
    \ * @brief Sparse Table\n */\nnamespace bys {\n/**\n * @brief Sparse Table\n *\n\
    \ * \u69CB\u7BC9: O(NlogN)\n * \u30AF\u30A8\u30EA: O(1)\n * See: https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band>\nclass SparseTable {\n    using\
    \ T = typename Band::set_type;\n    int n;\n    std::vector<int> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n   public:\n    SparseTable() {}\n   \
    \ SparseTable(const std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>&\
    \ v) {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (int\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        int max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (int i = 1; i\
    \ <= max_k; ++i) {\n            for (int j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int\
    \ r) {\n        assert(0 <= l && l < r && r <= n);\n        int w = r - l;\n \
    \       return Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 <<\
    \ lookup[w])]);\n    }\n};\n}  // namespace bys\n/**\n * @file fixpoint.hpp\n\
    \ * @brief FixPoint\n */\nnamespace bys {\n/**\n * @brief \u30E9\u30E0\u30C0\u518D\
    \u5E30\n *\n * See: https://koturn.hatenablog.com/entry/2018/06/10/060000\n */\n\
    template <typename F>\nstruct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n}  // namespace bys\n/**\n * @file edge.hpp\n * @brief Edge\n * @todo\
    \ concept\n */\nnamespace bys {\n//! @brief \u8FBA\nstruct Edge {\n    std::size_t\
    \ src, dest;\n    ll weight;\n    Edge() {}\n    Edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) : src(src), dest(dest), weight(weight) {}\n    bool operator<(const\
    \ Edge& rh) const { return weight < rh.weight; }\n    operator int() const { return\
    \ dest; }\n    friend std::ostream& operator<<(std::ostream& os, const Edge& e)\
    \ {\n        return os << \"{\" << e.src << \" -> \" << e.dest << \": \" << e.weight\
    \ << \"}\";\n    }\n};\n//! @brief \u96A3\u63A5\u30EA\u30B9\u30C8\nstruct DynamicAdjacencyList\
    \ {\n    std::vector<std::vector<Edge>> data;\n    DynamicAdjacencyList(std::size_t\
    \ n) : data(n, vector<Edge>()), _n(n) {}\n    std::vector<vector<Edge>>::reference\
    \ operator[](std::size_t i) { return *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
    \ operator[](std::size_t i) const { return *(data.cbegin() + i); }\n    void add_edge(const\
    \ Edge& e) { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\n/**\n *\
    \ @brief \u96A3\u63A5\u30EA\u30B9\u30C8\n *\n * CSR\u5F62\u5F0F\n * See: https://qiita.com/Nachia/items/d420c08b333296f54526\n\
    \ */\nstruct AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m =\
    \ UINT64_MAX) : _n(n), _m(m), index(n + 1), _build_flg(m == 0) {}\n\n    struct\
    \ AdjacencyRange {\n        using iterator = std::vector<Edge>::const_iterator;\n\
    \        using reference = std::vector<Edge>::const_reference;\n        using\
    \ value_type = Edge;\n        iterator _begin, _end;\n        iterator begin()\
    \ const { return _begin; }\n        iterator end() const { return _end; }\n  \
    \      reference operator[](std::size_t i) const { return *(_begin + i); }\n \
    \       std::size_t size() const { return std::distance(_begin, _end); }\n   \
    \     bool empty() const { return size() == 0; }\n    };\n    AdjacencyRange operator[](std::size_t\
    \ i) const {\n        return AdjacencyRange{data.begin() + index[i], data.begin()\
    \ + index[i + 1]};\n    }\n\n    void build() {\n        std::partial_sum(index.begin(),\
    \ index.end(), index.begin());\n        data.resize(buf.size());\n        for\
    \ (auto&& e : buf) data[--index[e.src]] = e;\n        _build_flg = true;\n   \
    \ }\n    void add_edge(const Edge& e) {\n        ++index[e.src];\n        buf.emplace_back(e);\n\
    \        if (buf.size() == _m) build();\n    }\n    void add_edge(std::size_t\
    \ src, std::size_t dest, ll weight = 1) { add_edge(Edge(src, dest, weight)); }\n\
    \    std::size_t size() const { return _n; }\n    std::size_t n_edge() const {\
    \ return buf.size(); }\n    bool build_flg() const { return _build_flg; }\n\n\
    \   private:\n    std::size_t _n, _m;\n    std::vector<Edge> buf, data;\n    std::vector<std::size_t>\
    \ index;\n    bool _build_flg;\n};\n}  // namespace bys\nnamespace bys {\n/**\n\
    \ * @brief \u6700\u8FD1\u5171\u901A\u7956\u5148\n *\n * Sparse Table\u306B\u3088\
    \u308BEulerTour + RmQ\n * \u69CB\u7BC9   O(N logN)\n * \u30AF\u30A8\u30EA O(1)\n\
    \ */\nclass LowestCommonAncestor {\n    struct Vertex {\n        int id, depath;\n\
    \        bool operator<(const Vertex& rh) const { return depath < rh.depath; }\n\
    \    };\n    std::size_t n;\n    SparseTable<Min<Vertex>> st;\n    std::vector<int>\
    \ pos;\n\n   public:\n    template <class Adj>\n    LowestCommonAncestor(const\
    \ Adj& graph, int root) : n(graph.size()), pos(n) {\n        std::vector<Vertex>\
    \ euler_tour;\n        euler_tour.reserve(2 * n - 1);\n        FixPoint([&](auto&&\
    \ self, int now, int prev, int deapth) -> void {\n            pos[now] = euler_tour.size();\n\
    \            euler_tour.push_back({now, deapth});\n\n            for (auto&& nxt\
    \ : graph[now]) {\n                if (int(nxt.dest) == prev) continue;\n    \
    \            self(nxt.dest, now, deapth + 1);\n                euler_tour.push_back({now,\
    \ deapth});\n            }\n        })(root, -1, 0);\n        st.build(euler_tour);\n\
    \    }\n    int lca(std::size_t a, std::size_t b) {\n        assert(a < n);\n\
    \        assert(b < n);\n        if (pos[a] > pos[b]) std::swap(a, b);\n     \
    \   return st.query(pos[a], pos[b]).id;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file lca.hpp\n * @brief Lowest Common Ancestor\n *\n\
    \ * \u6700\u8FD1\u5171\u901A\u7956\u5148\n */\n#include \"../algebra/monoid.hpp\"\
    \n#include \"../data/sparse_table.hpp\"\n#include \"../utility/fixpoint.hpp\"\n\
    #include \"edge.hpp\"\nnamespace bys {\n/**\n * @brief \u6700\u8FD1\u5171\u901A\
    \u7956\u5148\n *\n * Sparse Table\u306B\u3088\u308BEulerTour + RmQ\n * \u69CB\u7BC9\
    \   O(N logN)\n * \u30AF\u30A8\u30EA O(1)\n */\nclass LowestCommonAncestor {\n\
    \    struct Vertex {\n        int id, depath;\n        bool operator<(const Vertex&\
    \ rh) const { return depath < rh.depath; }\n    };\n    std::size_t n;\n    SparseTable<Min<Vertex>>\
    \ st;\n    std::vector<int> pos;\n\n   public:\n    template <class Adj>\n   \
    \ LowestCommonAncestor(const Adj& graph, int root) : n(graph.size()), pos(n) {\n\
    \        std::vector<Vertex> euler_tour;\n        euler_tour.reserve(2 * n - 1);\n\
    \        FixPoint([&](auto&& self, int now, int prev, int deapth) -> void {\n\
    \            pos[now] = euler_tour.size();\n            euler_tour.push_back({now,\
    \ deapth});\n\n            for (auto&& nxt : graph[now]) {\n                if\
    \ (int(nxt.dest) == prev) continue;\n                self(nxt.dest, now, deapth\
    \ + 1);\n                euler_tour.push_back({now, deapth});\n            }\n\
    \        })(root, -1, 0);\n        st.build(euler_tour);\n    }\n    int lca(std::size_t\
    \ a, std::size_t b) {\n        assert(a < n);\n        assert(b < n);\n      \
    \  if (pos[a] > pos[b]) std::swap(a, b);\n        return st.query(pos[a], pos[b]).id;\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn:
  - algebra/monoid.hpp
  - data/sparse_table.hpp
  - core/stdlib.hpp
  - utility/fixpoint.hpp
  - graphv2/edge.hpp
  isVerificationFile: false
  path: graphv2/lca.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graphv2/lca.test.cpp
documentation_of: graphv2/lca.hpp
layout: document
redirect_from:
- /library/graphv2/lca.hpp
- /library/graphv2/lca.hpp.html
title: Lowest Common Ancestor
---
