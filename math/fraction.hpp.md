---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6709\u7406\u6570"
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\nnamespace bys {\n//! @brief \u6709\u7406\u6570\nstruct Fraction {\n   \
    \ // numerator / denominator\n    ll numerator, denominator;\n    Fraction() :\
    \ numerator(0), denominator(1) {}\n    Fraction(ll num, ll den) {\n        assert(den\
    \ != 0);\n        if (num == 0) {\n            numerator = 0;\n            denominator\
    \ = 1;\n        } else {\n            if (den < 0) num *= -1;\n            ll\
    \ g = std::gcd(num, den);\n            numerator = num;\n            denominator\
    \ = den;\n            reduction();\n        }\n    }\n    bool reduction() {\n\
    \        ll g = std::gcd(numerator, denominator);\n        if (g == 1) return\
    \ false;\n        numerator /= g;\n        denominator /= g;\n        return true;\n\
    \    }\n    operator ld() const { return (ld)numerator / denominator; }\n    Fraction\
    \ operator+(const Fraction& rh) const {\n        return Fraction(numerator * rh.denominator\
    \ + rh.numerator * denominator, denominator * rh.denominator);\n    }\n    Fraction\
    \ operator+(const ll rh) const { return *this + Fraction(rh, 1); }\n    Fraction\
    \ operator+=(const Fraction& rh) {\n        *this = *this + rh;\n        return\
    \ *this;\n    }\n    Fraction operator+=(const ll rh) {\n        *this = *this\
    \ + rh;\n        return *this;\n    }\n    Fraction operator-(const Fraction&\
    \ rh) const {\n        return Fraction(numerator * rh.denominator - rh.numerator\
    \ * denominator, denominator * rh.denominator);\n    }\n    Fraction operator-(const\
    \ ll rh) const { return *this - Fraction(rh, 1); }\n    Fraction operator-=(const\
    \ Fraction& rh) {\n        *this = *this - rh;\n        return *this;\n    }\n\
    \    Fraction operator-=(const ll rh) {\n        *this = *this - rh;\n       \
    \ return *this;\n    }\n    Fraction operator*(const Fraction& rh) const { return\
    \ Fraction(numerator * rh.numerator, denominator * rh.denominator); }\n    Fraction\
    \ operator*(const ll rh) const { return Fraction(numerator * rh, denominator);\
    \ }\n    Fraction operator*=(const Fraction& rh) {\n        *this = *this * rh;\n\
    \        return *this;\n    }\n    Fraction operator*=(const ll rh) {\n      \
    \  *this = *this * rh;\n        return *this;\n    }\n    Fraction operator/(const\
    \ Fraction& rh) const { return Fraction(numerator * rh.denominator, denominator\
    \ * rh.numerator); }\n    Fraction operator/(const ll rh) const { return *this\
    \ * Fraction(1, rh); }\n    Fraction operator/=(const Fraction& rh) {\n      \
    \  *this = *this / rh;\n        return *this;\n    }\n    Fraction operator/=(const\
    \ ll rh) {\n        *this = *this / rh;\n        return *this;\n    }\n    bool\
    \ operator<(const Fraction& rh) const { return numerator * rh.denominator < rh.numerator\
    \ * denominator; }\n};\nstd::ostream& operator<<(std::ostream& os, const Fraction&\
    \ f) { return os << (ld)f; }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\n//! @brief\
    \ \u6709\u7406\u6570\nstruct Fraction {\n    // numerator / denominator\n    ll\
    \ numerator, denominator;\n    Fraction() : numerator(0), denominator(1) {}\n\
    \    Fraction(ll num, ll den) {\n        assert(den != 0);\n        if (num ==\
    \ 0) {\n            numerator = 0;\n            denominator = 1;\n        } else\
    \ {\n            if (den < 0) num *= -1;\n            ll g = std::gcd(num, den);\n\
    \            numerator = num;\n            denominator = den;\n            reduction();\n\
    \        }\n    }\n    bool reduction() {\n        ll g = std::gcd(numerator,\
    \ denominator);\n        if (g == 1) return false;\n        numerator /= g;\n\
    \        denominator /= g;\n        return true;\n    }\n    operator ld() const\
    \ { return (ld)numerator / denominator; }\n    Fraction operator+(const Fraction&\
    \ rh) const {\n        return Fraction(numerator * rh.denominator + rh.numerator\
    \ * denominator, denominator * rh.denominator);\n    }\n    Fraction operator+(const\
    \ ll rh) const { return *this + Fraction(rh, 1); }\n    Fraction operator+=(const\
    \ Fraction& rh) {\n        *this = *this + rh;\n        return *this;\n    }\n\
    \    Fraction operator+=(const ll rh) {\n        *this = *this + rh;\n       \
    \ return *this;\n    }\n    Fraction operator-(const Fraction& rh) const {\n \
    \       return Fraction(numerator * rh.denominator - rh.numerator * denominator,\
    \ denominator * rh.denominator);\n    }\n    Fraction operator-(const ll rh) const\
    \ { return *this - Fraction(rh, 1); }\n    Fraction operator-=(const Fraction&\
    \ rh) {\n        *this = *this - rh;\n        return *this;\n    }\n    Fraction\
    \ operator-=(const ll rh) {\n        *this = *this - rh;\n        return *this;\n\
    \    }\n    Fraction operator*(const Fraction& rh) const { return Fraction(numerator\
    \ * rh.numerator, denominator * rh.denominator); }\n    Fraction operator*(const\
    \ ll rh) const { return Fraction(numerator * rh, denominator); }\n    Fraction\
    \ operator*=(const Fraction& rh) {\n        *this = *this * rh;\n        return\
    \ *this;\n    }\n    Fraction operator*=(const ll rh) {\n        *this = *this\
    \ * rh;\n        return *this;\n    }\n    Fraction operator/(const Fraction&\
    \ rh) const { return Fraction(numerator * rh.denominator, denominator * rh.numerator);\
    \ }\n    Fraction operator/(const ll rh) const { return *this * Fraction(1, rh);\
    \ }\n    Fraction operator/=(const Fraction& rh) {\n        *this = *this / rh;\n\
    \        return *this;\n    }\n    Fraction operator/=(const ll rh) {\n      \
    \  *this = *this / rh;\n        return *this;\n    }\n    bool operator<(const\
    \ Fraction& rh) const { return numerator * rh.denominator < rh.numerator * denominator;\
    \ }\n};\nstd::ostream& operator<<(std::ostream& os, const Fraction& f) { return\
    \ os << (ld)f; }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: "\u6709\u7406\u6570"
---
