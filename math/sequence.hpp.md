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
    document_title: "\u03A3[0, n)"
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
    \ bys\n#line 3 \"math/sequence.hpp\"\nnamespace bys {\ntemplate <class T>\nstruct\
    \ Arithmetic {\n    T a0, d;\n    Arithmetic(T a0, T d) : a0(a0), d(d) {}\n  \
    \  T an(T n) { return a0 + d * n; }\n\n    //! @brief \u03A3[0, n)\n    T sn(T\
    \ n) { return (a0 + an(n - 1)) * n / 2; }\n    //! @brief \u03A3[l, r)\n    T\
    \ sn(T l, T r) { return sn(r) - sn(l); }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\ntemplate\
    \ <class T>\nstruct Arithmetic {\n    T a0, d;\n    Arithmetic(T a0, T d) : a0(a0),\
    \ d(d) {}\n    T an(T n) { return a0 + d * n; }\n\n    //! @brief \u03A3[0, n)\n\
    \    T sn(T n) { return (a0 + an(n - 1)) * n / 2; }\n    //! @brief \u03A3[l,\
    \ r)\n    T sn(T l, T r) { return sn(r) - sn(l); }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/sequence.hpp
  requiredBy: []
  timestamp: '2022-02-26 15:09:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sequence.hpp
layout: document
redirect_from:
- /library/math/sequence.hpp
- /library/math/sequence.hpp.html
title: "\u03A3[0, n)"
---
