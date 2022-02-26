---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u5206\u63A2\u7D22\u6CD5"
    links:
    - https://atcoder.jp/contests/abc205/submissions/23500985
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
    \ bys\n#line 3 \"utility/binary_search.hpp\"\n\nnamespace bys {\n/**\n * @brief\
    \ \u4E8C\u5206\u63A2\u7D22\u6CD5\n * https://atcoder.jp/contests/abc205/submissions/23500985\n\
    \ * @tparam T \u521D\u671F\u5024\u3068\u8FD4\u308A\u5024\u3001is_ok\u306E\u7B2C\
    \u4E00\u5F15\u6570 int or long long int\u3092\u60F3\u5B9A\n * @param ok (T): is_ok\u3092\
    \u6E80\u305F\u3059\u521D\u671F\u5024\n * @param ng (T): is_ok\u3092\u6E80\u305F\
    \u3055\u306A\u3044\u521D\u671F\u5024\n * @param is_ok (bool()): \u5224\u5B9A\u7528\
    \u30E9\u30E0\u30C0\u5F0F\n * @param args... (Args...): is_ok\u306B\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return (T): is_ok\u3092\u6E80\
    \u305F\u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T,\
    \ class Lambda, class... Args>\nT meguru_bisect(T ok, T ng, Lambda is_ok, Args...\
    \ args) {\n    assert(is_ok(ok, args...));\n    assert(!is_ok(ng, args...));\n\
    \n    while (std::abs(ok - ng) > 1) {\n        T mid = (ok + ng) / 2;\n      \
    \  if (is_ok(mid, args...)) {\n            ok = mid;\n        } else {\n     \
    \       ng = mid;\n        }\n    }\n    return ok;\n}\n/**\n * @brief \u5B9F\u6570\
    \u306E\u4E8C\u5206\u63A2\u7D22\n *\n * @tparam Lambda\n * @tparam Args\n * @param\
    \ ok is_ok\u3092\u6E80\u305F\u3059\u521D\u671F\u5024\n * @param ng is_ok\u3092\
    \u6E80\u305F\u3055\u306A\u3044\u521D\u671F\u5024\n * @param rep \u30A8\u30DD\u30C3\
    \u30AF\n * @param is_ok \u5224\u5B9A\u7528\u30E9\u30E0\u30C0\u5F0F bool(long double,\
    \ Args...)\n * @param args is_ok\u306B\u6E21\u3055\u308C\u308B\u8FFD\u52A0\u5F15\
    \u6570\n * @return double\n */\ntemplate <class Lambda, class... Args>\ndouble\
    \ bisect_float(ld ok, ld ng, int rep, Lambda is_ok, Args... args) {\n    assert(is_ok(ok,\
    \ args...));\n    assert(!is_ok(ng, args...));\n\n    for (int i = 0; i < rep;\
    \ i++) {\n        ld mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n\
    \            ok = mid;\n        } else {\n            ng = mid;\n        }\n \
    \   }\n    return ok;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\n/**\n *\
    \ @brief \u4E8C\u5206\u63A2\u7D22\u6CD5\n * https://atcoder.jp/contests/abc205/submissions/23500985\n\
    \ * @tparam T \u521D\u671F\u5024\u3068\u8FD4\u308A\u5024\u3001is_ok\u306E\u7B2C\
    \u4E00\u5F15\u6570 int or long long int\u3092\u60F3\u5B9A\n * @param ok (T): is_ok\u3092\
    \u6E80\u305F\u3059\u521D\u671F\u5024\n * @param ng (T): is_ok\u3092\u6E80\u305F\
    \u3055\u306A\u3044\u521D\u671F\u5024\n * @param is_ok (bool()): \u5224\u5B9A\u7528\
    \u30E9\u30E0\u30C0\u5F0F\n * @param args... (Args...): is_ok\u306B\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return (T): is_ok\u3092\u6E80\
    \u305F\u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T,\
    \ class Lambda, class... Args>\nT meguru_bisect(T ok, T ng, Lambda is_ok, Args...\
    \ args) {\n    assert(is_ok(ok, args...));\n    assert(!is_ok(ng, args...));\n\
    \n    while (std::abs(ok - ng) > 1) {\n        T mid = (ok + ng) / 2;\n      \
    \  if (is_ok(mid, args...)) {\n            ok = mid;\n        } else {\n     \
    \       ng = mid;\n        }\n    }\n    return ok;\n}\n/**\n * @brief \u5B9F\u6570\
    \u306E\u4E8C\u5206\u63A2\u7D22\n *\n * @tparam Lambda\n * @tparam Args\n * @param\
    \ ok is_ok\u3092\u6E80\u305F\u3059\u521D\u671F\u5024\n * @param ng is_ok\u3092\
    \u6E80\u305F\u3055\u306A\u3044\u521D\u671F\u5024\n * @param rep \u30A8\u30DD\u30C3\
    \u30AF\n * @param is_ok \u5224\u5B9A\u7528\u30E9\u30E0\u30C0\u5F0F bool(long double,\
    \ Args...)\n * @param args is_ok\u306B\u6E21\u3055\u308C\u308B\u8FFD\u52A0\u5F15\
    \u6570\n * @return double\n */\ntemplate <class Lambda, class... Args>\ndouble\
    \ bisect_float(ld ok, ld ng, int rep, Lambda is_ok, Args... args) {\n    assert(is_ok(ok,\
    \ args...));\n    assert(!is_ok(ng, args...));\n\n    for (int i = 0; i < rep;\
    \ i++) {\n        ld mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n\
    \            ok = mid;\n        } else {\n            ng = mid;\n        }\n \
    \   }\n    return ok;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/binary_search.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/binary_search.hpp
layout: document
redirect_from:
- /library/utility/binary_search.hpp
- /library/utility/binary_search.hpp.html
title: "\u4E8C\u5206\u63A2\u7D22\u6CD5"
---
