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
    document_title: Python::itertools
    links:
    - https://docs.python.org/ja/3/library/itertools.html
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
    \ T>;\n}  // namespace bys\n/**\n * @file itertools.hpp\n * @author bayashi_cl\n\
    \ * @brief Python::itertools\n *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA\
    \ itertools\u7DE8\n * See: https://docs.python.org/ja/3/library/itertools.html\n\
    \ */\nnamespace bys {\n/**\n * @brief itertools.conbination()\n *\n * \u5165\u529B\
    \u306E\u8981\u7D20\u304B\u3089\u306A\u308B\u9577\u3055r\u306E\u90E8\u5206\u5217\
    \u3092\u8FD4\u3059\u3002\n */\ntemplate <class T>\nclass Combinations {\n    const\
    \ std::vector<T> pool;\n    int n, r;\n    std::vector<T> comb;\n    std::vector<int>\
    \ indices;\n    bool term = false;\n\n   public:\n    Combinations(const std::vector<T>&\
    \ vec, int r) : pool(vec), n(vec.size()), r(r), comb(r), indices(r) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n        for (int i = 0;\
    \ i < r; ++i) comb[i] = pool[indices[i]];\n    }\n    Combinations<T> begin()\
    \ const { return *this; }\n    bool end() const { return true; }\n    bool operator!=(bool)\
    \ const { return !term; }\n    void operator++() {\n        bool flg = true;\n\
    \        int i = r - 1;\n        for (; i >= 0; --i) {\n            if (indices[i]\
    \ != i + n - r) {\n                flg = false;\n                break;\n    \
    \        }\n        }\n        if (flg) {\n            term = true;\n        \
    \    return;\n        }\n        indices[i]++;\n        for (int j = i + 1; j\
    \ < r; ++j) {\n            indices[j] = indices[j - 1] + 1;\n        }\n     \
    \   for (int k = 0; k < r; ++k) comb[k] = pool[indices[k]];\n    }\n    const\
    \ std::vector<T>& operator*() const { return comb; }\n};\n/**\n * @brief itertools.combinations(range(n),\
    \ r)\n *\n * [0, n) \u304B\u3089R\u500B\u3092\u9078\u3076\u7D44\u307F\u5408\u308F\
    \u305B\u5168\u63A2\u7D22\n */\ntemplate <std::size_t R>\nclass IndexCombinations\
    \ {\n    std::array<std::size_t, R> indices;\n    std::size_t n, r;\n    bool\
    \ term = false;\n\n   public:\n    IndexCombinations(std::size_t n) : n(n), r(indices.size())\
    \ {\n        if (r > n) {\n            term = true;\n            return;\n   \
    \     }\n        std::iota(indices.begin(), indices.end(), 0);\n    }\n    IndexCombinations\
    \ begin() const { return *this; }\n    bool end() const { return true; }\n   \
    \ bool operator!=(bool) const { return !term; }\n    void operator++() {\n   \
    \     bool flg = true;\n        int i = r - 1;\n        for (; i >= 0; --i) {\n\
    \            if (indices[i] != i + n - r) {\n                flg = false;\n  \
    \              break;\n            }\n        }\n        if (flg) {\n        \
    \    term = true;\n            return;\n        }\n        indices[i]++;\n   \
    \     for (std::size_t j = i + 1; j < r; ++j) {\n            indices[j] = indices[j\
    \ - 1] + 1;\n        }\n    }\n    const std::array<std::size_t, R>& operator*()\
    \ const { return indices; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file itertools.hpp\n\
    \ * @author bayashi_cl\n * @brief Python::itertools\n *\n * Python\u518D\u73FE\
    \u30B7\u30EA\u30FC\u30BA itertools\u7DE8\n * See: https://docs.python.org/ja/3/library/itertools.html\n\
    \ */\nnamespace bys {\n/**\n * @brief itertools.conbination()\n *\n * \u5165\u529B\
    \u306E\u8981\u7D20\u304B\u3089\u306A\u308B\u9577\u3055r\u306E\u90E8\u5206\u5217\
    \u3092\u8FD4\u3059\u3002\n */\ntemplate <class T>\nclass Combinations {\n    const\
    \ std::vector<T> pool;\n    int n, r;\n    std::vector<T> comb;\n    std::vector<int>\
    \ indices;\n    bool term = false;\n\n   public:\n    Combinations(const std::vector<T>&\
    \ vec, int r) : pool(vec), n(vec.size()), r(r), comb(r), indices(r) {\n      \
    \  if (r > n) {\n            term = true;\n            return;\n        }\n  \
    \      std::iota(indices.begin(), indices.end(), 0);\n        for (int i = 0;\
    \ i < r; ++i) comb[i] = pool[indices[i]];\n    }\n    Combinations<T> begin()\
    \ const { return *this; }\n    bool end() const { return true; }\n    bool operator!=(bool)\
    \ const { return !term; }\n    void operator++() {\n        bool flg = true;\n\
    \        int i = r - 1;\n        for (; i >= 0; --i) {\n            if (indices[i]\
    \ != i + n - r) {\n                flg = false;\n                break;\n    \
    \        }\n        }\n        if (flg) {\n            term = true;\n        \
    \    return;\n        }\n        indices[i]++;\n        for (int j = i + 1; j\
    \ < r; ++j) {\n            indices[j] = indices[j - 1] + 1;\n        }\n     \
    \   for (int k = 0; k < r; ++k) comb[k] = pool[indices[k]];\n    }\n    const\
    \ std::vector<T>& operator*() const { return comb; }\n};\n/**\n * @brief itertools.combinations(range(n),\
    \ r)\n *\n * [0, n) \u304B\u3089R\u500B\u3092\u9078\u3076\u7D44\u307F\u5408\u308F\
    \u305B\u5168\u63A2\u7D22\n */\ntemplate <std::size_t R>\nclass IndexCombinations\
    \ {\n    std::array<std::size_t, R> indices;\n    std::size_t n, r;\n    bool\
    \ term = false;\n\n   public:\n    IndexCombinations(std::size_t n) : n(n), r(indices.size())\
    \ {\n        if (r > n) {\n            term = true;\n            return;\n   \
    \     }\n        std::iota(indices.begin(), indices.end(), 0);\n    }\n    IndexCombinations\
    \ begin() const { return *this; }\n    bool end() const { return true; }\n   \
    \ bool operator!=(bool) const { return !term; }\n    void operator++() {\n   \
    \     bool flg = true;\n        int i = r - 1;\n        for (; i >= 0; --i) {\n\
    \            if (indices[i] != i + n - r) {\n                flg = false;\n  \
    \              break;\n            }\n        }\n        if (flg) {\n        \
    \    term = true;\n            return;\n        }\n        indices[i]++;\n   \
    \     for (std::size_t j = i + 1; j < r; ++j) {\n            indices[j] = indices[j\
    \ - 1] + 1;\n        }\n    }\n    const std::array<std::size_t, R>& operator*()\
    \ const { return indices; }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/itertools.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/itertools.hpp
layout: document
redirect_from:
- /library/utility/itertools.hpp
- /library/utility/itertools.hpp.html
title: Python::itertools
---
