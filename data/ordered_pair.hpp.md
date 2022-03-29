---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Orderd Pair
    links: []
  bundledCode: "/**\n * @file ordered_pair.hpp\n * @author bayashi_cl\n * @brief Orderd\
    \ Pair\n */\n/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\nnamespace bys {\n//! @brief first <= second\u306B\u306A\
    \u308Bpair\ntemplate <class T>\nstruct OrderedPair : std::pair<T, T> {\n    OrderedPair(T\
    \ a, T b) {\n        if (a > b) std::swap(a, b);\n        this->first = a;\n \
    \       this->second = b;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file ordered_pair.hpp\n * @author bayashi_cl\n * @brief\
    \ Orderd Pair\n */\n#include \"../core/stdlib.hpp\"\nnamespace bys {\n//! @brief\
    \ first <= second\u306B\u306A\u308Bpair\ntemplate <class T>\nstruct OrderedPair\
    \ : std::pair<T, T> {\n    OrderedPair(T a, T b) {\n        if (a > b) std::swap(a,\
    \ b);\n        this->first = a;\n        this->second = b;\n    }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/ordered_pair.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/ordered_pair.hpp
layout: document
redirect_from:
- /library/data/ordered_pair.hpp
- /library/data/ordered_pair.hpp.html
title: Orderd Pair
---
