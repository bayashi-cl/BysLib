---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ItemSorter
    links: []
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
    \ bys\n/**\n * @file itemsorter.hpp\n * @brief ItemSorter\n *\n * sort\u95A2\u6570\
    \u306E\u7B2C\u4E09\u5F15\u6570\u306B\u6E21\u3059\u3053\u3068\u3067\"vector\u306E\
    2\u756A\u76EE\u306E\u8981\u7D20\u3067\u30BD\u30FC\u30C8\"\u3001\"pair\u306Esecond\n\
    \ * \u3092\u57FA\u6E96\u3068\u3057\u3066\u30BD\u30FC\u30C8\"\u7B49\u306E\u64CD\
    \u4F5C\u304C\u3067\u304D\u308B\u3002\n */\nnamespace bys {\n//! @brief Iterable\u306E\
    I\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\ntemplate <std::size_t I>\n\
    struct ItemSorter {\n    template <class T>\n    constexpr bool operator()(const\
    \ T& lh, const T& rh) const {\n        return lh[I] < rh[I];\n    }\n};\n\n//!\
    \ @brief Tuple-like\u306EI\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\ntemplate\
    \ <std::size_t I>\nstruct TupleSorter {\n    template <class T>\n    bool operator()(const\
    \ T& lh, const T& rh) {\n        return std::get<I>(lh) < std::get<I>(rh);\n \
    \   }\n};\n\n//! @brief std::pair\u3092second -> first\u306E\u9806\u3067\u6BD4\
    \u8F03\nstruct SecondSorter {\n    template <class T, class U>\n    bool operator()(const\
    \ std::pair<T, U>& lh, const std::pair<T, U>& rh) {\n        return lh.second\
    \ == rh.second ? lh.first < rh.first : lh.second < rh.second;\n    }\n};\n\n/**\n\
    \ * @def SORTBY(member)\n * class\u3092\u30E1\u30F3\u30D0\u3067\u6BD4\u8F03\n\
    \ */\n#define SORTBY(member) [](const auto& a, const auto& b) { return a.member\
    \ < b.member; }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file itemsorter.hpp\n\
    \ * @brief ItemSorter\n *\n * sort\u95A2\u6570\u306E\u7B2C\u4E09\u5F15\u6570\u306B\
    \u6E21\u3059\u3053\u3068\u3067\"vector\u306E2\u756A\u76EE\u306E\u8981\u7D20\u3067\
    \u30BD\u30FC\u30C8\"\u3001\"pair\u306Esecond\n * \u3092\u57FA\u6E96\u3068\u3057\
    \u3066\u30BD\u30FC\u30C8\"\u7B49\u306E\u64CD\u4F5C\u304C\u3067\u304D\u308B\u3002\
    \n */\nnamespace bys {\n//! @brief Iterable\u306EI\u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u6BD4\u8F03\ntemplate <std::size_t I>\nstruct ItemSorter {\n    template\
    \ <class T>\n    constexpr bool operator()(const T& lh, const T& rh) const {\n\
    \        return lh[I] < rh[I];\n    }\n};\n\n//! @brief Tuple-like\u306EI\u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\ntemplate <std::size_t I>\nstruct TupleSorter\
    \ {\n    template <class T>\n    bool operator()(const T& lh, const T& rh) {\n\
    \        return std::get<I>(lh) < std::get<I>(rh);\n    }\n};\n\n//! @brief std::pair\u3092\
    second -> first\u306E\u9806\u3067\u6BD4\u8F03\nstruct SecondSorter {\n    template\
    \ <class T, class U>\n    bool operator()(const std::pair<T, U>& lh, const std::pair<T,\
    \ U>& rh) {\n        return lh.second == rh.second ? lh.first < rh.first : lh.second\
    \ < rh.second;\n    }\n};\n\n/**\n * @def SORTBY(member)\n * class\u3092\u30E1\
    \u30F3\u30D0\u3067\u6BD4\u8F03\n */\n#define SORTBY(member) [](const auto& a,\
    \ const auto& b) { return a.member < b.member; }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/itemsorter.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/itemsorter.hpp
layout: document
redirect_from:
- /library/utility/itemsorter.hpp
- /library/utility/itemsorter.hpp.html
title: ItemSorter
---
