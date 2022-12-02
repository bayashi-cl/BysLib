---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ItemSorter
    links: []
  bundledCode: "#include <utility>\n/**\n * @file itemsorter.hpp\n * @brief ItemSorter\n\
    \ *\n * sort\u95A2\u6570\u306E\u7B2C\u4E09\u5F15\u6570\u306B\u6E21\u3059\u3053\
    \u3068\u3067\"vector\u306E2\u756A\u76EE\u306E\u8981\u7D20\u3067\u30BD\u30FC\u30C8\
    \"\u3001\"pair\u306Esecond\n * \u3092\u57FA\u6E96\u3068\u3057\u3066\u30BD\u30FC\
    \u30C8\"\u7B49\u306E\u64CD\u4F5C\u304C\u3067\u304D\u308B\u3002\n */\nnamespace\
    \ bys {\n//! @brief Iterable\u306EI\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\
    \ntemplate <std::size_t I> struct ItemSorter {\n    template <class T> constexpr\
    \ bool operator()(const T& lh, const T& rh) const { return lh[I] < rh[I]; }\n\
    };\n\n//! @brief Tuple-like\u306EI\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\
    \ntemplate <std::size_t I> struct TupleSorter {\n    template <class T> bool operator()(const\
    \ T& lh, const T& rh) { return std::get<I>(lh) < std::get<I>(rh); }\n};\n\n//!\
    \ @brief std::pair\u3092second -> first\u306E\u9806\u3067\u6BD4\u8F03\nstruct\
    \ SecondSorter {\n    template <class T, class U> bool operator()(const std::pair<T,\
    \ U>& lh, const std::pair<T, U>& rh) {\n        return lh.second == rh.second\
    \ ? lh.first < rh.first : lh.second < rh.second;\n    }\n};\n\n/**\n * @def SORTBY(member)\n\
    \ * class\u3092\u30E1\u30F3\u30D0\u3067\u6BD4\u8F03\n */\n#define SORTBY(member)\
    \ [](const auto& a, const auto& b) { return a.member < b.member; }\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include <utility>\n/**\n * @file itemsorter.hpp\n * @brief\
    \ ItemSorter\n *\n * sort\u95A2\u6570\u306E\u7B2C\u4E09\u5F15\u6570\u306B\u6E21\
    \u3059\u3053\u3068\u3067\"vector\u306E2\u756A\u76EE\u306E\u8981\u7D20\u3067\u30BD\
    \u30FC\u30C8\"\u3001\"pair\u306Esecond\n * \u3092\u57FA\u6E96\u3068\u3057\u3066\
    \u30BD\u30FC\u30C8\"\u7B49\u306E\u64CD\u4F5C\u304C\u3067\u304D\u308B\u3002\n */\n\
    namespace bys {\n//! @brief Iterable\u306EI\u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u6BD4\u8F03\ntemplate <std::size_t I> struct ItemSorter {\n    template <class\
    \ T> constexpr bool operator()(const T& lh, const T& rh) const { return lh[I]\
    \ < rh[I]; }\n};\n\n//! @brief Tuple-like\u306EI\u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u6BD4\u8F03\ntemplate <std::size_t I> struct TupleSorter {\n    template\
    \ <class T> bool operator()(const T& lh, const T& rh) { return std::get<I>(lh)\
    \ < std::get<I>(rh); }\n};\n\n//! @brief std::pair\u3092second -> first\u306E\u9806\
    \u3067\u6BD4\u8F03\nstruct SecondSorter {\n    template <class T, class U> bool\
    \ operator()(const std::pair<T, U>& lh, const std::pair<T, U>& rh) {\n       \
    \ return lh.second == rh.second ? lh.first < rh.first : lh.second < rh.second;\n\
    \    }\n};\n\n/**\n * @def SORTBY(member)\n * class\u3092\u30E1\u30F3\u30D0\u3067\
    \u6BD4\u8F03\n */\n#define SORTBY(member) [](const auto& a, const auto& b) { return\
    \ a.member < b.member; }\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/itemsorter.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/itemsorter.hpp
layout: document
redirect_from:
- /library/byslib/extension/itemsorter.hpp
- /library/byslib/extension/itemsorter.hpp.html
title: ItemSorter
---
