---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graphv2/breadth_first_search.hpp
    title: Breadth First Search
  - icon: ':warning:'
    path: graphv2/depth_first_search.hpp
    title: Depth First Search
  - icon: ':heavy_check_mark:'
    path: graphv2/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: graphv2/lca.hpp
    title: Lowest Common Ancestor
  - icon: ':warning:'
    path: graphv2/reader.hpp
    title: Reader
  - icon: ':warning:'
    path: graphv2/rooted_tree.hpp
    title: Rooted tree
  - icon: ':warning:'
    path: graphv2/topological_sort.hpp
    title: Topological Sort
  - icon: ':heavy_check_mark:'
    path: graphv2/warshall_floyd.hpp
    title: Warshall Floyd
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/dijkstra.test.cpp
    title: test/graphv2/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Edge
    links:
    - https://qiita.com/Nachia/items/d420c08b333296f54526
  bundledCode: "/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n/**\n * @file edge.hpp\n * @author bayashi_cl\n *\
    \ @brief Edge\n * @todo concept\n */\nnamespace bys {\n//! @brief \u8FBA\nstruct\
    \ Edge {\n    std::size_t src, dest;\n    ll weight;\n    Edge() {}\n    Edge(std::size_t\
    \ src, std::size_t dest, ll weight = 1) : src(src), dest(dest), weight(weight)\
    \ {}\n    bool operator<(const Edge& rh) const { return weight < rh.weight; }\n\
    \    operator int() const { return dest; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge& e) {\n        return os << \"{\" << e.src << \" -> \" << e.dest\
    \ << \": \" << e.weight << \"}\";\n    }\n};\n//! @brief \u96A3\u63A5\u30EA\u30B9\
    \u30C8\nstruct DynamicAdjacencyList {\n    std::vector<std::vector<Edge>> data;\n\
    \    DynamicAdjacencyList(std::size_t n) : data(n, vector<Edge>()), _n(n) {}\n\
    \    std::vector<vector<Edge>>::reference operator[](std::size_t i) { return *(data.begin()\
    \ + i); }\n    const std::vector<vector<Edge>>::const_reference operator[](std::size_t\
    \ i) const { return *(data.cbegin() + i); }\n    void add_edge(const Edge& e)\
    \ { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\n/**\n *\
    \ @brief \u96A3\u63A5\u30EA\u30B9\u30C8\n *\n * CSR\u5F62\u5F0F\n * See: https://qiita.com/Nachia/items/d420c08b333296f54526\n\
    \ */\nstruct AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m)\
    \ : _n(n), _m(m), index(n + 1), _build_flg(m == 0) { buf.reserve(m); }\n\n   \
    \ struct AdjacencyRange {\n        using iterator = std::vector<Edge>::const_iterator;\n\
    \        using reference = std::vector<Edge>::const_reference;\n        iterator\
    \ _begin, _end;\n        iterator begin() const { return _begin; }\n        iterator\
    \ end() const { return _end; }\n        reference operator[](std::size_t i) const\
    \ { return *(_begin + i); }\n        std::size_t size() const { return std::distance(_begin,\
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
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file edge.hpp\n *\
    \ @author bayashi_cl\n * @brief Edge\n * @todo concept\n */\nnamespace bys {\n\
    //! @brief \u8FBA\nstruct Edge {\n    std::size_t src, dest;\n    ll weight;\n\
    \    Edge() {}\n    Edge(std::size_t src, std::size_t dest, ll weight = 1) : src(src),\
    \ dest(dest), weight(weight) {}\n    bool operator<(const Edge& rh) const { return\
    \ weight < rh.weight; }\n    operator int() const { return dest; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Edge& e) {\n        return\
    \ os << \"{\" << e.src << \" -> \" << e.dest << \": \" << e.weight << \"}\";\n\
    \    }\n};\n//! @brief \u96A3\u63A5\u30EA\u30B9\u30C8\nstruct DynamicAdjacencyList\
    \ {\n    std::vector<std::vector<Edge>> data;\n    DynamicAdjacencyList(std::size_t\
    \ n) : data(n, vector<Edge>()), _n(n) {}\n    std::vector<vector<Edge>>::reference\
    \ operator[](std::size_t i) { return *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
    \ operator[](std::size_t i) const { return *(data.cbegin() + i); }\n    void add_edge(const\
    \ Edge& e) { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\n/**\n *\
    \ @brief \u96A3\u63A5\u30EA\u30B9\u30C8\n *\n * CSR\u5F62\u5F0F\n * See: https://qiita.com/Nachia/items/d420c08b333296f54526\n\
    \ */\nstruct AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m)\
    \ : _n(n), _m(m), index(n + 1), _build_flg(m == 0) { buf.reserve(m); }\n\n   \
    \ struct AdjacencyRange {\n        using iterator = std::vector<Edge>::const_iterator;\n\
    \        using reference = std::vector<Edge>::const_reference;\n        iterator\
    \ _begin, _end;\n        iterator begin() const { return _begin; }\n        iterator\
    \ end() const { return _end; }\n        reference operator[](std::size_t i) const\
    \ { return *(_begin + i); }\n        std::size_t size() const { return std::distance(_begin,\
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
    \ bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: graphv2/edge.hpp
  requiredBy:
  - graphv2/depth_first_search.hpp
  - graphv2/reader.hpp
  - graphv2/topological_sort.hpp
  - graphv2/warshall_floyd.hpp
  - graphv2/lca.hpp
  - graphv2/breadth_first_search.hpp
  - graphv2/dijkstra.hpp
  - graphv2/rooted_tree.hpp
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graphv2/lca.test.cpp
  - test/graphv2/dijkstra.test.cpp
documentation_of: graphv2/edge.hpp
layout: document
redirect_from:
- /library/graphv2/edge.hpp
- /library/graphv2/edge.hpp.html
title: Edge
---
