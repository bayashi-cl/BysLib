---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Search
    links:
    - https://twitter.com/meguru_comp/status/697008509376835584
  bundledCode: "#include <cmath>\n#include <type_traits>\n\n#include <cstdint>\nnamespace\
    \ bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\n\
    using i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n/**\n * @file binary_search.hpp\n\
    \ * @brief Binary Search\n *\n * \u4E8C\u5206\u63A2\u7D22\u6CD5\n */\nnamespace\
    \ bys {\n/**\n * @brief \u62BD\u8C61\u5316\u3081\u3050\u308B\u5F0F\u4E8C\u5206\
    \u63A2\u7D22\n *\n * See: https://twitter.com/meguru_comp/status/697008509376835584\n\
    \ *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param is_ok \u5224\
    \u5B9A\u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return T is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T, class\
    \ Lambda, class... Args> T meguru_bisect(T ok, T ng, Lambda is_ok, Args... args)\
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
    \ Args> f128 bisect_float(f128 ok, f128 ng, i32 rep, Lambda is_ok, Args... args)\
    \ {\n    static_assert(std::is_same_v<std::invoke_result_t<Lambda, f128, Args...>,\
    \ bool>, \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    for (i32 i = 0; i < rep; i++) {\n   \
    \     auto mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n        \
    \    ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n  \
    \  return ok;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <cmath>\n#include <type_traits>\n\n#include \"../core/int_alias.hpp\"\
    \n/**\n * @file binary_search.hpp\n * @brief Binary Search\n *\n * \u4E8C\u5206\
    \u63A2\u7D22\u6CD5\n */\nnamespace bys {\n/**\n * @brief \u62BD\u8C61\u5316\u3081\
    \u3050\u308B\u5F0F\u4E8C\u5206\u63A2\u7D22\n *\n * See: https://twitter.com/meguru_comp/status/697008509376835584\n\
    \ *\n * @param ok is_ok\u304CTrue\u3068\u306A\u308B\u521D\u671F\u5024\n * @param\
    \ ng is_ok\u304CFalse\u3068\u306A\u308B\u521D\u671F\u5024\n * @param is_ok \u5224\
    \u5B9A\u7528\u95A2\u6570\n * @param args is_ok\u306B\u8FFD\u52A0\u3067\u6E21\u3055\
    \u308C\u308B\u5F15\u6570 \u53EF\u5909\u9577\n * @return T is_ok\u3092\u6E80\u305F\
    \u3059\u6700\u5927/\u5C0F\u306E\u6574\u6570\n */\ntemplate <typename T, class\
    \ Lambda, class... Args> T meguru_bisect(T ok, T ng, Lambda is_ok, Args... args)\
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
    \ Args> f128 bisect_float(f128 ok, f128 ng, i32 rep, Lambda is_ok, Args... args)\
    \ {\n    static_assert(std::is_same_v<std::invoke_result_t<Lambda, f128, Args...>,\
    \ bool>, \"The function signature is invalid.\");\n    assert(is_ok(ok, args...));\n\
    \    assert(!is_ok(ng, args...));\n\n    for (i32 i = 0; i < rep; i++) {\n   \
    \     auto mid = (ok + ng) / 2;\n        if (is_ok(mid, args...)) {\n        \
    \    ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n  \
    \  return ok;\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/algorithm/binary_search.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/algorithm/binary_search.hpp
layout: document
redirect_from:
- /library/byslib/algorithm/binary_search.hpp
- /library/byslib/algorithm/binary_search.hpp.html
title: Binary Search
---
