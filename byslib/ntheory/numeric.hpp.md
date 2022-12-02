---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/algebra/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: byslib/ntheory/prime.hpp
    title: Prime
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Numeric
    links:
    - https://docs.python.org/ja/3/library/functions.html#divmod
    - https://docs.python.org/ja/3/library/math.html#math.isqrt
    - https://docs.python.org/ja/3/reference/expressions.html#index-68
    - https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural
  bundledCode: "#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
    using i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\nusing isize\
    \ = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name,\
    \ type) \\\n    constexpr auto operator\"\" name(unsigned long long x) { return\
    \ static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16,\
    \ std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64,\
    \ std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8,\
    \ std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32,\
    \ std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128,\
    \ __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n\
    }  // namespace bys\n#include <algorithm>\n#include <cassert>\n#include <string>\n\
    /**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\
    \u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x)\
    \ - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T> constexpr i32 bit_width(T\
    \ x) {\n    i32 bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\
    \ntemplate <class T> constexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\ntemplate <class T> constexpr T bit_ceil(T x) {\n    assert(x >=\
    \ 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\
    \u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T> std::string bin(T n)\
    \ {\n    assert(n >= 0);\n    if (n == 0) return \"0\";\n    std::string res;\n\
    \    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//!\
    \ @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class\
    \ T> constexpr bool pop(T s, i32 d) { return s & (T(1) << d); }\n}  // namespace\
    \ bys\n/**\n * @file numeric.hpp\n * @brief Numeric\n *\n * \u6570\u5024\u8A08\
    \u7B97\u8A70\u3081\u5408\u308F\u305B\n */\nnamespace bys {\n//! @brief \u6574\u6570\
    \u306E\u7D2F\u4E57\nconstexpr i64 int_pow(i32 a, i32 b) {\n    i64 res = 1;\n\
    \    for (i32 i = 0; i < b; ++i) res *= a;\n    return res;\n}\n/**\n * @brief\
    \ \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * O(log q)\n */\nconstexpr\
    \ i64 mod_pow(i64 p, i64 q, i64 mod) {\n    if (mod == 1) return 0_i64;\n    i128\
    \ res = 1;\n    i128 b = p % mod;\n    while (q) {\n        if (q & 1) res = res\
    \ * b % mod;\n        b = b * b % mod;\n        q >>= 1;\n    }\n    return (i64)res;\n\
    }\n//! @brief ceil(x / y)\ntemplate <class T> constexpr T ceildiv(T x, T y) {\n\
    \    if ((x < T(0)) ^ (y < T(0))) {\n        return x / y;\n    } else {\n   \
    \     return (x + y + (x < T(0) ? 1 : -1)) / y;\n    }\n}\n//! @brief floor(x\
    \ / y)\ntemplate <class T> constexpr T floordiv(T x, T y) {\n    if ((x < T(0))\
    \ ^ (y < T(0))) {\n        return (x - y + (x < T(0) ? 1 : -1)) / y;\n    } else\
    \ {\n        return x / y;\n    }\n}\n/**\n * @brief Python::divmod\n *\n * See:\
    \ https://docs.python.org/ja/3/library/functions.html#divmod\n */\ntemplate <class\
    \ T> constexpr std::pair<T, T> divmod(T x, T y) {\n    auto q = floordiv(x, y);\n\
    \    return {q, x - q * y};\n}\n\n/**\n * @brief Python::%\n *\n * See: https://docs.python.org/ja/3/reference/expressions.html#index-68\n\
    \ */\ntemplate <class T, class S> constexpr T floormod(T x, S mod) {\n    x %=\
    \ mod;\n    if (x < 0) x += mod;\n    return x;\n}\n\nnamespace impl {\nconstexpr\
    \ i64 isqrt_aux(i64 c, i64 n) {\n    if (c == 0) return 1;\n    i64 k = (c - 1)\
    \ / 2;\n    i64 a = isqrt_aux(c / 2, n >> (2 * k + 2));\n    return (a << k) +\
    \ (n >> (k + 2)) / a;\n}\n}  // namespace impl\n/**\n * @brief Python::math.isqrt\n\
    \ *\n * floor(sqrt(n))\n * See: https://docs.python.org/ja/3/library/math.html#math.isqrt\n\
    \ */\ntemplate <class T> constexpr T isqrt(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return T(0);\n    i64 a = impl::isqrt_aux((bit_width(n) - 1) / 2,\
    \ n);\n    return n < a * a ? a - 1 : a;\n}\n/**\n * @brief Nim::math::almostEqual\n\
    \ *\n * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural\n */\n\
    template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\nconstexpr bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y)\
    \ return true;\n    auto diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n\nconstexpr\
    \ std::pair<i64, i64> inv_gcd(i64 a, i64 b) {\n    a = floormod(a, b);\n    if\
    \ (a == 0) return {b, 0};\n    i64 s = b, t = a;\n    i64 m0 = 0, m1 = 1;\n\n\
    \    while (t) {\n        i64 u = s / t;\n        s -= t * u;\n        m0 -= m1\
    \ * u;\n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp =\
    \ m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n\
    \    return {s, m0};\n}\n\n//! @brief Count multipules of k in the [left, right)\n\
    template <class T> constexpr T range_multiples(T left, T right, T k) { return\
    \ (right - 1) / k - (left - 1) / k; }\ntemplate <class T> constexpr T multiple_floor(T\
    \ x, T k) { return x / k * k; }\ntemplate <class T> constexpr T multiple_ceil(T\
    \ x, T k) { return ceildiv(x, k) * k; }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/int_alias.hpp\"\n#include \"bit.hpp\"\n\
    /**\n * @file numeric.hpp\n * @brief Numeric\n *\n * \u6570\u5024\u8A08\u7B97\u8A70\
    \u3081\u5408\u308F\u305B\n */\nnamespace bys {\n//! @brief \u6574\u6570\u306E\u7D2F\
    \u4E57\nconstexpr i64 int_pow(i32 a, i32 b) {\n    i64 res = 1;\n    for (i32\
    \ i = 0; i < b; ++i) res *= a;\n    return res;\n}\n/**\n * @brief \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * O(log q)\n */\nconstexpr i64 mod_pow(i64\
    \ p, i64 q, i64 mod) {\n    if (mod == 1) return 0_i64;\n    i128 res = 1;\n \
    \   i128 b = p % mod;\n    while (q) {\n        if (q & 1) res = res * b % mod;\n\
    \        b = b * b % mod;\n        q >>= 1;\n    }\n    return (i64)res;\n}\n\
    //! @brief ceil(x / y)\ntemplate <class T> constexpr T ceildiv(T x, T y) {\n \
    \   if ((x < T(0)) ^ (y < T(0))) {\n        return x / y;\n    } else {\n    \
    \    return (x + y + (x < T(0) ? 1 : -1)) / y;\n    }\n}\n//! @brief floor(x /\
    \ y)\ntemplate <class T> constexpr T floordiv(T x, T y) {\n    if ((x < T(0))\
    \ ^ (y < T(0))) {\n        return (x - y + (x < T(0) ? 1 : -1)) / y;\n    } else\
    \ {\n        return x / y;\n    }\n}\n/**\n * @brief Python::divmod\n *\n * See:\
    \ https://docs.python.org/ja/3/library/functions.html#divmod\n */\ntemplate <class\
    \ T> constexpr std::pair<T, T> divmod(T x, T y) {\n    auto q = floordiv(x, y);\n\
    \    return {q, x - q * y};\n}\n\n/**\n * @brief Python::%\n *\n * See: https://docs.python.org/ja/3/reference/expressions.html#index-68\n\
    \ */\ntemplate <class T, class S> constexpr T floormod(T x, S mod) {\n    x %=\
    \ mod;\n    if (x < 0) x += mod;\n    return x;\n}\n\nnamespace impl {\nconstexpr\
    \ i64 isqrt_aux(i64 c, i64 n) {\n    if (c == 0) return 1;\n    i64 k = (c - 1)\
    \ / 2;\n    i64 a = isqrt_aux(c / 2, n >> (2 * k + 2));\n    return (a << k) +\
    \ (n >> (k + 2)) / a;\n}\n}  // namespace impl\n/**\n * @brief Python::math.isqrt\n\
    \ *\n * floor(sqrt(n))\n * See: https://docs.python.org/ja/3/library/math.html#math.isqrt\n\
    \ */\ntemplate <class T> constexpr T isqrt(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return T(0);\n    i64 a = impl::isqrt_aux((bit_width(n) - 1) / 2,\
    \ n);\n    return n < a * a ? a - 1 : a;\n}\n/**\n * @brief Nim::math::almostEqual\n\
    \ *\n * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural\n */\n\
    template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\nconstexpr bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y)\
    \ return true;\n    auto diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n\nconstexpr\
    \ std::pair<i64, i64> inv_gcd(i64 a, i64 b) {\n    a = floormod(a, b);\n    if\
    \ (a == 0) return {b, 0};\n    i64 s = b, t = a;\n    i64 m0 = 0, m1 = 1;\n\n\
    \    while (t) {\n        i64 u = s / t;\n        s -= t * u;\n        m0 -= m1\
    \ * u;\n        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp =\
    \ m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n\
    \    return {s, m0};\n}\n\n//! @brief Count multipules of k in the [left, right)\n\
    template <class T> constexpr T range_multiples(T left, T right, T k) { return\
    \ (right - 1) / k - (left - 1) / k; }\ntemplate <class T> constexpr T multiple_floor(T\
    \ x, T k) { return x / k * k; }\ntemplate <class T> constexpr T multiple_ceil(T\
    \ x, T k) { return ceildiv(x, k) * k; }\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/ntheory/bit.hpp
  isVerificationFile: false
  path: byslib/ntheory/numeric.hpp
  requiredBy:
  - byslib/ntheory/prime.hpp
  - byslib/algebra/modint.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/ntheory/numeric.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/numeric.hpp
- /library/byslib/ntheory/numeric.hpp.html
title: Numeric
---
