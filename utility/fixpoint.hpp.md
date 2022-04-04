---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/util.hpp
    title: graph/util.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/lca.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: FixPoint
    links:
    - https://koturn.hatenablog.com/entry/2018/06/10/060000
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
    \ bys\n/**\n * @file fixpoint.hpp\n * @brief FixPoint\n */\nnamespace bys {\n\
    /**\n * @brief \u30E9\u30E0\u30C0\u518D\u5E30\n *\n * See: https://koturn.hatenablog.com/entry/2018/06/10/060000\n\
    \ */\ntemplate <typename F>\nstruct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file fixpoint.hpp\n\
    \ * @brief FixPoint\n */\nnamespace bys {\n/**\n * @brief \u30E9\u30E0\u30C0\u518D\
    \u5E30\n *\n * See: https://koturn.hatenablog.com/entry/2018/06/10/060000\n */\n\
    template <typename F>\nstruct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/fixpoint.hpp
  requiredBy:
  - graphv2/lca.hpp
  - graph/util.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/lca.test.cpp
documentation_of: utility/fixpoint.hpp
layout: document
redirect_from:
- /library/utility/fixpoint.hpp
- /library/utility/fixpoint.hpp.html
title: FixPoint
---
