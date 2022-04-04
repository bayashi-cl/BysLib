---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':x:'
    path: graphv2/warshall_floyd.hpp
    title: Warshall Floyd
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum_2D.test.cpp
    title: test/data/cumulative_sum_2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RAQ.test.cpp
    title: test/data/dual_segment_tree_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RUQ.test.cpp
    title: test/data/dual_segment_tree_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
    title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RMQ.test.cpp
    title: test/data/segment_tree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ.test.cpp
    title: test/data/segment_tree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ2.test.cpp
    title: test/data/segment_tree_RSQ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/union_find.test.cpp
    title: test/data/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bellman_ford.test.cpp
    title: test/graphv2/bellman_ford.test.cpp
  - icon: ':x:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  - icon: ':x:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  - icon: ':x:'
    path: test/math/euclid.test.cpp
    title: test/math/euclid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: chmin/chmax
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
    \ bys\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace bys {\n\
    /**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\
    \u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmax(T&\
    \ a, const T& b) {\n    return a < b ? a = b, true : false;\n}\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\
    \u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmin(T& a, const T&\
    \ b) {\n    return a > b ? a = b, true : false;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file change.hpp\n\
    \ * @brief chmin/chmax\n */\nnamespace bys {\n/**\n * @brief \u6700\u5927\u5024\
    \u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\
    \n */\ntemplate <class T>\ninline bool chmax(T& a, const T& b) {\n    return a\
    \ < b ? a = b, true : false;\n}\n/**\n * @brief \u6700\u5C0F\u5024\u3067\u66F4\
    \u65B0\n * @return true \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate\
    \ <class T>\ninline bool chmin(T& a, const T& b) {\n    return a > b ? a = b,\
    \ true : false;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/change.hpp
  requiredBy:
  - graphv2/bellman_ford.hpp
  - graphv2/warshall_floyd.hpp
  - graph/bellman_ford.hpp
  - graph/warshall_floyd.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graphv2/bellman_ford.test.cpp
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graph/bellman_ford.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - test/data/union_find.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree_RSQ2.test.cpp
  - test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - test/data/segment_tree_RMQ.test.cpp
  - test/data/segment_tree_RSQ.test.cpp
  - test/data/cumulative_sum_2D.test.cpp
  - test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - test/math/euclid.test.cpp
documentation_of: utility/change.hpp
layout: document
redirect_from:
- /library/utility/change.hpp
- /library/utility/change.hpp.html
title: chmin/chmax
---
