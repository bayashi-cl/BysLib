---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: core/types.hpp
    title: Types
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Run Length Encoding
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
    \ bys\n/**\n * @file types.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\
    \n */\nnamespace bys {\ntemplate <class, class = void>\nstruct has_lshift_to_ostream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n/**\n * @file\
    \ run_length.hpp\n * @brief Run Length Encoding\n */\nnamespace bys {\n//! @brief\
    \ \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\ntemplate <class Iterable,\
    \ std::enable_if_t<has_iterator<Iterable>::value, std::nullptr_t> = nullptr>\n\
    auto run_length_encode(const Iterable& v) {\n    using T = typename Iterable::value_type;\n\
    \    std::vector<std::pair<T, int>> res;\n    if (v.empty()) return res;\n   \
    \ res.emplace_back(v.front(), 0);\n    for (auto&& e : v) {\n        if (e ==\
    \ res.back().first) {\n            res.back().second++;\n        } else {\n  \
    \          res.emplace_back(e, 1);\n        }\n    }\n    return res;\n}\n}  //\
    \ namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../core/types.hpp\"\
    \n/**\n * @file run_length.hpp\n * @brief Run Length Encoding\n */\nnamespace\
    \ bys {\n//! @brief \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\ntemplate\
    \ <class Iterable, std::enable_if_t<has_iterator<Iterable>::value, std::nullptr_t>\
    \ = nullptr>\nauto run_length_encode(const Iterable& v) {\n    using T = typename\
    \ Iterable::value_type;\n    std::vector<std::pair<T, int>> res;\n    if (v.empty())\
    \ return res;\n    res.emplace_back(v.front(), 0);\n    for (auto&& e : v) {\n\
    \        if (e == res.back().first) {\n            res.back().second++;\n    \
    \    } else {\n            res.emplace_back(e, 1);\n        }\n    }\n    return\
    \ res;\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - core/types.hpp
  isVerificationFile: false
  path: algorithm/run_length.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/run_length.hpp
layout: document
redirect_from:
- /library/algorithm/run_length.hpp
- /library/algorithm/run_length.hpp.html
title: Run Length Encoding
---
