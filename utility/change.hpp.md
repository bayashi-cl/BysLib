---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/warshall_floyd.hpp
    title: graphv2/warshall_floyd.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
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
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/change.hpp\"\nnamespace bys {\ntemplate <class T>\n\
    inline bool chmax(T& a, const T& b) {\n    if (a < b) {\n        a = b;\n    \
    \    return 1;\n    }\n    return 0;\n}\ntemplate <class T>\ninline bool chmin(T&\
    \ a, const T& b) {\n    if (b < a) {\n        a = b;\n        return 1;\n    }\n\
    \    return 0;\n}\n}  // namespace bys\n"
  code: "#pragma once\nnamespace bys {\ntemplate <class T>\ninline bool chmax(T& a,\
    \ const T& b) {\n    if (a < b) {\n        a = b;\n        return 1;\n    }\n\
    \    return 0;\n}\ntemplate <class T>\ninline bool chmin(T& a, const T& b) {\n\
    \    if (b < a) {\n        a = b;\n        return 1;\n    }\n    return 0;\n}\n\
    }  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/change.hpp
  requiredBy:
  - graphv2/warshall_floyd.hpp
  - graph/warshall_floyd.hpp
  - graph/bellman_ford.hpp
  timestamp: '2021-12-29 22:40:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/binary_indexed_tree.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
  - test/data/union_find.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: utility/change.hpp
layout: document
redirect_from:
- /library/utility/change.hpp
- /library/utility/change.hpp.html
title: utility/change.hpp
---
