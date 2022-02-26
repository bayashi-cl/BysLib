---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: graph/breadth_first.hpp
    title: graph/breadth_first.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  - icon: ':warning:'
    path: graphv2/breadth_first_search.hpp
    title: graphv2/breadth_first_search.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/dijkstra.hpp
    title: graphv2/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/result.hpp
    title: Single Source Shortest Path Result
  - icon: ':heavy_check_mark:'
    path: graphv2/warshall_floyd.hpp
    title: graphv2/warshall_floyd.hpp
  - icon: ':warning:'
    path: math/combination.hpp
    title: math/combination.hpp
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
    links: []
  bundledCode: '#line 2 "core/stdlib.hpp"

    #ifndef LOCAL

    #define NDEBUG

    #endif


    #include <algorithm>

    #include <array>

    #include <cassert>

    #include <cmath>

    #include <complex>

    #include <functional>

    #include <iomanip>

    #include <iostream>

    #include <iterator>

    #include <limits>

    #include <map>

    #include <numeric>

    #include <queue>

    #include <set>

    #include <stack>

    #include <string>

    #include <type_traits>

    #include <unordered_map>

    #include <unordered_set>

    #include <vector>


    namespace bys {

    using std::array, std::vector, std::string, std::set, std::map, std::pair;

    using std::cin, std::cout, std::endl;

    using std::min, std::max, std::sort, std::reverse, std::abs, std::pow;


    // alias

    using ll = long long int;

    using ld = long double;

    using Pa = pair<int, int>;

    using Pall = pair<ll, ll>;

    using ibool = std::int8_t;

    template <class T>

    using uset = std::unordered_set<T>;

    template <class S, class T>

    using umap = std::unordered_map<S, T>;

    }  // namespace bys

    #line 3 "core/const.hpp"


    namespace bys {

    constexpr int MOD = 998244353;

    constexpr int MOD7 = 1000000007;

    constexpr int INF = std::numeric_limits<int>::max() / 2;

    constexpr ll LINF = std::numeric_limits<ll>::max() / 2;

    }  // namespace bys

    '
  code: '#pragma once

    #include "stdlib.hpp"


    namespace bys {

    constexpr int MOD = 998244353;

    constexpr int MOD7 = 1000000007;

    constexpr int INF = std::numeric_limits<int>::max() / 2;

    constexpr ll LINF = std::numeric_limits<ll>::max() / 2;

    }  // namespace bys

    '
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: core/const.hpp
  requiredBy:
  - math/combination.hpp
  - core/core.hpp
  - graphv2/result.hpp
  - graphv2/warshall_floyd.hpp
  - graphv2/breadth_first_search.hpp
  - graphv2/dijkstra.hpp
  - graph/breadth_first.hpp
  - graph/warshall_floyd.hpp
  - graph/dijkstra.hpp
  - graph/bellman_ford.hpp
  timestamp: '2022-02-09 20:16:53+09:00'
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
  - test/graphv2/dijkstra.test.cpp
  - test/graph/bfs_grid.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/lca.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: core/const.hpp
layout: document
redirect_from:
- /library/core/const.hpp
- /library/core/const.hpp.html
title: core/const.hpp
---
