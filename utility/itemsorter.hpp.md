---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "I\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03"
    links: []
  bundledCode: "#line 2 \"core/stdlib.hpp\"\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n#line 3 \"utility/itemsorter.hpp\"\n\nnamespace bys {\n//! @brief I\u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\ntemplate <class T, std::size_t I>\n\
    struct ItemSorter {\n    bool operator()(const T& lh, const T& rh) { return lh[I]\
    \ < rh[I]; }\n};\n//! @brief Tuple\u7CFB\u306EI\u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u6BD4\u8F03\ntemplate <class T, std::size_t I>\nstruct TupleSorter {\n    bool\
    \ operator()(const T& lh, const T& rh) { return std::get<I>(lh) < std::get<I>(rh);\
    \ }\n};\ntemplate <class T, class U>\nstruct SecondSorter {\n    bool operator()(const\
    \ std::pair<T, U>& lh, const std::pair<T, U>& rh) {\n        return lh.second\
    \ == rh.second ? lh.first < rh.first : lh.second < rh.second;\n    }\n};\n#define\
    \ SORTBY(method) [](const auto& a, const auto& b) { return a.method < b.method;\
    \ }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\n//! @brief\
    \ I\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03\ntemplate <class T, std::size_t\
    \ I>\nstruct ItemSorter {\n    bool operator()(const T& lh, const T& rh) { return\
    \ lh[I] < rh[I]; }\n};\n//! @brief Tuple\u7CFB\u306EI\u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u6BD4\u8F03\ntemplate <class T, std::size_t I>\nstruct TupleSorter {\n\
    \    bool operator()(const T& lh, const T& rh) { return std::get<I>(lh) < std::get<I>(rh);\
    \ }\n};\ntemplate <class T, class U>\nstruct SecondSorter {\n    bool operator()(const\
    \ std::pair<T, U>& lh, const std::pair<T, U>& rh) {\n        return lh.second\
    \ == rh.second ? lh.first < rh.first : lh.second < rh.second;\n    }\n};\n#define\
    \ SORTBY(method) [](const auto& a, const auto& b) { return a.method < b.method;\
    \ }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/itemsorter.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:17:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/itemsorter.hpp
layout: document
redirect_from:
- /library/utility/itemsorter.hpp
- /library/utility/itemsorter.hpp.html
title: "I\u756A\u76EE\u306E\u8981\u7D20\u3092\u6BD4\u8F03"
---
