---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':warning:'
    path: graphv2/breadth_first_search.hpp
    title: graphv2/breadth_first_search.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree_aux.test.cpp
    title: test/data/binary_indexed_tree_aux.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum.test.cpp
    title: test/data/cumulative_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree.test.cpp
    title: test/data/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/union_find.test.cpp
    title: test/data/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/counter_clockwise.test.cpp
    title: test/geometry/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs_grid.test.cpp
    title: test/graph/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/dijkstra.test.cpp
    title: test/graphv2/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: test/math/osa_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/prime.test.cpp
    title: test/math/prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/test.test.cpp
    title: test/test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/utility/range.test.cpp
    title: test/utility/range.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30DE\u30AF\u30ED"
    links: []
  bundledCode: "#line 2 \"core/macro.hpp\"\n// clang-format off\n/**\n * @brief \u30DE\
    \u30AF\u30ED\n */\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\
    \u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\u3057\u306A\u3044\
    \u3002\n#define DEBUG(...) { std::cerr << \"[debug] line\" << std::setw(4) <<\
    \ __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n#define DEBUG(...)\n#endif\n\
    //! @brief print\u3057\u3066return\u3059\u308B\u3002\n#define EXIT(...) { print(__VA_ARGS__);\
    \ return; }\n#define CONCAT_IMPL(a, b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a,\
    \ b)\n//! @brief [[maybe_unused]]\u306A\u5909\u6570\u3092\u751F\u6210\u3002\n\
    #define UV [[maybe_unused]] auto CONCAT(unused_val_, __LINE__)\n#define RE std::runtime_error(\"\
    line: \" + std::to_string(__LINE__) + \", func: \" + __func__)\n// clang-format\
    \ on\n"
  code: "#pragma once\n// clang-format off\n/**\n * @brief \u30DE\u30AF\u30ED\n */\n\
    #ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\
    \u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\u3057\u306A\u3044\u3002\n#define DEBUG(...)\
    \ { std::cerr << \"[debug] line\" << std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__);\
    \ }\n#else\n#define DEBUG(...)\n#endif\n//! @brief print\u3057\u3066return\u3059\
    \u308B\u3002\n#define EXIT(...) { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a,\
    \ b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"line: \" + std::to_string(__LINE__)\
    \ + \", func: \" + __func__)\n// clang-format on\n"
  dependsOn: []
  isVerificationFile: false
  path: core/macro.hpp
  requiredBy:
  - core/core.hpp
  - graphv2/breadth_first_search.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-02-26 15:56:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
  - test/math/osa_k.test.cpp
  - test/geometry/area.test.cpp
  - test/geometry/counter_clockwise.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
  - test/geometry/is_convex.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/intersection.test.cpp
  - test/geometry/cross_point.test.cpp
  - test/utility/range.test.cpp
  - test/test.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/binary_indexed_tree_aux.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
  - test/data/cumulative_sum.test.cpp
  - test/data/union_find.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graphv2/lca.test.cpp
  - test/graphv2/dijkstra.test.cpp
  - test/graph/bfs_grid.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/lca.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: core/macro.hpp
layout: document
redirect_from:
- /library/core/macro.hpp
- /library/core/macro.hpp.html
title: "\u30DE\u30AF\u30ED"
---
