---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: data/union_find.hpp
    title: data/union_find.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#line 3 \"data/union_find.hpp\"\nnamespace bys {\nstruct UnionFindTree\
    \ {\n    UnionFindTree() : _n(0) {}\n    UnionFindTree(std::size_t n) : _n(n),\
    \ _n_tree(_n), parent(_n, -1) {}\n\n    std::size_t find(std::size_t a) {\n  \
    \      assert(a < _n);\n        std::vector<std::size_t> path;\n        while\
    \ (parent[a] >= 0) {\n            path.emplace_back(a);\n            a = parent[a];\n\
    \        }\n        for (auto&& p : path) parent[p] = a;\n        return a;\n\
    \    }\n    bool same(std::size_t a, std::size_t b) {\n        assert(a < _n);\n\
    \        assert(b < _n);\n        return find(a) == find(b);\n    }\n    bool\
    \ unite(std::size_t a, std::size_t b) {\n        assert(a < _n);\n        assert(b\
    \ < _n);\n        a = find(a);\n        b = find(b);\n        if (a == b) return\
    \ false;\n        --_n_tree;\n        if (-parent[a] < -parent[b]) std::swap(a,\
    \ b);\n        parent[a] += parent[b];\n        parent[b] = a;\n        return\
    \ true;\n    }\n    std::map<std::size_t, std::vector<std::size_t>> groups() {\n\
    \        std::map<std::size_t, std::vector<std::size_t>> res;\n        for (std::size_t\
    \ i = 0; i < _n; ++i) res[find(i)].emplace_back(i);\n        return res;\n   \
    \ };\n    std::size_t size(std::size_t a) { return -parent[find(a)]; }\n    std::size_t\
    \ n_tree() { return _n_tree; }\n\n   private:\n    std::size_t _n, _n_tree;\n\
    \    std::vector<int> parent;  // \u8CA0\u306A\u3089\u89AA\u3067\u3042\u308A\u305D\
    \u306E\u5024\u306F(-\u5B50\u306E\u6570)\n};\n}  // namespace bys\n#line 3 \"graph/edge.hpp\"\
    \n\nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\nstruct Edge {\n    int from, to;\n    ll cost;\n\n    //! @brief\
    \ \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\n    Edge(int to) : from(-1), to(to),\
    \ cost(1) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u5358\u9802\u70B9\n    Edge(int\
    \ to, ll cost) : from(-1), to(to), cost(cost) {}\n    //! @brief \u91CD\u307F\u4ED8\
    \u304D\u4E21\u9802\u70B9\n    Edge(int from, int to, ll cost) : from(from), to(to),\
    \ cost(cost) {}\n    bool operator<(const Edge& rh) const { return cost < rh.cost;\
    \ }\n    operator std::size_t() const { return to; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n        return os << \"{\" <<\
    \ e.from << \" -> \" << e.to << \": \" << e.cost << \"}\";\n    }\n};\nusing Adj\
    \ = vector<vector<Edge>>;\nusing EdgeList = vector<Edge>;\n}  // namespace bys\n\
    #line 5 \"graph/kruskal.hpp\"\n\nnamespace bys {\nstruct Kruskal {\n    int n_node;\n\
    \    EdgeList mst;\n    ll cost = 0;\n    Kruskal(EdgeList& edges, int n_node,\
    \ int n_tree = 1) : n_node(n_node) {\n        sort(edges.begin(), edges.end());\n\
    \        search(edges, n_tree);\n    }\n    void search(const EdgeList& edges,\
    \ int n_tree) {\n        UnionFindTree uft(n_node);\n        int sz = n_node;\n\
    \        for (auto&& e : edges) {\n            if (uft.same(e.from, e.to)) continue;\n\
    \            uft.unite(e.from, e.to);\n            mst.push_back(e);\n       \
    \     cost += e.cost;\n            --sz;\n            if (sz == n_tree) return;\n\
    \        }\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../data/union_find.hpp\"\
    \n#include \"edge.hpp\"\n\nnamespace bys {\nstruct Kruskal {\n    int n_node;\n\
    \    EdgeList mst;\n    ll cost = 0;\n    Kruskal(EdgeList& edges, int n_node,\
    \ int n_tree = 1) : n_node(n_node) {\n        sort(edges.begin(), edges.end());\n\
    \        search(edges, n_tree);\n    }\n    void search(const EdgeList& edges,\
    \ int n_tree) {\n        UnionFindTree uft(n_node);\n        int sz = n_node;\n\
    \        for (auto&& e : edges) {\n            if (uft.same(e.from, e.to)) continue;\n\
    \            uft.unite(e.from, e.to);\n            mst.push_back(e);\n       \
    \     cost += e.cost;\n            --sz;\n            if (sz == n_tree) return;\n\
    \        }\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - data/union_find.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-02-26 20:23:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal.test.cpp
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
