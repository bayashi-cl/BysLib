---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: core/core.hpp
    title: core/core.hpp
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/reader.hpp
    title: graph/reader.hpp
  - icon: ':warning:'
    path: graphv2/reader.hpp
    title: graphv2/reader.hpp
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
    path: test/data/dual_segment_tree.test.cpp
    title: test/data/dual_segment_tree.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/math/combination.test.cpp
    title: test/math/combination.test.cpp
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
  bundledCode: '#include <iostream>

    #include <type_traits>

    #include <utility>


    namespace bys {

    template <class, class = void>

    struct has_lshift_to_ostream : std::false_type {};

    template <class T>

    struct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()
    << std::declval<T&>())>> : std::true_type {};


    template <class, class = void>

    struct has_rshift_from_istream : std::false_type {};

    template <class T>

    struct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()
    >> std::declval<T&>())>> : std::true_type {};


    template <class T, class = void>

    struct has_tuple_interface : std::false_type {};

    template <class T>

    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type
    {};


    template <class, class = void>

    struct has_iterator : std::false_type {};

    template <class T>

    struct has_iterator<T, std::void_t<typename T::iterator>> : std::true_type {};


    struct Int1 {};

    }  // namespace bys

    '
  code: '#pragma once

    #include <iostream>

    #include <type_traits>

    #include <utility>


    namespace bys {

    template <class, class = void>

    struct has_lshift_to_ostream : std::false_type {};

    template <class T>

    struct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()
    << std::declval<T&>())>> : std::true_type {};


    template <class, class = void>

    struct has_rshift_from_istream : std::false_type {};

    template <class T>

    struct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()
    >> std::declval<T&>())>> : std::true_type {};


    template <class T, class = void>

    struct has_tuple_interface : std::false_type {};

    template <class T>

    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type
    {};


    template <class, class = void>

    struct has_iterator : std::false_type {};

    template <class T>

    struct has_iterator<T, std::void_t<typename T::iterator>> : std::true_type {};


    struct Int1 {};

    }  // namespace bys

    '
  dependsOn: []
  isVerificationFile: false
  path: core/types.hpp
  requiredBy:
  - core/core.hpp
  - core/scanner.hpp
  - core/io.hpp
  - core/printer.hpp
  - graphv2/reader.hpp
  - graph/reader.hpp
  - graph/dijkstra.hpp
  timestamp: '2022-01-13 21:15:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
  - test/math/osa_k.test.cpp
  - test/math/combination.test.cpp
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
  - test/data/dual_segment_tree.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
  - test/data/cumulative_sum.test.cpp
  - test/data/union_find.test.cpp
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graphv2/lca.test.cpp
  - test/graphv2/dijkstra.test.cpp
  - test/graph/bfs_grid.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/lca.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: core/types.hpp
layout: document
redirect_from:
- /library/core/types.hpp
- /library/core/types.hpp.html
title: core/types.hpp
---
