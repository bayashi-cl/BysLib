---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/graph/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':warning:'
    path: byslib/graph/bfs.hpp
    title: byslib/graph/bfs.hpp
  - icon: ':warning:'
    path: byslib/graph/dfs.hpp
    title: byslib/graph/dfs.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/dijkstra.hpp
    title: byslib/graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/edge.hpp
    title: byslib/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/graph.hpp
    title: byslib/graph/graph.hpp
  - icon: ':warning:'
    path: byslib/graph/kruskal.hpp
    title: byslib/graph/kruskal.hpp
  - icon: ':warning:'
    path: byslib/graph/lca.hpp
    title: Lowest Common Ancestor
  - icon: ':warning:'
    path: byslib/graph/reader.hpp
    title: Reader
  - icon: ':warning:'
    path: byslib/graph/shortest_path_tree.hpp
    title: byslib/graph/shortest_path_tree.hpp
  - icon: ':warning:'
    path: byslib/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':warning:'
    path: byslib/graph/tree.hpp
    title: byslib/graph/tree.hpp
  - icon: ':warning:'
    path: byslib/graph/util.hpp
    title: byslib/graph/util.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/warshall_floyd.hpp
    title: Warshall Floyd
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/coo.hpp
    title: byslib/linalg/coo.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/csr.hpp
    title: byslib/linalg/csr.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: 'namespace bys {

    template <class T> struct CSRMatrix;

    }

    '
  code: '#pragma once

    namespace bys {

    template <class T> struct CSRMatrix;

    }

    '
  dependsOn: []
  isVerificationFile: false
  path: byslib/linalg/sparsefwd.hpp
  requiredBy:
  - byslib/linalg/csr.hpp
  - byslib/linalg/coo.hpp
  - byslib/graph/bellman_ford.hpp
  - byslib/graph/topological_sort.hpp
  - byslib/graph/bfs.hpp
  - byslib/graph/shortest_path_tree.hpp
  - byslib/graph/dijkstra.hpp
  - byslib/graph/kruskal.hpp
  - byslib/graph/util.hpp
  - byslib/graph/lca.hpp
  - byslib/graph/graph.hpp
  - byslib/graph/tree.hpp
  - byslib/graph/reader.hpp
  - byslib/graph/edge.hpp
  - byslib/graph/dfs.hpp
  - byslib/graph/warshall_floyd.hpp
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_A.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
documentation_of: byslib/linalg/sparsefwd.hpp
layout: document
redirect_from:
- /library/byslib/linalg/sparsefwd.hpp
- /library/byslib/linalg/sparsefwd.hpp.html
title: byslib/linalg/sparsefwd.hpp
---
