---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/graph/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':heavy_check_mark:'
    path: byslib/graph/warshall_floyd.hpp
    title: Warshall Floyd
  - icon: ':question:'
    path: byslib/template.hpp
    title: byslib/template.hpp
  - icon: ':warning:'
    path: template.cpp
    title: template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_A.test.cpp
    title: test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_B.test.cpp
    title: test/AOJ/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_C.test.cpp
    title: test/AOJ/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_A.test.cpp
    title: test/AOJ/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_B.test.cpp
    title: test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_D.test.cpp
    title: test/AOJ/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_A.test.cpp
    title: test/AOJ/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_B.test.cpp
    title: test/AOJ/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_A.test.cpp
    title: test/AOJ/DSL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_B.test.cpp
    title: test/AOJ/DSL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/test.test.cpp
    title: test/test.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: chmin/chmax
    links: []
  bundledCode: "/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace bys\
    \ {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\
    \u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr bool chmax(T&\
    \ a, T const& b) { return a < b ? a = b, true : false; }\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\u305F\
    \u3068\u304D\n */\ntemplate <class T> constexpr bool chmin(T& a, T const& b) {\
    \ return a > b ? a = b, true : false; }\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace\
    \ bys {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true\
    \ \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr\
    \ bool chmax(T& a, T const& b) { return a < b ? a = b, true : false; }\n/**\n\
    \ * @brief \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\
    \u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr bool chmin(T& a, T\
    \ const& b) { return a > b ? a = b, true : false; }\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/change.hpp
  requiredBy:
  - template.cpp
  - byslib/template.hpp
  - byslib/graph/bellman_ford.hpp
  - byslib/graph/warshall_floyd.hpp
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_5_B.test.cpp
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/GRL_1_A.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/CGL_2_B.test.cpp
  - test/AOJ/CGL_2_A.test.cpp
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_1_C.test.cpp
  - test/AOJ/CGL_1_B.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/DSL_5_A.test.cpp
  - test/AOJ/CGL_2_D.test.cpp
  - test/AOJ/DSL_1_A.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/CGL_3_A.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/CGL_1_A.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/CGL_3_B.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
  - test/test.test.cpp
  - test/yosupo/staticrmq.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/unionfind.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/extension/change.hpp
layout: document
redirect_from:
- /library/byslib/extension/change.hpp
- /library/byslib/extension/change.hpp.html
title: chmin/chmax
---
