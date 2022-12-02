---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#include <random>\n#include <string>\n#include <vector>\n\n#include\
    \ <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\nnamespace bys {\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\n *\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ *\n */\nclass RollingHash {\n    static constexpr u64 mod = (1UL << 61) - 1;\n\
    \    static inline const u64 base = []() {\n        std::random_device seed_gen;\n\
    \        std::mt19937 engine(seed_gen());\n        return engine();\n    }();\n\
    \    static inline std::vector<u64> base_pow = {1};\n\n    std::vector<u64> _hash;\n\
    \n  public:\n    RollingHash(std::string const& s) : _hash(s.length() + 1) {\n\
    \        extend_base(s.length());\n        for (i32 i = 0, n = (i32)s.length();\
    \ i < n; ++i) {\n            _hash[i + 1] = modmul(_hash[i], base) + s[i] + 1;\n\
    \            if (_hash[i + 1] >= mod) _hash[i + 1] -= mod;\n        }\n    }\n\
    \n    u64 hash(i32 l, i32 r) const {\n        u64 res = mod + _hash[r] - modmul(_hash[l],\
    \ base_pow[r - l]);\n        return res < mod ? res : res - mod;\n    }\n\n  private:\n\
    \    void extend_base(i32 n) {\n        while ((i32)base_pow.size() < n) {\n \
    \           base_pow.push_back(modmul(base_pow.back(), base));\n        }\n  \
    \  }\n\n    u64 modmul(i128 a, i128 b) const {\n        i128 t = a * b;\n    \
    \    t = (t >> 61) + (t & mod);\n        if (t >= mod) return t - mod;\n     \
    \   return t;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <random>\n#include <string>\n#include <vector>\n\n\
    #include \"../core/int_alias.hpp\"\nnamespace bys {\n/**\n * @brief \u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n *\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ *\n */\nclass RollingHash {\n    static constexpr u64 mod = (1UL << 61) - 1;\n\
    \    static inline const u64 base = []() {\n        std::random_device seed_gen;\n\
    \        std::mt19937 engine(seed_gen());\n        return engine();\n    }();\n\
    \    static inline std::vector<u64> base_pow = {1};\n\n    std::vector<u64> _hash;\n\
    \n  public:\n    RollingHash(std::string const& s) : _hash(s.length() + 1) {\n\
    \        extend_base(s.length());\n        for (i32 i = 0, n = (i32)s.length();\
    \ i < n; ++i) {\n            _hash[i + 1] = modmul(_hash[i], base) + s[i] + 1;\n\
    \            if (_hash[i + 1] >= mod) _hash[i + 1] -= mod;\n        }\n    }\n\
    \n    u64 hash(i32 l, i32 r) const {\n        u64 res = mod + _hash[r] - modmul(_hash[l],\
    \ base_pow[r - l]);\n        return res < mod ? res : res - mod;\n    }\n\n  private:\n\
    \    void extend_base(i32 n) {\n        while ((i32)base_pow.size() < n) {\n \
    \           base_pow.push_back(modmul(base_pow.back(), base));\n        }\n  \
    \  }\n\n    u64 modmul(i128 a, i128 b) const {\n        i128 t = a * b;\n    \
    \    t = (t >> 61) + (t & mod);\n        if (t >= mod) return t - mod;\n     \
    \   return t;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/string/rollinghash.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/string/rollinghash.hpp
layout: document
redirect_from:
- /library/byslib/string/rollinghash.hpp
- /library/byslib/string/rollinghash.hpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
