---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: Bit
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: Numeric
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: Prime
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
    title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links:
    - https://atcoder.github.io/ac-library/document_ja/modint.html
  bundledCode: "/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n/**\n * @file bit.hpp\n * @author bayashi_cl\n * @brief\
    \ Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace\
    \ bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n\
    \ */\ntemplate <class T>\nconstexpr int bit_width(T x) {\n    int bits = 0;\n\
    \    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return\
    \ bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class\
    \ T>\nconstexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0\
    \ : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\
    \u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x) {\n    assert(x >= 0);\n\
    \    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\u6587\
    \u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\nstd::string bin(T n) {\n \
    \   assert(n > 0);\n    if (n == 0) return \"0\";\n    std::string res;\n    while\
    \ (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>= 1;\n   \
    \ }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//! @brief\
    \ d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class T>\n\
    constexpr bool pop(T s, int d) {\n    return s & (T(1) << d);\n}\n}  // namespace\
    \ bys\n/**\n * @file numeric.hpp\n * @author bayashi_cl\n * @brief Numeric\n *\n\
    \ * \u6570\u5024\u8A08\u7B97\u8A70\u3081\u5408\u308F\u305B\n */\nnamespace bys\
    \ {\n//! @brief \u6574\u6570\u306E\u7D2F\u4E57\nconstexpr ll int_pow(int a, int\
    \ b) {\n    ll res = 1;\n    for (int i = 0; i < b; ++i) res *= a;\n    return\
    \ res;\n}\n/**\n * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * O(log\
    \ q)\n */\ntemplate <class T>\nconstexpr T mod_pow(T p, T q, T mod) {\n    T res\
    \ = 1 % mod;\n    p %= mod;\n    for (; q; q >>= 1) {\n        if (q & 1) res\
    \ = res * p % mod;\n        p = p * p % mod;\n    }\n    return res;\n}\n//! @brief\
    \ ceil(x / y)\ntemplate <class T>\nconstexpr T ceildiv(T x, T y) {\n    return\
    \ x > T(0) ? (x + y - 1) / y : x / y;\n}\n//! @brief floor(x / y)\ntemplate <class\
    \ T>\nconstexpr T floordiv(T x, T y) {\n    return x > T(0) ? x / y : (x - y +\
    \ 1) / y;\n}\n/**\n * @brief Python::divmod\n *\n * See: https://docs.python.org/ja/3/library/functions.html#divmod\n\
    \ */\ntemplate <class T>\nconstexpr std::pair<T, T> divmod(T x, T y) {\n    auto\
    \ q = floordiv(x, y);\n    return {q, x - q * y};\n}\n\n/**\n * @brief Python::%\n\
    \ *\n * See: https://docs.python.org/ja/3/reference/expressions.html#index-68\n\
    \ */\ntemplate <class T, class S>\nconstexpr T floormod(T x, S mod) {\n    x %=\
    \ mod;\n    if (x < 0) x += mod;\n    return x;\n}\n\nconstexpr ll isqrt_aux(ll\
    \ c, ll n) {\n    if (c == 0) return 1;\n    ll k = (c - 1) / 2;\n    ll a = isqrt_aux(c\
    \ / 2, n >> (2 * k + 2));\n    return (a << k) + (n >> (k + 2)) / a;\n}\n/**\n\
    \ * @brief Python::math.isqrt\n *\n * floor(sqrt(n))\n * See: https://docs.python.org/ja/3/library/math.html#math.isqrt\n\
    \ */\ntemplate <class T>\nconstexpr T isqrt(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return T(0);\n    ll a = isqrt_aux((bit_width(n) - 1) / 2, n);\n\
    \    return n < a * a ? a - 1 : a;\n}\n/**\n * @brief Nim::math::almostEqual\n\
    \ *\n * See: https://nim-lang.org/docs/math.html#almostEqual,T,T,Natural\n */\n\
    template <class T, typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t>\
    \ = nullptr>\nconstexpr bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y)\
    \ return true;\n    auto diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n}  //\
    \ namespace bys\n/**\n * @file prime.hpp\n * @author bayashi_cl\n * @brief Prime\n\
    \ */\nnamespace bys {\n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\n *\n *\
    \ \u8A66\u3057\u5272\u308A\u6CD5\n * O(\u221An)\n */\ntemplate <typename T>\n\
    vector<T> prime_factorize(T n) {\n    vector<T> res;\n    while (n % 2 == 0) {\n\
    \        res.push_back(2);\n        n /= 2;\n    }\n    T f = 3;\n    while (f\
    \ * f <= n) {\n        if (n % f == 0) {\n            res.push_back(f);\n    \
    \        n /= f;\n        } else {\n            f += 2;\n        }\n    }\n  \
    \  if (n != 1) res.push_back(n);\n    return res;\n}\n\n/**\n * @brief Miller-Rabin\u7D20\
    \u6570\u5224\u5B9A\n *\n * 2^64\u4EE5\u4E0B\u306A\u3089\u6B63\u78BA\u306B\u5224\
    \u5B9A\u3067\u304D\u308B\n * See: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test\n\
    \ * See: https://miller-rabin.appspot.com\n */\nconstexpr bool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d >>= 1;\n    constexpr std::array<ll, 7> prime = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n    for (long long p : prime) {\n    \
    \    long long t = d;\n        long long y = mod_pow(p, t, n);\n        while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n       \
    \     t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n         \
    \   return false;\n        }\n    }\n    return true;\n}\n}  // namespace bys\n\
    /**\n * @file modint.hpp\n * @author bayashi_cl\n * @brief Modint\n */\nnamespace\
    \ bys {\n/**\n * @brief ModInt\n *\n * ac-library\u306Emodint\u3092constexpr\u5316\
    \u3057\u305F\u3082\u306E\n * See: https://atcoder.github.io/ac-library/document_ja/modint.html\n\
    \ *\n * @tparam Modulo (\u4ECA\u306E\u6240)\u7D20\u6570\n * @todo \u975E\u7D20\
    \u6570mod\u3078\u306E\u5BFE\u5FDC\n */\ntemplate <unsigned int Modulo>\nclass\
    \ ModInt {\n    unsigned int _v;\n\n   public:\n    static constexpr unsigned\
    \ int mod = Modulo;\n    static_assert(is_prime(mod), \"Modulo need to be prime.\"\
    );\n    static_assert(mod < (std::numeric_limits<unsigned int>::max() >> 1), \"\
    Modulo need to be <2^31.\");\n\n    constexpr ModInt() noexcept : _v(0) {}\n \
    \   template <class T, std::enable_if_t<std::is_unsigned_v<T>, std::nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T v) noexcept : _v(v % mod) {}\n    template\
    \ <class T, std::enable_if_t<std::is_signed_v<T>, std::nullptr_t> = nullptr>\n\
    \    constexpr ModInt(T v) noexcept : _v(floormod(v, mod)) {}\n\n    constexpr\
    \ ModInt pow(ll n) const noexcept {\n        ModInt res = 1, p = *this;\n    \
    \    while (n) {\n            if (n & 1) res *= p;\n            p *= p;\n    \
    \        n >>= 1;\n        }\n        return res;\n    }\n    constexpr ModInt\
    \ inv() const noexcept { return pow(mod - 2); }\n\n    constexpr ModInt& operator+=(const\
    \ ModInt rhs) noexcept {\n        _v += rhs._v;\n        if (_v >= mod) _v -=\
    \ mod;\n        return *this;\n    }\n    constexpr ModInt& operator-=(const ModInt\
    \ rhs) noexcept {\n        if (rhs._v > _v) _v += mod;\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt rhs)\
    \ noexcept {\n        unsigned long long z = _v;\n        z *= rhs._v;\n     \
    \   _v = (unsigned int)(z % mod);\n        return *this;\n    }\n    constexpr\
    \ ModInt& operator/=(const ModInt rhs) noexcept { return *this = *this * rhs.inv();\
    \ }\n\n    constexpr ModInt& operator+() const noexcept { return *this; }\n  \
    \  constexpr ModInt& operator-() const noexcept { return ModInt() - *this; }\n\
    \    constexpr ModInt& operator++() noexcept {\n        _v++;\n        if (_v\
    \ == mod) _v = 0;\n        return *this;\n    }\n    constexpr ModInt& operator--()\
    \ noexcept {\n        if (_v == 0) _v = mod;\n        --_v;\n        return *this;\n\
    \    }\n    constexpr ModInt operator++(int) noexcept {\n        ModInt res =\
    \ *this;\n        ++*this;\n        return res;\n    }\n    constexpr ModInt operator--(int)\
    \ noexcept {\n        ModInt res = *this;\n        --*this;\n        return res;\n\
    \    }\n\n    friend constexpr ModInt operator+(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend constexpr ModInt operator-(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }\n  \
    \  friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) *= rhs; }\n    friend constexpr ModInt operator/(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }\n  \
    \  friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return lhs._v == rhs._v; }\n    friend constexpr bool operator!=(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return lhs._v != rhs._v; }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& m) noexcept { return is >>\
    \ m._v; }\n    friend std::ostream& operator<<(std::ostream& os, const ModInt&\
    \ m) noexcept { return os << m._v; }\n};\nusing Mint = ModInt<998244353>;\nusing\
    \ Mint7 = ModInt<1000000007>;\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"prime.hpp\"\n/**\n\
    \ * @file modint.hpp\n * @author bayashi_cl\n * @brief Modint\n */\nnamespace\
    \ bys {\n/**\n * @brief ModInt\n *\n * ac-library\u306Emodint\u3092constexpr\u5316\
    \u3057\u305F\u3082\u306E\n * See: https://atcoder.github.io/ac-library/document_ja/modint.html\n\
    \ *\n * @tparam Modulo (\u4ECA\u306E\u6240)\u7D20\u6570\n * @todo \u975E\u7D20\
    \u6570mod\u3078\u306E\u5BFE\u5FDC\n */\ntemplate <unsigned int Modulo>\nclass\
    \ ModInt {\n    unsigned int _v;\n\n   public:\n    static constexpr unsigned\
    \ int mod = Modulo;\n    static_assert(is_prime(mod), \"Modulo need to be prime.\"\
    );\n    static_assert(mod < (std::numeric_limits<unsigned int>::max() >> 1), \"\
    Modulo need to be <2^31.\");\n\n    constexpr ModInt() noexcept : _v(0) {}\n \
    \   template <class T, std::enable_if_t<std::is_unsigned_v<T>, std::nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T v) noexcept : _v(v % mod) {}\n    template\
    \ <class T, std::enable_if_t<std::is_signed_v<T>, std::nullptr_t> = nullptr>\n\
    \    constexpr ModInt(T v) noexcept : _v(floormod(v, mod)) {}\n\n    constexpr\
    \ ModInt pow(ll n) const noexcept {\n        ModInt res = 1, p = *this;\n    \
    \    while (n) {\n            if (n & 1) res *= p;\n            p *= p;\n    \
    \        n >>= 1;\n        }\n        return res;\n    }\n    constexpr ModInt\
    \ inv() const noexcept { return pow(mod - 2); }\n\n    constexpr ModInt& operator+=(const\
    \ ModInt rhs) noexcept {\n        _v += rhs._v;\n        if (_v >= mod) _v -=\
    \ mod;\n        return *this;\n    }\n    constexpr ModInt& operator-=(const ModInt\
    \ rhs) noexcept {\n        if (rhs._v > _v) _v += mod;\n        _v -= rhs._v;\n\
    \        return *this;\n    }\n    constexpr ModInt& operator*=(const ModInt rhs)\
    \ noexcept {\n        unsigned long long z = _v;\n        z *= rhs._v;\n     \
    \   _v = (unsigned int)(z % mod);\n        return *this;\n    }\n    constexpr\
    \ ModInt& operator/=(const ModInt rhs) noexcept { return *this = *this * rhs.inv();\
    \ }\n\n    constexpr ModInt& operator+() const noexcept { return *this; }\n  \
    \  constexpr ModInt& operator-() const noexcept { return ModInt() - *this; }\n\
    \    constexpr ModInt& operator++() noexcept {\n        _v++;\n        if (_v\
    \ == mod) _v = 0;\n        return *this;\n    }\n    constexpr ModInt& operator--()\
    \ noexcept {\n        if (_v == 0) _v = mod;\n        --_v;\n        return *this;\n\
    \    }\n    constexpr ModInt operator++(int) noexcept {\n        ModInt res =\
    \ *this;\n        ++*this;\n        return res;\n    }\n    constexpr ModInt operator--(int)\
    \ noexcept {\n        ModInt res = *this;\n        --*this;\n        return res;\n\
    \    }\n\n    friend constexpr ModInt operator+(const ModInt& lhs, const ModInt&\
    \ rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend constexpr ModInt operator-(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }\n  \
    \  friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return ModInt(lhs) *= rhs; }\n    friend constexpr ModInt operator/(const\
    \ ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }\n  \
    \  friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept\
    \ { return lhs._v == rhs._v; }\n    friend constexpr bool operator!=(const ModInt&\
    \ lhs, const ModInt& rhs) noexcept { return lhs._v != rhs._v; }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, ModInt& m) noexcept { return is >>\
    \ m._v; }\n    friend std::ostream& operator<<(std::ostream& os, const ModInt&\
    \ m) noexcept { return os << m._v; }\n};\nusing Mint = ModInt<998244353>;\nusing\
    \ Mint7 = ModInt<1000000007>;\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - math/prime.hpp
  - math/numeric.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: Modint
---
