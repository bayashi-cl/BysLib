---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Search
    links:
    - https://twitter.com/meguru_comp/status/697008509376835584
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
    \ bys\n/**\n * @file binary_search.hpp\n * @brief Binary Search\n *\n * \u4E8C\
    \u5206\u63A2\u7D22\u6CD5\n */\nnamespace bys {\n/**\n * @brief \u62BD\u8C61\u5316\
    \u3081\u3050\u308B\u5F0F\u4E8C\u5206\u63A2\u7D22\n *\n * See: https://twitter.com/meguru_comp/status/697008509376835584\n\
    \ *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param is_ok \u5224\
    \u5B9A\u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return T is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T, class\
    \ Lambda, class... Args>\nT meguru_bisect(T ok, T ng, Lambda is_ok, Args... args)\
    \ {\n    static_assert(std::is_same_v<std::invoke_result_t<Lambda, T, Args...>,\
    \ bool>, \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    while (std::abs(ok - ng) > 1) {\n   \
    \     T mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n           \
    \ ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n\n/**\n * @brief \u5B9F\u6570\u7BC4\u56F2\u306E\u4E8C\u5206\u63A2\u7D22\
    \n *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param rep \u7E70\
    \u308A\u8FD4\u3057\u56DE\u6570 100\u56DE\u7A0B\u5EA6?\n * @param is_ok \u5224\u5B9A\
    \u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\u308C\
    \u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return double is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u5B9F\u6570\n */\ntemplate <class Lambda, class...\
    \ Args>\nld bisect_float(ld ok, ld ng, int rep, Lambda is_ok, Args... args) {\n\
    \    static_assert(std::is_same_v<std::invoke_result_t<Lambda, ld, Args...>, bool>,\
    \ \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    for (int i = 0; i < rep; i++) {\n   \
    \     ld mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n          \
    \  ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file binary_search.hpp\n\
    \ * @brief Binary Search\n *\n * \u4E8C\u5206\u63A2\u7D22\u6CD5\n */\nnamespace\
    \ bys {\n/**\n * @brief \u62BD\u8C61\u5316\u3081\u3050\u308B\u5F0F\u4E8C\u5206\
    \u63A2\u7D22\n *\n * See: https://twitter.com/meguru_comp/status/697008509376835584\n\
    \ *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param is_ok \u5224\
    \u5B9A\u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return T is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T, class\
    \ Lambda, class... Args>\nT meguru_bisect(T ok, T ng, Lambda is_ok, Args... args)\
    \ {\n    static_assert(std::is_same_v<std::invoke_result_t<Lambda, T, Args...>,\
    \ bool>, \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    while (std::abs(ok - ng) > 1) {\n   \
    \     T mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n           \
    \ ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n\n/**\n * @brief \u5B9F\u6570\u7BC4\u56F2\u306E\u4E8C\u5206\u63A2\u7D22\
    \n *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param rep \u7E70\
    \u308A\u8FD4\u3057\u56DE\u6570 100\u56DE\u7A0B\u5EA6?\n * @param is_ok \u5224\u5B9A\
    \u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\u308C\
    \u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return double is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u5B9F\u6570\n */\ntemplate <class Lambda, class...\
    \ Args>\nld bisect_float(ld ok, ld ng, int rep, Lambda is_ok, Args... args) {\n\
    \    static_assert(std::is_same_v<std::invoke_result_t<Lambda, ld, Args...>, bool>,\
    \ \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    for (int i = 0; i < rep; i++) {\n   \
    \     ld mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n          \
    \  ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n    return\
    \ ok;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/binary_search.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/binary_search.hpp
layout: document
redirect_from:
- /library/utility/binary_search.hpp
- /library/utility/binary_search.hpp.html
title: Binary Search
---
