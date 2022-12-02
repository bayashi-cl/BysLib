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
    document_title: Osa-k
    links:
    - https://osak.jp/diary/diary_201310.html#20131017
    - https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <map>\n#include\
    \ <numeric>\n#include <vector>\n#include <cstdint>\nnamespace bys {\nusing i8\
    \ = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing\
    \ u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n/**\n * @file osa_k.hpp\n * @brief\
    \ Osa-k\n */\nnamespace bys {\n/**\n * @brief osa_k\u6CD5\n *\n * \u7D20\u56E0\
    \u6570\u5206\u89E3\u3082\u3067\u304D\u308B\n * See: https://osak.jp/diary/diary_201310.html#20131017\n\
    \ * See: https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n *\n */\nstruct\
    \ Osa_K {\n    i32 mx;\n    std::vector<i32> spf;  // smallest prime factor\n\
    \    Osa_K(i32 n) : mx(n), spf(n + 1) {\n        std::iota(spf.begin(), spf.end(),\
    \ 0);\n        sieve();\n    }\n\n    void sieve() {\n        for (i32 i = 2;\
    \ i <= mx; i += 2) spf[i] = 2;\n        for (i32 p = 3; p * p <= mx; p += 2) {\n\
    \            if (spf[p] != p) continue;\n            for (i32 k = p * p; k <=\
    \ mx; k += p) {\n                if (spf[k] == k) spf[k] = p;\n            }\n\
    \        }\n    }\n    bool is_prime(i32 n) const {\n        assert(n <= mx);\n\
    \        if (n <= 1) return false;\n        return spf[n] == n;\n    }\n    std::map<i32,\
    \ i32> factorize(i32 n) const {\n        assert(n <= mx);\n        std::map<i32,\
    \ i32> res;\n        while (n > 1) {\n            res[spf[n]]++;\n           \
    \ n /= spf[n];\n        }\n        return res;\n    }\n    std::vector<i32> divisor(i32\
    \ n) const {\n        std::vector<i32> res;\n        std::map<i32, i32> factor_\
    \ = factorize(n);\n        std::vector<std::pair<i32, i32>> factor(factor_.begin(),\
    \ factor_.end());\n        i32 k = factor.size();\n        auto dfs = [&](auto\
    \ dfs, i32 depth, i32 prod) {\n            if (depth == k) {\n               \
    \ res.push_back(prod);\n                return;\n            }\n            auto\
    \ [p, q] = factor[depth];\n            for (i32 i = 0; i <= q; ++i) {\n      \
    \          dfs(dfs, depth + 1, prod);\n                prod *= p;\n          \
    \  }\n        };\n        dfs(dfs, 0, 1);\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <numeric>\n#include <vector>\n#include \"../core/int_alias.hpp\"\n/**\n\
    \ * @file osa_k.hpp\n * @brief Osa-k\n */\nnamespace bys {\n/**\n * @brief osa_k\u6CD5\
    \n *\n * \u7D20\u56E0\u6570\u5206\u89E3\u3082\u3067\u304D\u308B\n * See: https://osak.jp/diary/diary_201310.html#20131017\n\
    \ * See: https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n *\n */\nstruct\
    \ Osa_K {\n    i32 mx;\n    std::vector<i32> spf;  // smallest prime factor\n\
    \    Osa_K(i32 n) : mx(n), spf(n + 1) {\n        std::iota(spf.begin(), spf.end(),\
    \ 0);\n        sieve();\n    }\n\n    void sieve() {\n        for (i32 i = 2;\
    \ i <= mx; i += 2) spf[i] = 2;\n        for (i32 p = 3; p * p <= mx; p += 2) {\n\
    \            if (spf[p] != p) continue;\n            for (i32 k = p * p; k <=\
    \ mx; k += p) {\n                if (spf[k] == k) spf[k] = p;\n            }\n\
    \        }\n    }\n    bool is_prime(i32 n) const {\n        assert(n <= mx);\n\
    \        if (n <= 1) return false;\n        return spf[n] == n;\n    }\n    std::map<i32,\
    \ i32> factorize(i32 n) const {\n        assert(n <= mx);\n        std::map<i32,\
    \ i32> res;\n        while (n > 1) {\n            res[spf[n]]++;\n           \
    \ n /= spf[n];\n        }\n        return res;\n    }\n    std::vector<i32> divisor(i32\
    \ n) const {\n        std::vector<i32> res;\n        std::map<i32, i32> factor_\
    \ = factorize(n);\n        std::vector<std::pair<i32, i32>> factor(factor_.begin(),\
    \ factor_.end());\n        i32 k = factor.size();\n        auto dfs = [&](auto\
    \ dfs, i32 depth, i32 prod) {\n            if (depth == k) {\n               \
    \ res.push_back(prod);\n                return;\n            }\n            auto\
    \ [p, q] = factor[depth];\n            for (i32 i = 0; i <= q; ++i) {\n      \
    \          dfs(dfs, depth + 1, prod);\n                prod *= p;\n          \
    \  }\n        };\n        dfs(dfs, 0, 1);\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ntheory/osa_k.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/osa_k.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/osa_k.hpp
- /library/byslib/ntheory/osa_k.hpp.html
title: Osa-k
---
