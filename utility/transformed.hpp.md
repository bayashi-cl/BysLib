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
    document_title: Transformed
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
    \ bys\n/**\n * @file transformed.hpp\n * @brief Transformed\n */\nnamespace bys\
    \ {\n//! @brief vecotr\u306E\u5909\u63DB\ntemplate <class T, class Lambda, typename\
    \ R = std::invoke_result_t<std::decay_t<Lambda>, T>>\nstd::vector<R> transformed(const\
    \ std::vector<T>& vec, Lambda f) {\n    std::vector<R> res;\n    std::transform(vec.begin(),\
    \ vec.end(), std::back_inserter(res), f);\n    return res;\n}\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file transformed.hpp\n\
    \ * @brief Transformed\n */\nnamespace bys {\n//! @brief vecotr\u306E\u5909\u63DB\
    \ntemplate <class T, class Lambda, typename R = std::invoke_result_t<std::decay_t<Lambda>,\
    \ T>>\nstd::vector<R> transformed(const std::vector<T>& vec, Lambda f) {\n   \
    \ std::vector<R> res;\n    std::transform(vec.begin(), vec.end(), std::back_inserter(res),\
    \ f);\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/transformed.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/transformed.hpp
layout: document
redirect_from:
- /library/utility/transformed.hpp
- /library/utility/transformed.hpp.html
title: Transformed
---
