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
    document_title: Timer
    links: []
  bundledCode: "#include <chrono>\n\n#include <cstdint>\nnamespace bys {\nusing i8\
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
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n/**\n * @file timer.hpp\n * @brief\
    \ Timer\n */\nnamespace bys {\nstruct Timer {\n    std::chrono::time_point<std::chrono::system_clock>\
    \ end;\n    Timer(i32 ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);\
    \ }\n    inline bool counting() const { return std::chrono::system_clock::now()\
    \ <= end; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <chrono>\n\n#include \"../core/int_alias.hpp\"\n/**\n\
    \ * @file timer.hpp\n * @brief Timer\n */\nnamespace bys {\nstruct Timer {\n \
    \   std::chrono::time_point<std::chrono::system_clock> end;\n    Timer(i32 ms)\
    \ { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms); }\n\
    \    inline bool counting() const { return std::chrono::system_clock::now() <=\
    \ end; }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/extension/timer.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/timer.hpp
layout: document
redirect_from:
- /library/byslib/extension/timer.hpp
- /library/byslib/extension/timer.hpp.html
title: Timer
---
