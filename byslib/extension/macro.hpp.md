---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    document_title: Macro
    links: []
  bundledCode: "#include <string>\nusing std::literals::string_literals::operator\"\
    \"s;\n/**\n * @file macro.hpp\n * @brief Macro\n */\n// clang-format off\n#define\
    \ CONCAT_IMPL(a, b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"file: \"s + __FILE__ + \", line:\
    \ \"s + std::to_string(__LINE__) + \", func: \"s + __func__)\n#ifdef LOCAL\n#define\
    \ DEBUGBLOCK(block) block\n#else\n#define DEBUGBLOCK(block)\n#endif\n// clang-format\
    \ on\n"
  code: "#pragma once\n#include <string>\nusing std::literals::string_literals::operator\"\
    \"s;\n/**\n * @file macro.hpp\n * @brief Macro\n */\n// clang-format off\n#define\
    \ CONCAT_IMPL(a, b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\
    \u5909\u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"file: \"s + __FILE__ + \", line:\
    \ \"s + std::to_string(__LINE__) + \", func: \"s + __func__)\n#ifdef LOCAL\n#define\
    \ DEBUGBLOCK(block) block\n#else\n#define DEBUGBLOCK(block)\n#endif\n// clang-format\
    \ on\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/macro.hpp
  requiredBy:
  - template.cpp
  - byslib/template.hpp
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
documentation_of: byslib/extension/macro.hpp
layout: document
redirect_from:
- /library/byslib/extension/macro.hpp
- /library/byslib/extension/macro.hpp.html
title: Macro
---
