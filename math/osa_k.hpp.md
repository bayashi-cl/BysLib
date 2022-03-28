---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: test/math/osa_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Osa-k
    links:
    - https://osak.jp/diary/diary_201310.html#20131017
    - https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
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
    \ T>;\n}  // namespace bys\n/**\n * @file osa_k.hpp\n * @author bayashi_cl\n *\
    \ @brief Osa-k\n */\nnamespace bys {\n/**\n * @brief osa_k\u6CD5\n *\n * \u7D20\
    \u56E0\u6570\u5206\u89E3\u3082\u3067\u304D\u308B\n * See: https://osak.jp/diary/diary_201310.html#20131017\n\
    \ * See: https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n *\n * @todo\
    \ c++20\u3067vector\u3082constexpr\u5316\u3067\u304D\u308B\u3088\u3046\u306B\u306A\
    \u308B\n */\nstruct Osa_K {\n    int mx;\n    vector<int> spf;  // smallest prime\
    \ factor\n    Osa_K(int n) : mx(n), spf(n + 1) {\n        std::iota(spf.begin(),\
    \ spf.end(), 0);\n        sieve();\n    }\n\n    void sieve() {\n        for (int\
    \ i = 2; i <= mx; i += 2) spf[i] = 2;\n        for (int p = 3; p * p <= mx; p\
    \ += 2) {\n            if (spf[p] != p) continue;\n            for (int k = p\
    \ * p; k <= mx; k += p) {\n                if (spf[k] == k) spf[k] = p;\n    \
    \        }\n        }\n    }\n    bool is_prime(int n) const {\n        assert(n\
    \ <= mx);\n        if (n <= 1) return false;\n        return spf[n] == n;\n  \
    \  }\n    map<int, int> factorize(int n) const {\n        assert(n <= mx);\n \
    \       map<int, int> res;\n        while (n > 1) {\n            res[spf[n]]++;\n\
    \            n /= spf[n];\n        }\n        return res;\n    }\n    vector<int>\
    \ divisor(int n) const {\n        vector<int> res;\n        map<int, int> factor_\
    \ = factorize(n);\n        vector<pair<int, int>> factor(factor_.begin(), factor_.end());\n\
    \        int k = factor.size();\n        auto dfs = [&](auto dfs, int depth, int\
    \ prod) {\n            if (depth == k) {\n                res.push_back(prod);\n\
    \                return;\n            }\n            auto [p, q] = factor[depth];\n\
    \            for (int i = 0; i <= q; ++i) {\n                dfs(dfs, depth +\
    \ 1, prod);\n                prod *= p;\n            }\n        };\n        dfs(dfs,\
    \ 0, 1);\n        sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file osa_k.hpp\n\
    \ * @author bayashi_cl\n * @brief Osa-k\n */\nnamespace bys {\n/**\n * @brief\
    \ osa_k\u6CD5\n *\n * \u7D20\u56E0\u6570\u5206\u89E3\u3082\u3067\u304D\u308B\n\
    \ * See: https://osak.jp/diary/diary_201310.html#20131017\n * See: https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    \ *\n * @todo c++20\u3067vector\u3082constexpr\u5316\u3067\u304D\u308B\u3088\u3046\
    \u306B\u306A\u308B\n */\nstruct Osa_K {\n    int mx;\n    vector<int> spf;  //\
    \ smallest prime factor\n    Osa_K(int n) : mx(n), spf(n + 1) {\n        std::iota(spf.begin(),\
    \ spf.end(), 0);\n        sieve();\n    }\n\n    void sieve() {\n        for (int\
    \ i = 2; i <= mx; i += 2) spf[i] = 2;\n        for (int p = 3; p * p <= mx; p\
    \ += 2) {\n            if (spf[p] != p) continue;\n            for (int k = p\
    \ * p; k <= mx; k += p) {\n                if (spf[k] == k) spf[k] = p;\n    \
    \        }\n        }\n    }\n    bool is_prime(int n) const {\n        assert(n\
    \ <= mx);\n        if (n <= 1) return false;\n        return spf[n] == n;\n  \
    \  }\n    map<int, int> factorize(int n) const {\n        assert(n <= mx);\n \
    \       map<int, int> res;\n        while (n > 1) {\n            res[spf[n]]++;\n\
    \            n /= spf[n];\n        }\n        return res;\n    }\n    vector<int>\
    \ divisor(int n) const {\n        vector<int> res;\n        map<int, int> factor_\
    \ = factorize(n);\n        vector<pair<int, int>> factor(factor_.begin(), factor_.end());\n\
    \        int k = factor.size();\n        auto dfs = [&](auto dfs, int depth, int\
    \ prod) {\n            if (depth == k) {\n                res.push_back(prod);\n\
    \                return;\n            }\n            auto [p, q] = factor[depth];\n\
    \            for (int i = 0; i <= q; ++i) {\n                dfs(dfs, depth +\
    \ 1, prod);\n                prod *= p;\n            }\n        };\n        dfs(dfs,\
    \ 0, 1);\n        sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/osa_k.test.cpp
documentation_of: math/osa_k.hpp
layout: document
redirect_from:
- /library/math/osa_k.hpp
- /library/math/osa_k.hpp.html
title: Osa-k
---
