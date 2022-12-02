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
    document_title: Python::str
    links: []
  bundledCode: "#include <iomanip>\n#include <string>\n#include <vector>\n#include\
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
    \ bys\n/**\n * @file zfill.hpp\n * @brief Python::str\n *\n * Python\u518D\u73FE\
    \u30B7\u30EA\u30FC\u30BA str\u7DE8\n */\nnamespace bys {\n/**\n * @brief str.zfill()\n\
    \ * @param n \u57CB\u3081\u308B\u5BFE\u8C61\n * @param width \u5E45\n * @param\
    \ fill \u57CB\u3081\u308B\u6587\u5B57\n */\ntemplate <class T> std::string zfill(const\
    \ T& n, const i32 width, char fill = '0') {\n    std::stringstream ss;\n    ss\
    \ << std::setw(width) << std::setfill(fill) << n;\n    return ss.str();\n}\n/**\n\
    \ * @brief str.split()\n * @param s \u5206\u5272\u3059\u308B\u6587\u5B57\u5217\
    \n * @param delim \u533A\u5207\u308A\u6587\u5B57\n */\nstd::vector<std::string>\
    \ split(const std::string& s, char delim = ' ') {\n    std::vector<std::string>\
    \ res;\n    auto n = static_cast<i32>(s.length());\n    i32 left = 0;\n    for\
    \ (i32 i = 0; i < n; ++i) {\n        if (s[i] == delim) {\n            if (i !=\
    \ left) {\n                res.emplace_back(s.substr(left, i - left));\n     \
    \       }\n            left = i + 1;\n        }\n    }\n    if (left != n) res.emplace_back(s.substr(left,\
    \ n - left));\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <iomanip>\n#include <string>\n#include <vector>\n\
    #include \"../core/int_alias.hpp\"\n/**\n * @file zfill.hpp\n * @brief Python::str\n\
    \ *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA str\u7DE8\n */\nnamespace bys\
    \ {\n/**\n * @brief str.zfill()\n * @param n \u57CB\u3081\u308B\u5BFE\u8C61\n\
    \ * @param width \u5E45\n * @param fill \u57CB\u3081\u308B\u6587\u5B57\n */\n\
    template <class T> std::string zfill(const T& n, const i32 width, char fill =\
    \ '0') {\n    std::stringstream ss;\n    ss << std::setw(width) << std::setfill(fill)\
    \ << n;\n    return ss.str();\n}\n/**\n * @brief str.split()\n * @param s \u5206\
    \u5272\u3059\u308B\u6587\u5B57\u5217\n * @param delim \u533A\u5207\u308A\u6587\
    \u5B57\n */\nstd::vector<std::string> split(const std::string& s, char delim =\
    \ ' ') {\n    std::vector<std::string> res;\n    auto n = static_cast<i32>(s.length());\n\
    \    i32 left = 0;\n    for (i32 i = 0; i < n; ++i) {\n        if (s[i] == delim)\
    \ {\n            if (i != left) {\n                res.emplace_back(s.substr(left,\
    \ i - left));\n            }\n            left = i + 1;\n        }\n    }\n  \
    \  if (left != n) res.emplace_back(s.substr(left, n - left));\n    return res;\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/string/str.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/string/str.hpp
layout: document
redirect_from:
- /library/byslib/string/str.hpp
- /library/byslib/string/str.hpp.html
title: Python::str
---
