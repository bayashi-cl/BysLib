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
    document_title: Base conversion
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
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
    \ T>;\n}  // namespace bys\n/**\n * @file base.hpp\n * @author bayashi_cl\n *\
    \ @brief Base conversion\n *\n * \u9032\u6570\u5909\u63DB\n * 153(10) -> std::vector<ll>({3,\
    \ 5, 1})\n *\n * @todo \u30AF\u30E9\u30B9\u5316\n */\nnamespace bys {\n//! @brief\
    \ 10\u9032\u6570 -> n\u9032\u6570\ntemplate <class T>\nstd::vector<T> deci2n(T\
    \ deci, T base) {\n    std::vector<T> res;\n    while (deci > 0) {\n        res.push_back(deci\
    \ % base);\n        deci /= base;\n    }\n    return res;\n}\n//! @brief n\u9032\
    \u6570 -> 10\u9032\u6570\nll n2deci(std::vector<ll> n, int base) {\n    ll b =\
    \ 1;\n    ll res = 0;\n    for (auto&& d : n) {\n        res += d * b;\n     \
    \   b *= base;\n    }\n    return res;\n}\nstd::vector<ll> strbase(string n) {\n\
    \    std::vector<ll> res;\n    std::for_each(n.rbegin(), n.rend(), [&](char d)\
    \ { res.push_back(d - '0'); });\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file base.hpp\n *\
    \ @author bayashi_cl\n * @brief Base conversion\n *\n * \u9032\u6570\u5909\u63DB\
    \n * 153(10) -> std::vector<ll>({3, 5, 1})\n *\n * @todo \u30AF\u30E9\u30B9\u5316\
    \n */\nnamespace bys {\n//! @brief 10\u9032\u6570 -> n\u9032\u6570\ntemplate <class\
    \ T>\nstd::vector<T> deci2n(T deci, T base) {\n    std::vector<T> res;\n    while\
    \ (deci > 0) {\n        res.push_back(deci % base);\n        deci /= base;\n \
    \   }\n    return res;\n}\n//! @brief n\u9032\u6570 -> 10\u9032\u6570\nll n2deci(std::vector<ll>\
    \ n, int base) {\n    ll b = 1;\n    ll res = 0;\n    for (auto&& d : n) {\n \
    \       res += d * b;\n        b *= base;\n    }\n    return res;\n}\nstd::vector<ll>\
    \ strbase(string n) {\n    std::vector<ll> res;\n    std::for_each(n.rbegin(),\
    \ n.rend(), [&](char d) { res.push_back(d - '0'); });\n    return res;\n}\n} \
    \ // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/base.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/base.hpp
layout: document
redirect_from:
- /library/math/base.hpp
- /library/math/base.hpp.html
title: Base conversion
---
