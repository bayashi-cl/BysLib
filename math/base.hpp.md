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
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T>\nvector<T> deci2n(T deci, T base)\
    \ {\n    vector<T> res;\n    while (deci > 0) {\n        res.push_back(deci %\
    \ base);\n        deci /= base;\n    }\n    return res;\n}\nll n2deci(vector<ll>\
    \ n, int base) {\n    ll b = 1;\n    ll res = 0;\n    for (auto&& d : n) {\n \
    \       res += d * b;\n        b *= base;\n    }\n    return res;\n}\nvector<ll>\
    \ strbase(string n) {\n    vector<ll> res;\n    std::for_each(n.rbegin(), n.rend(),\
    \ [&](char d) { res.push_back(d - '0'); });\n    return res;\n}\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\ntemplate\
    \ <class T>\nvector<T> deci2n(T deci, T base) {\n    vector<T> res;\n    while\
    \ (deci > 0) {\n        res.push_back(deci % base);\n        deci /= base;\n \
    \   }\n    return res;\n}\nll n2deci(vector<ll> n, int base) {\n    ll b = 1;\n\
    \    ll res = 0;\n    for (auto&& d : n) {\n        res += d * b;\n        b *=\
    \ base;\n    }\n    return res;\n}\nvector<ll> strbase(string n) {\n    vector<ll>\
    \ res;\n    std::for_each(n.rbegin(), n.rend(), [&](char d) { res.push_back(d\
    \ - '0'); });\n    return res;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/base.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/base.hpp
layout: document
redirect_from:
- /library/math/base.hpp
- /library/math/base.hpp.html
title: math/base.hpp
---
