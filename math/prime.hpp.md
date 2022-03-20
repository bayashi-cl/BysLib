---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':question:'
    path: math/bit.hpp
    title: math/bit.hpp
  - icon: ':heavy_check_mark:'
    path: math/numeric.hpp
    title: math/numeric.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/prime.test.cpp
    title: test/math/prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Miller-Rabin
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
    \ bys\n\nnamespace bys {\ntemplate <class T>\nint bit_width(T x) {\n    int bits\
    \ = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n   \
    \ return bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x >= 0);\n\
    \    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class T>\n\
    T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x\
    \ - 1);\n}\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n == 0) return \"\
    0\";\n    string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1'\
    \ : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\n\
    inline bool pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n\
    \nnamespace bys {\nconstexpr ll int_pow(int a, int b) {\n    ll res = 1;\n   \
    \ for (int i = 0; i < b; ++i) res *= a;\n    return res;\n}\ntemplate <class T>\n\
    T mod_pow(T p, T q, T mod) {\n    T res = 1 % mod;\n    p %= mod;\n    for (;\
    \ q; q >>= 1) {\n        if (q & 1) res = res * p % mod;\n        p = p * p %\
    \ mod;\n    }\n    return res;\n}\nll ceildiv(ll x, ll y) { return x > 0 ? (x\
    \ + y - 1) / y : x / y; }\nll floordiv(ll x, ll y) { return x > 0 ? x / y : (x\
    \ - y + 1) / y; }\npair<ll, ll> divmod(ll x, ll y) {\n    ll q = floordiv(x, y);\n\
    \    return {q, x - q * y};\n}\n\nll isqrt_aux(ll c, ll n) {\n    if (c == 0)\
    \ return 1;\n    ll k = (c - 1) / 2;\n    ll a = isqrt_aux(c / 2, n >> (2 * k\
    \ + 2));\n    return (a << k) + (n >> (k + 2)) / a;\n}\nll isqrt(ll n) {\n   \
    \ assert(n >= 0);\n    if (n == 0) return 0;\n    ll a = isqrt_aux((bit_width(n)\
    \ - 1) / 2, n);\n    return n < a * a ? a - 1 : a;\n}\ntemplate <class T, typename\
    \ std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>\ninline\
    \ bool isclose(T x, T y, T coef = 4.0) {\n    if (x == y) return true;\n    auto\
    \ diff = std::abs(x - y);\n    return diff <= std::numeric_limits<T>::epsilon()\
    \ * std::abs(x + y) * coef || diff < std::numeric_limits<T>::min();\n}\n}  //\
    \ namespace bys\nnamespace bys {\ntemplate <typename T>\nvector<T> prime_factorize(T\
    \ n) {\n    vector<T> res;\n    while (n % 2 == 0) {\n        res.push_back(2);\n\
    \        n /= 2;\n    }\n    T f = 3;\n    while (f * f <= n) {\n        if (n\
    \ % f == 0) {\n            res.push_back(f);\n            n /= f;\n        } else\
    \ {\n            f += 2;\n        }\n    }\n    if (n != 1) res.push_back(n);\n\
    \    return res;\n}\n//! @brief Miller-Rabin\nbool is_prime(ll n) {\n    if (n\
    \ <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return\
    \ false;\n    std::array<ll, 7> prime = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n    ll s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n\
    \        d >>= 1;\n    }\n    for (auto p : prime) {\n        if (p % n == 0)\
    \ return true;\n        ll t, x = mod_pow<__int128_t>(p, d, n);\n        if (x\
    \ != 1) {\n            for (t = 0; t < s; ++t) {\n                if (x == n -\
    \ 1) break;\n                x = __int128_t(x) * x % n;\n            }\n     \
    \       if (t == s) return false;\n        }\n    }\n    return true;\n}\n}  //\
    \ namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"numeric.hpp\"\n\
    namespace bys {\ntemplate <typename T>\nvector<T> prime_factorize(T n) {\n   \
    \ vector<T> res;\n    while (n % 2 == 0) {\n        res.push_back(2);\n      \
    \  n /= 2;\n    }\n    T f = 3;\n    while (f * f <= n) {\n        if (n % f ==\
    \ 0) {\n            res.push_back(f);\n            n /= f;\n        } else {\n\
    \            f += 2;\n        }\n    }\n    if (n != 1) res.push_back(n);\n  \
    \  return res;\n}\n//! @brief Miller-Rabin\nbool is_prime(ll n) {\n    if (n <=\
    \ 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n\
    \    std::array<ll, 7> prime = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \    ll s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n        d >>=\
    \ 1;\n    }\n    for (auto p : prime) {\n        if (p % n == 0) return true;\n\
    \        ll t, x = mod_pow<__int128_t>(p, d, n);\n        if (x != 1) {\n    \
    \        for (t = 0; t < s; ++t) {\n                if (x == n - 1) break;\n \
    \               x = __int128_t(x) * x % n;\n            }\n            if (t ==\
    \ s) return false;\n        }\n    }\n    return true;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - math/numeric.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: Miller-Rabin
---
