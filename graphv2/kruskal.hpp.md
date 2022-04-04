---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: data/union_find.hpp
    title: Union Find Tree
  - icon: ':heavy_check_mark:'
    path: graphv2/edge.hpp
    title: Edge
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Kruskal
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file union_find.hpp\n * @brief Union Find Tree\n */\nnamespace\
    \ bys {\n//! @brief Union Find Tree\nstruct UnionFindTree {\n    UnionFindTree()\
    \ : _n(0) {}\n    UnionFindTree(std::size_t n) : _n(n), _n_tree(_n), parent(_n,\
    \ -1) {}\n\n    std::size_t find(std::size_t a) {\n        assert(a < _n);\n \
    \       std::vector<std::size_t> path;\n        while (parent[a] >= 0) {\n   \
    \         path.emplace_back(a);\n            a = parent[a];\n        }\n     \
    \   for (auto&& p : path) parent[p] = a;\n        return a;\n    }\n    bool same(std::size_t\
    \ a, std::size_t b) {\n        assert(a < _n);\n        assert(b < _n);\n    \
    \    return find(a) == find(b);\n    }\n    /**\n     * @brief \u30DE\u30FC\u30B8\
    \n     *\n     * a, b\u304C\u5225\u306E\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\
    \u3066\u3044\u305F\u5834\u5408true\n     */\n    bool unite(std::size_t a, std::size_t\
    \ b) {\n        assert(a < _n);\n        assert(b < _n);\n        a = find(a);\n\
    \        b = find(b);\n        if (a == b) return false;\n        --_n_tree;\n\
    \        if (-parent[a] < -parent[b]) std::swap(a, b);\n        parent[a] += parent[b];\n\
    \        parent[b] = a;\n        return true;\n    }\n    std::map<std::size_t,\
    \ std::vector<std::size_t>> groups() {\n        std::map<std::size_t, std::vector<std::size_t>>\
    \ res;\n        for (std::size_t i = 0; i < _n; ++i) res[find(i)].emplace_back(i);\n\
    \        return res;\n    };\n    std::size_t size(std::size_t a) { return -parent[find(a)];\
    \ }\n    std::size_t n_tree() { return _n_tree; }\n\n   private:\n    std::size_t\
    \ _n, _n_tree;\n    std::vector<int> parent;  // \u8CA0\u306A\u3089\u89AA\u3067\
    \u3042\u308A\u305D\u306E\u5024\u306F(-\u5B50\u306E\u6570)\n};\n}  // namespace\
    \ bys\n/**\n * @file edge.hpp\n * @brief Edge\n * @todo concept\n */\nnamespace\
    \ bys {\n//! @brief \u8FBA\nstruct Edge {\n    std::size_t src, dest;\n    ll\
    \ weight;\n    Edge() {}\n    Edge(std::size_t src, std::size_t dest, ll weight\
    \ = 1) : src(src), dest(dest), weight(weight) {}\n    bool operator<(const Edge&\
    \ rh) const { return weight < rh.weight; }\n    operator int() const { return\
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
    \ index;\n    bool _build_flg;\n};\n}  // namespace bys\n/**\n * @file kruskal.hpp\n\
    \ * @brief Kruskal\n */\nnamespace bys {\nusing Elist = std::vector<Edge>;\n/**\n\
    \ * @brief \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\n * @param elist \u30BD\u30FC\u30C8\
    \u3055\u308C\u305F\u8FBA\u30EA\u30B9\u30C8\n * @param n_node \u9802\u70B9\u6570\
    \n * @param n_tree \u6700\u7D42\u7684\u306A\u9023\u7D50\u6210\u5206\u306E\u500B\
    \u6570(optional)\n * @return std::pair<ll, Elist> {\u30B3\u30B9\u30C8, \u6700\u5C0F\
    \u5168\u57DF\u6728}\n */\nstd::pair<ll, Elist> kruskal(const Elist& elist, int\
    \ n_node, int n_tree = 1) {\n    assert(std::is_sorted(elist.begin(), elist.end()));\n\
    \    UnionFindTree uft(n_node);\n    ll cost = 0;\n    Elist mst;\n    for (auto&&\
    \ e : elist) {\n        if (uft.unite(e.src, e.dest)) {\n            cost += e.weight;\n\
    \            mst.push_back(e);\n            if (--n_node == n_tree) break;\n \
    \       }\n    }\n    return {cost, mst};\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../data/union_find.hpp\"\
    \n#include \"edge.hpp\"\n/**\n * @file kruskal.hpp\n * @brief Kruskal\n */\nnamespace\
    \ bys {\nusing Elist = std::vector<Edge>;\n/**\n * @brief \u30AF\u30E9\u30B9\u30AB\
    \u30EB\u6CD5\n * @param elist \u30BD\u30FC\u30C8\u3055\u308C\u305F\u8FBA\u30EA\
    \u30B9\u30C8\n * @param n_node \u9802\u70B9\u6570\n * @param n_tree \u6700\u7D42\
    \u7684\u306A\u9023\u7D50\u6210\u5206\u306E\u500B\u6570(optional)\n * @return std::pair<ll,\
    \ Elist> {\u30B3\u30B9\u30C8, \u6700\u5C0F\u5168\u57DF\u6728}\n */\nstd::pair<ll,\
    \ Elist> kruskal(const Elist& elist, int n_node, int n_tree = 1) {\n    assert(std::is_sorted(elist.begin(),\
    \ elist.end()));\n    UnionFindTree uft(n_node);\n    ll cost = 0;\n    Elist\
    \ mst;\n    for (auto&& e : elist) {\n        if (uft.unite(e.src, e.dest)) {\n\
    \            cost += e.weight;\n            mst.push_back(e);\n            if\
    \ (--n_node == n_tree) break;\n        }\n    }\n    return {cost, mst};\n}\n\
    }  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - data/union_find.hpp
  - graphv2/edge.hpp
  isVerificationFile: false
  path: graphv2/kruskal.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphv2/kruskal.hpp
layout: document
redirect_from:
- /library/graphv2/kruskal.hpp
- /library/graphv2/kruskal.hpp.html
title: Kruskal
---
