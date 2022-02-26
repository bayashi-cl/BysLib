---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/prime.test.cpp
    title: test/math/prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ bys\n#line 3 \"math/prime.hpp\"\n\nnamespace bys {\ntemplate <typename T>\n\
    vector<T> prime_factorize(T n) {\n    vector<T> res;\n    while (n % 2 == 0) {\n\
    \        res.push_back(2);\n        n /= 2;\n    }\n    T f = 3;\n    while (f\
    \ * f <= n) {\n        if (n % f == 0) {\n            res.push_back(f);\n    \
    \        n /= f;\n        } else {\n            f += 2;\n        }\n    }\n  \
    \  if (n != 1) res.push_back(n);\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\ntemplate\
    \ <typename T>\nvector<T> prime_factorize(T n) {\n    vector<T> res;\n    while\
    \ (n % 2 == 0) {\n        res.push_back(2);\n        n /= 2;\n    }\n    T f =\
    \ 3;\n    while (f * f <= n) {\n        if (n % f == 0) {\n            res.push_back(f);\n\
    \            n /= f;\n        } else {\n            f += 2;\n        }\n    }\n\
    \    if (n != 1) res.push_back(n);\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
