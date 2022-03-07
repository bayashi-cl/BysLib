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
    document_title: Orderd pair
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cmath>\n#include <complex>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\nnamespace bys {\n/**\n * @brief Orderd pair\n * @details first <= second\u306B\
    \u306A\u308Bpair\n */\ntemplate <class T>\nstruct OrderedPair : std::pair<T, T>\
    \ {\n    OrderedPair(T a, T b) {\n        if (a > b) std::swap(a, b);\n      \
    \  this->first = a;\n        this->second = b;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\n/**\n * @brief\
    \ Orderd pair\n * @details first <= second\u306B\u306A\u308Bpair\n */\ntemplate\
    \ <class T>\nstruct OrderedPair : std::pair<T, T> {\n    OrderedPair(T a, T b)\
    \ {\n        if (a > b) std::swap(a, b);\n        this->first = a;\n        this->second\
    \ = b;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/ordered_pair.hpp
  requiredBy: []
  timestamp: '2022-02-26 15:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/ordered_pair.hpp
layout: document
redirect_from:
- /library/data/ordered_pair.hpp
- /library/data/ordered_pair.hpp.html
title: Orderd pair
---
