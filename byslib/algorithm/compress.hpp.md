---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/algorithm/inversion.hpp
    title: byslib/algorithm/inversion.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Coordinate Compression
    links: []
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <vector>\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
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
    }  // namespace bys\n/**\n * @file compress.hpp\n * @brief Coordinate Compression\n\
    \ *\n * \u5EA7\u6A19\u5727\u7E2E\n */\nnamespace bys {\n/**\n * @brief \u5EA7\u6A19\
    \u5727\u7E2E\n */\ntemplate <class T> class Compress {\n    std::vector<T> cp;\n\
    \    Compress(std::vector<T> const& v) : cp(v) {\n        sort(std::begin(cp),\
    \ std::end(cp));\n        cp.erase(std::unique(std::begin(cp), std::end(cp)),\
    \ cp.end());\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\u305F\u5024\u3092\
    \u53D6\u5F97 O(log N)\n    i32 get(T v) const {\n        auto itr = std::lower_bound(std::begin(cp),\
    \ std::end(cp), v);\n        assert(*itr == v);\n        return std::distance(cp.begin(),\
    \ itr);\n    }\n\n    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\
    \u5F97 O(1)\n    T unzip(i32 i) const { return cp[i]; }\n    std::size_t size()\
    \ const { return cp.size(); }\n    std::ptrdiff_t ssize() const { return cp.size();\
    \ }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n\
    #include <vector>\n#include \"../core/int_alias.hpp\"\n/**\n * @file compress.hpp\n\
    \ * @brief Coordinate Compression\n *\n * \u5EA7\u6A19\u5727\u7E2E\n */\nnamespace\
    \ bys {\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n */\ntemplate <class T> class\
    \ Compress {\n    std::vector<T> cp;\n    Compress(std::vector<T> const& v) :\
    \ cp(v) {\n        sort(std::begin(cp), std::end(cp));\n        cp.erase(std::unique(std::begin(cp),\
    \ std::end(cp)), cp.end());\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\u305F\
    \u5024\u3092\u53D6\u5F97 O(log N)\n    i32 get(T v) const {\n        auto itr\
    \ = std::lower_bound(std::begin(cp), std::end(cp), v);\n        assert(*itr ==\
    \ v);\n        return std::distance(cp.begin(), itr);\n    }\n\n    //! @brief\
    \ \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\u5F97 O(1)\n    T unzip(i32\
    \ i) const { return cp[i]; }\n    std::size_t size() const { return cp.size();\
    \ }\n    std::ptrdiff_t ssize() const { return cp.size(); }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/algorithm/compress.hpp
  requiredBy:
  - byslib/algorithm/inversion.hpp
  timestamp: '2022-12-02 16:15:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/algorithm/compress.hpp
layout: document
redirect_from:
- /library/byslib/algorithm/compress.hpp
- /library/byslib/algorithm/compress.hpp.html
title: Coordinate Compression
---
