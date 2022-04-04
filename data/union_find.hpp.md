---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  - icon: ':warning:'
    path: graphv2/kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/union_find.test.cpp
    title: test/data/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find Tree
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
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file union_find.hpp\n\
    \ * @brief Union Find Tree\n */\nnamespace bys {\n//! @brief Union Find Tree\n\
    struct UnionFindTree {\n    UnionFindTree() : _n(0) {}\n    UnionFindTree(std::size_t\
    \ n) : _n(n), _n_tree(_n), parent(_n, -1) {}\n\n    std::size_t find(std::size_t\
    \ a) {\n        assert(a < _n);\n        std::vector<std::size_t> path;\n    \
    \    while (parent[a] >= 0) {\n            path.emplace_back(a);\n           \
    \ a = parent[a];\n        }\n        for (auto&& p : path) parent[p] = a;\n  \
    \      return a;\n    }\n    bool same(std::size_t a, std::size_t b) {\n     \
    \   assert(a < _n);\n        assert(b < _n);\n        return find(a) == find(b);\n\
    \    }\n    /**\n     * @brief \u30DE\u30FC\u30B8\n     *\n     * a, b\u304C\u5225\
    \u306E\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u305F\u5834\u5408\
    true\n     */\n    bool unite(std::size_t a, std::size_t b) {\n        assert(a\
    \ < _n);\n        assert(b < _n);\n        a = find(a);\n        b = find(b);\n\
    \        if (a == b) return false;\n        --_n_tree;\n        if (-parent[a]\
    \ < -parent[b]) std::swap(a, b);\n        parent[a] += parent[b];\n        parent[b]\
    \ = a;\n        return true;\n    }\n    std::map<std::size_t, std::vector<std::size_t>>\
    \ groups() {\n        std::map<std::size_t, std::vector<std::size_t>> res;\n \
    \       for (std::size_t i = 0; i < _n; ++i) res[find(i)].emplace_back(i);\n \
    \       return res;\n    };\n    std::size_t size(std::size_t a) { return -parent[find(a)];\
    \ }\n    std::size_t n_tree() { return _n_tree; }\n\n   private:\n    std::size_t\
    \ _n, _n_tree;\n    std::vector<int> parent;  // \u8CA0\u306A\u3089\u89AA\u3067\
    \u3042\u308A\u305D\u306E\u5024\u306F(-\u5B50\u306E\u6570)\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/union_find.hpp
  requiredBy:
  - graphv2/kruskal.hpp
  - graph/kruskal.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal.test.cpp
  - test/data/union_find.test.cpp
documentation_of: data/union_find.hpp
layout: document
redirect_from:
- /library/data/union_find.hpp
- /library/data/union_find.hpp.html
title: Union Find Tree
---
