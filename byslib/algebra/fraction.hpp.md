---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fraction
    links: []
  bundledCode: "#include <cassert>\n#include <iostream>\n#include <numeric>\n#include\
    \ <utility>\n\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\n\
    using i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
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
    }  // namespace bys\n/**\n * @file fraction.hpp\n * @brief Fraction\n */\nnamespace\
    \ bys {\n//! @brief \u6709\u7406\u6570\nclass Fraction {\n    i64 numerator, denominator;\n\
    \n    bool reduction() {\n        i64 g = std::gcd(numerator, denominator);\n\
    \        if (g == 1) return false;\n        numerator /= g;\n        denominator\
    \ /= g;\n        return true;\n    }\n\n  public:\n    Fraction() : numerator(0),\
    \ denominator(1) {}\n    Fraction(i64 integer) : numerator(integer), denominator(1)\
    \ {}\n    Fraction(i64 num, i64 den) : numerator(num), denominator(den) {\n  \
    \      assert(denominator != 0);\n        if (numerator == 0) {\n            denominator\
    \ = 1;\n        } else if (denominator < 0) {\n            numerator *= -1;\n\
    \            denominator *= -1;\n        }\n        reduction();\n    }\n\n  \
    \  Fraction inv() const { return Fraction(denominator, numerator); }\n    operator\
    \ f128() const { return (f128)numerator / denominator; }\n    std::pair<i64, i64>\
    \ as_integer_ratio() { return {numerator, denominator}; }\n\n    Fraction& operator+=(Fraction\
    \ const& rhs) {\n        numerator = numerator * rhs.denominator + rhs.numerator\
    \ * denominator;\n        denominator *= rhs.denominator;\n        reduction();\n\
    \    }\n    Fraction& operator-=(Fraction const& rhs) {\n        numerator = numerator\
    \ * rhs.denominator - rhs.numerator * denominator;\n        denominator *= rhs.denominator;\n\
    \        reduction();\n    }\n    Fraction& operator*=(Fraction const& rhs) {\n\
    \        numerator *= rhs.numerator;\n        denominator *= rhs.denominator;\n\
    \        reduction();\n    }\n    Fraction& operator/=(Fraction const& rhs) {\
    \ *this *= rhs.inv(); }\n\n    template <class T> friend Fraction operator+(Fraction\
    \ const& rhs, Fraction const& lhs) { return Fraction(rhs) += lhs; }\n    template\
    \ <class T> friend Fraction operator-(Fraction const& rhs, Fraction const& lhs)\
    \ { return Fraction(rhs) -= lhs; }\n    template <class T> friend Fraction operator*(Fraction\
    \ const& rhs, Fraction const& lhs) { return Fraction(rhs) *= lhs; }\n    template\
    \ <class T> friend Fraction operator/(Fraction const& rhs, Fraction const& lhs)\
    \ { return Fraction(rhs) /= lhs; }\n\n    Fraction operator+() const { return\
    \ *this; }\n    Fraction operator-() const { return Fraction(-numerator, denominator);\
    \ }\n\n    Fraction& operator++() { numerator += denominator; }\n    Fraction&\
    \ operator--() { numerator -= denominator; }\n\n    Fraction operator++(int) {\n\
    \        auto temp = *this;\n        ++*this;\n        return temp;\n    }\n \
    \   Fraction operator--(int) {\n        auto temp = *this;\n        --*this;\n\
    \        return temp;\n    }\n\n    bool operator<(Fraction const& rhs) const\
    \ { return numerator * rhs.denominator < rhs.numerator * denominator; }\n};\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    #include <utility>\n\n#include \"../core/int_alias.hpp\"\n/**\n * @file fraction.hpp\n\
    \ * @brief Fraction\n */\nnamespace bys {\n//! @brief \u6709\u7406\u6570\nclass\
    \ Fraction {\n    i64 numerator, denominator;\n\n    bool reduction() {\n    \
    \    i64 g = std::gcd(numerator, denominator);\n        if (g == 1) return false;\n\
    \        numerator /= g;\n        denominator /= g;\n        return true;\n  \
    \  }\n\n  public:\n    Fraction() : numerator(0), denominator(1) {}\n    Fraction(i64\
    \ integer) : numerator(integer), denominator(1) {}\n    Fraction(i64 num, i64\
    \ den) : numerator(num), denominator(den) {\n        assert(denominator != 0);\n\
    \        if (numerator == 0) {\n            denominator = 1;\n        } else if\
    \ (denominator < 0) {\n            numerator *= -1;\n            denominator *=\
    \ -1;\n        }\n        reduction();\n    }\n\n    Fraction inv() const { return\
    \ Fraction(denominator, numerator); }\n    operator f128() const { return (f128)numerator\
    \ / denominator; }\n    std::pair<i64, i64> as_integer_ratio() { return {numerator,\
    \ denominator}; }\n\n    Fraction& operator+=(Fraction const& rhs) {\n       \
    \ numerator = numerator * rhs.denominator + rhs.numerator * denominator;\n   \
    \     denominator *= rhs.denominator;\n        reduction();\n    }\n    Fraction&\
    \ operator-=(Fraction const& rhs) {\n        numerator = numerator * rhs.denominator\
    \ - rhs.numerator * denominator;\n        denominator *= rhs.denominator;\n  \
    \      reduction();\n    }\n    Fraction& operator*=(Fraction const& rhs) {\n\
    \        numerator *= rhs.numerator;\n        denominator *= rhs.denominator;\n\
    \        reduction();\n    }\n    Fraction& operator/=(Fraction const& rhs) {\
    \ *this *= rhs.inv(); }\n\n    template <class T> friend Fraction operator+(Fraction\
    \ const& rhs, Fraction const& lhs) { return Fraction(rhs) += lhs; }\n    template\
    \ <class T> friend Fraction operator-(Fraction const& rhs, Fraction const& lhs)\
    \ { return Fraction(rhs) -= lhs; }\n    template <class T> friend Fraction operator*(Fraction\
    \ const& rhs, Fraction const& lhs) { return Fraction(rhs) *= lhs; }\n    template\
    \ <class T> friend Fraction operator/(Fraction const& rhs, Fraction const& lhs)\
    \ { return Fraction(rhs) /= lhs; }\n\n    Fraction operator+() const { return\
    \ *this; }\n    Fraction operator-() const { return Fraction(-numerator, denominator);\
    \ }\n\n    Fraction& operator++() { numerator += denominator; }\n    Fraction&\
    \ operator--() { numerator -= denominator; }\n\n    Fraction operator++(int) {\n\
    \        auto temp = *this;\n        ++*this;\n        return temp;\n    }\n \
    \   Fraction operator--(int) {\n        auto temp = *this;\n        --*this;\n\
    \        return temp;\n    }\n\n    bool operator<(Fraction const& rhs) const\
    \ { return numerator * rhs.denominator < rhs.numerator * denominator; }\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/algebra/fraction.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/algebra/fraction.hpp
layout: document
redirect_from:
- /library/byslib/algebra/fraction.hpp
- /library/byslib/algebra/fraction.hpp.html
title: Fraction
---
