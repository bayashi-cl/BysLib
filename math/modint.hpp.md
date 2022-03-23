---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: math/bit.hpp
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: math/numeric.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: Miller-Rabin
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
    title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <cstdint>\n#include <iostream>\n#include <limits>\n#include\
    \ <type_traits>\n\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iterator>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\n\nnamespace bys {\ntemplate <class T>\nint bit_width(T\
    \ x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class\
    \ T>\nT bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) <<\
    \ bit_width(x - 1);\n}\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n ==\
    \ 0) return \"0\";\n    string res;\n    while (n > 0) {\n        res.push_back(n\
    \ & 1 ? '1' : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\n\
    inline bool pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n\
    \nnamespace bys {\nconstexpr ll int_pow(int a, int b) {\n    ll res = 1;\n   \
    \ for (int i = 0; i < b; ++i) res *= a;\n    return res;\n}\ntemplate <class T>\n\
    constexpr T mod_pow(T p, T q, T mod) {\n    T res = 1 % mod;\n    p %= mod;\n\
    \    for (; q; q >>= 1) {\n        if (q & 1) res = res * p % mod;\n        p\
    \ = p * p % mod;\n    }\n    return res;\n}\nll ceildiv(ll x, ll y) { return x\
    \ > 0 ? (x + y - 1) / y : x / y; }\nll floordiv(ll x, ll y) { return x > 0 ? x\
    \ / y : (x - y + 1) / y; }\npair<ll, ll> divmod(ll x, ll y) {\n    ll q = floordiv(x,\
    \ y);\n    return {q, x - q * y};\n}\ntemplate <class T, class S>\nconstexpr T\
    \ floormod(T x, S mod) {\n    x %= mod;\n    if (x < 0) x += mod;\n    return\
    \ x;\n}\n\nll isqrt_aux(ll c, ll n) {\n    if (c == 0) return 1;\n    ll k = (c\
    \ - 1) / 2;\n    ll a = isqrt_aux(c / 2, n >> (2 * k + 2));\n    return (a <<\
    \ k) + (n >> (k + 2)) / a;\n}\nll isqrt(ll n) {\n    assert(n >= 0);\n    if (n\
    \ == 0) return 0;\n    ll a = isqrt_aux((bit_width(n) - 1) / 2, n);\n    return\
    \ n < a * a ? a - 1 : a;\n}\ntemplate <class T, typename std::enable_if_t<std::is_floating_point_v<T>,\
    \ std::nullptr_t> = nullptr>\ninline bool isclose(T x, T y, T coef = 4.0) {\n\
    \    if (x == y) return true;\n    auto diff = std::abs(x - y);\n    return diff\
    \ <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n\
    }\n}  // namespace bys\nnamespace bys {\ntemplate <typename T>\nvector<T> prime_factorize(T\
    \ n) {\n    vector<T> res;\n    while (n % 2 == 0) {\n        res.push_back(2);\n\
    \        n /= 2;\n    }\n    T f = 3;\n    while (f * f <= n) {\n        if (n\
    \ % f == 0) {\n            res.push_back(f);\n            n /= f;\n        } else\
    \ {\n            f += 2;\n        }\n    }\n    if (n != 1) res.push_back(n);\n\
    \    return res;\n}\n\n//! @brief Miller-Rabin\nconstexpr bool is_prime(long long\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d >>= 1;\n    constexpr std::array<ll, 7> prime = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n    for (long long p : prime) {\n    \
    \    long long t = d;\n        long long y = mod_pow(p, t, n);\n        while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n            y = y * y % n;\n       \
    \     t <<= 1;\n        }\n        if (y != n - 1 && t % 2 == 0) {\n         \
    \   return false;\n        }\n    }\n    return true;\n}\n}  // namespace bys\n\
    namespace bys {\ntemplate <unsigned int Modulo>\nclass ModInt {\n    unsigned\
    \ int _v;\n\n   public:\n    static constexpr unsigned int mod = Modulo;\n   \
    \ static_assert(is_prime(mod), \"Modulo need to be prime.\");\n    static_assert(mod\
    \ < std::numeric_limits<unsigned int>::max(), \"Modulo need to <2^32\");\n\n \
    \   constexpr ModInt() noexcept : _v(0) {}\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>,\
    \ std::nullptr_t> = nullptr>\n    constexpr ModInt(T v) noexcept : _v(v % mod)\
    \ {}\n    template <class T, std::enable_if_t<std::is_signed_v<T>, std::nullptr_t>\
    \ = nullptr>\n    constexpr ModInt(T v) noexcept : _v(floormod(v, mod)) {}\n\n\
    \    constexpr ModInt pow(ll n) const noexcept {\n        ModInt res = 1, p =\
    \ *this;\n        while (n) {\n            if (n & 1) res *= p;\n            p\
    \ *= p;\n            n >>= 1;\n        }\n        return res;\n    }\n    constexpr\
    \ ModInt inv() const noexcept { return pow(mod - 2); }\n\n    constexpr ModInt&\
    \ operator+=(const ModInt rhs) noexcept {\n        _v += rhs._v;\n        if (_v\
    \ >= mod) _v -= mod;\n        return *this;\n    }\n    constexpr ModInt& operator-=(const\
    \ ModInt rhs) noexcept {\n        if (rhs._v > _v) _v += mod;\n        _v -= rhs._v;\n\
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
  code: "#pragma once\n#include <cstdint>\n#include <iostream>\n#include <limits>\n\
    #include <type_traits>\n\n#include \"prime.hpp\"\nnamespace bys {\ntemplate <unsigned\
    \ int Modulo>\nclass ModInt {\n    unsigned int _v;\n\n   public:\n    static\
    \ constexpr unsigned int mod = Modulo;\n    static_assert(is_prime(mod), \"Modulo\
    \ need to be prime.\");\n    static_assert(mod < std::numeric_limits<unsigned\
    \ int>::max(), \"Modulo need to <2^32\");\n\n    constexpr ModInt() noexcept :\
    \ _v(0) {}\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>, std::nullptr_t>\
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
  - math/prime.hpp
  - core/stdlib.hpp
  - math/numeric.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2022-03-23 17:02:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
