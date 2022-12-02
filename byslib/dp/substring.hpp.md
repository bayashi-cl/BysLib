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
    links: []
  bundledCode: "#include <string>\n#include <vector>\n\n#include <cstdint>\nnamespace\
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
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n\nnamespace bys {\ni32 count_substring(const\
    \ std::string& s, i32 mod = 998244353) {\n    i32 n = s.length();\n    std::vector\
    \ next_char_pos(n + 1, std::vector(26, n));\n    for (i32 i = n - 1; i >= 0; --i)\
    \ {\n        for (i32 j = 0; j < 26; ++j) next_char_pos[i][j] = next_char_pos[i\
    \ + 1][j];\n        next_char_pos[i][s[i] - 'a'] = i;\n    }\n    std::vector<i32>\
    \ dp(n + 1);\n    dp[0] = 1;\n    for (i32 i = 0; i < n; ++i) {\n        for (i32\
    \ c = 0; c < 26; ++c) {\n            if (auto p = next_char_pos[i][c]; p < n)\
    \ {\n                dp[p + 1] += dp[i];\n                if (dp[p + 1] >= mod)\
    \ dp[p + 1] -= mod;\n            }\n        }\n    }\n    i32 res = 0;\n    for\
    \ (i32 i = 0; i <= n; ++i) {\n        res += dp[i];\n        if (res >= mod) res\
    \ -= mod;\n    }\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\n#include \"../core/int_alias.hpp\"\
    \n\nnamespace bys {\ni32 count_substring(const std::string& s, i32 mod = 998244353)\
    \ {\n    i32 n = s.length();\n    std::vector next_char_pos(n + 1, std::vector(26,\
    \ n));\n    for (i32 i = n - 1; i >= 0; --i) {\n        for (i32 j = 0; j < 26;\
    \ ++j) next_char_pos[i][j] = next_char_pos[i + 1][j];\n        next_char_pos[i][s[i]\
    \ - 'a'] = i;\n    }\n    std::vector<i32> dp(n + 1);\n    dp[0] = 1;\n    for\
    \ (i32 i = 0; i < n; ++i) {\n        for (i32 c = 0; c < 26; ++c) {\n        \
    \    if (auto p = next_char_pos[i][c]; p < n) {\n                dp[p + 1] +=\
    \ dp[i];\n                if (dp[p + 1] >= mod) dp[p + 1] -= mod;\n          \
    \  }\n        }\n    }\n    i32 res = 0;\n    for (i32 i = 0; i <= n; ++i) {\n\
    \        res += dp[i];\n        if (res >= mod) res -= mod;\n    }\n    return\
    \ res;\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/dp/substring.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/dp/substring.hpp
layout: document
redirect_from:
- /library/byslib/dp/substring.hpp
- /library/byslib/dp/substring.hpp.html
title: byslib/dp/substring.hpp
---
