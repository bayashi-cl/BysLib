---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: Const
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/combination.test.cpp
    title: test/math/combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binomial Coefficient
    links:
    - https://drken1215.hatenablog.com/entry/2018/06/08/210000
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
    \ bys\n/**\n * @file const.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr\
    \ int MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\nconstexpr int INF =\
    \ std::numeric_limits<int>::max() / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max()\
    \ / 2;\n}  // namespace bys\n/**\n * @file combination.hpp\n * @brief Binomial\
    \ Coefficient\n */\nnamespace bys {\n/**\n * @brief \u8907\u6570\u30AF\u30A8\u30EA\
    \u4E8C\u9805\u4FC2\u6570\n *\n * \u524D\u51E6\u7406 O(n)\n * \u30AF\u30A8\u30EA\
    \ O(1)\n * See: https://drken1215.hatenablog.com/entry/2018/06/08/210000\n */\n\
    struct MultiComb {\n    int _n;\n    int mod;\n    std::vector<ll> fact, factinv,\
    \ inv;\n\n    MultiComb(int n, int mod = MOD) : _n(n), mod(mod) {\n        fact.resize(_n\
    \ + 1);\n        factinv.resize(_n + 1);\n        inv.resize(_n + 1);\n\n    \
    \    fact[0] = fact[1] = 1;\n        factinv[0] = factinv[1] = 1;\n        inv[1]\
    \ = 1;\n\n        for (int i = 2; i <= _n; i++) {\n            fact[i] = fact[i\
    \ - 1] * i % mod;\n            inv[i] = mod - inv[mod % i] * (mod / i) % mod;\n\
    \            factinv[i] = factinv[i - 1] * inv[i] % mod;\n        }\n    }\n\n\
    \    ll comb(int n, int r) {\n        if (r < 0 || n < r) return 0;\n        return\
    \ fact[n] * (factinv[r] * factinv[n - r] % mod) % mod;\n    }\n    ll perm(int\
    \ n, int r) {\n        if (r < 0 || n < r) return 0;\n        return fact[n] *\
    \ factinv[n - r] % mod;\n    }\n    ll hom(int n, int r) {\n        if (n == 0\
    \ && r == 0) return 1;\n        return comb(n + r - 1, r);\n    }\n};\n\n/**\n\
    \ * @brief nCr\n *\n * O(min(n, (n - r)))\n *\n * @param n Modint\u3082\u6E21\u305B\
    \u308B\n */\ntemplate <class T>\nconstexpr T comb(T n, int r) {\n    T num = 1,\
    \ den = 1;\n    for (int i = 0; i < r; ++i) {\n        num *= n - i;\n       \
    \ den *= i + 1;\n    }\n    return num / den;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/const.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n/**\n * @file combination.hpp\n * @brief Binomial Coefficient\n */\nnamespace\
    \ bys {\n/**\n * @brief \u8907\u6570\u30AF\u30A8\u30EA\u4E8C\u9805\u4FC2\u6570\
    \n *\n * \u524D\u51E6\u7406 O(n)\n * \u30AF\u30A8\u30EA O(1)\n * See: https://drken1215.hatenablog.com/entry/2018/06/08/210000\n\
    \ */\nstruct MultiComb {\n    int _n;\n    int mod;\n    std::vector<ll> fact,\
    \ factinv, inv;\n\n    MultiComb(int n, int mod = MOD) : _n(n), mod(mod) {\n \
    \       fact.resize(_n + 1);\n        factinv.resize(_n + 1);\n        inv.resize(_n\
    \ + 1);\n\n        fact[0] = fact[1] = 1;\n        factinv[0] = factinv[1] = 1;\n\
    \        inv[1] = 1;\n\n        for (int i = 2; i <= _n; i++) {\n            fact[i]\
    \ = fact[i - 1] * i % mod;\n            inv[i] = mod - inv[mod % i] * (mod / i)\
    \ % mod;\n            factinv[i] = factinv[i - 1] * inv[i] % mod;\n        }\n\
    \    }\n\n    ll comb(int n, int r) {\n        if (r < 0 || n < r) return 0;\n\
    \        return fact[n] * (factinv[r] * factinv[n - r] % mod) % mod;\n    }\n\
    \    ll perm(int n, int r) {\n        if (r < 0 || n < r) return 0;\n        return\
    \ fact[n] * factinv[n - r] % mod;\n    }\n    ll hom(int n, int r) {\n       \
    \ if (n == 0 && r == 0) return 1;\n        return comb(n + r - 1, r);\n    }\n\
    };\n\n/**\n * @brief nCr\n *\n * O(min(n, (n - r)))\n *\n * @param n Modint\u3082\
    \u6E21\u305B\u308B\n */\ntemplate <class T>\nconstexpr T comb(T n, int r) {\n\
    \    T num = 1, den = 1;\n    for (int i = 0; i < r; ++i) {\n        num *= n\
    \ - i;\n        den *= i + 1;\n    }\n    return num / den;\n}\n}  // namespace\
    \ bys\n"
  dependsOn:
  - core/const.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/combination.test.cpp
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: Binomial Coefficient
---
