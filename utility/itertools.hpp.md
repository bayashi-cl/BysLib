---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <array>\n#include <iostream>\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace bys {\ntemplate <class T>\nclass Combinations {\n    const\
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
    \ std::vector<T>& operator*() const { return comb; }\n};\ntemplate <std::size_t\
    \ R>\nclass IndexCombinations {\n    std::array<std::size_t, R> indices;\n   \
    \ std::size_t n, r;\n    bool term = false;\n\n   public:\n    IndexCombinations(std::size_t\
    \ n) : n(n), r(indices.size()) {\n        if (r > n) {\n            term = true;\n\
    \            return;\n        }\n        std::iota(indices.begin(), indices.end(),\
    \ 0);\n    }\n    IndexCombinations begin() const { return *this; }\n    bool\
    \ end() const { return true; }\n    bool operator!=(bool) const { return !term;\
    \ }\n    void operator++() {\n        bool flg = true;\n        int i = r - 1;\n\
    \        for (; i >= 0; --i) {\n            if (indices[i] != i + n - r) {\n \
    \               flg = false;\n                break;\n            }\n        }\n\
    \        if (flg) {\n            term = true;\n            return;\n        }\n\
    \        indices[i]++;\n        for (std::size_t j = i + 1; j < r; ++j) {\n  \
    \          indices[j] = indices[j - 1] + 1;\n        }\n    }\n    const std::array<std::size_t,\
    \ R>& operator*() const { return indices; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <array>\n#include <iostream>\n#include <numeric>\n\
    #include <vector>\n\nnamespace bys {\ntemplate <class T>\nclass Combinations {\n\
    \    const std::vector<T> pool;\n    int n, r;\n    std::vector<T> comb;\n   \
    \ std::vector<int> indices;\n    bool term = false;\n\n   public:\n    Combinations(const\
    \ std::vector<T>& vec, int r) : pool(vec), n(vec.size()), r(r), comb(r), indices(r)\
    \ {\n        if (r > n) {\n            term = true;\n            return;\n   \
    \     }\n        std::iota(indices.begin(), indices.end(), 0);\n        for (int\
    \ i = 0; i < r; ++i) comb[i] = pool[indices[i]];\n    }\n    Combinations<T> begin()\
    \ const { return *this; }\n    bool end() const { return true; }\n    bool operator!=(bool)\
    \ const { return !term; }\n    void operator++() {\n        bool flg = true;\n\
    \        int i = r - 1;\n        for (; i >= 0; --i) {\n            if (indices[i]\
    \ != i + n - r) {\n                flg = false;\n                break;\n    \
    \        }\n        }\n        if (flg) {\n            term = true;\n        \
    \    return;\n        }\n        indices[i]++;\n        for (int j = i + 1; j\
    \ < r; ++j) {\n            indices[j] = indices[j - 1] + 1;\n        }\n     \
    \   for (int k = 0; k < r; ++k) comb[k] = pool[indices[k]];\n    }\n    const\
    \ std::vector<T>& operator*() const { return comb; }\n};\ntemplate <std::size_t\
    \ R>\nclass IndexCombinations {\n    std::array<std::size_t, R> indices;\n   \
    \ std::size_t n, r;\n    bool term = false;\n\n   public:\n    IndexCombinations(std::size_t\
    \ n) : n(n), r(indices.size()) {\n        if (r > n) {\n            term = true;\n\
    \            return;\n        }\n        std::iota(indices.begin(), indices.end(),\
    \ 0);\n    }\n    IndexCombinations begin() const { return *this; }\n    bool\
    \ end() const { return true; }\n    bool operator!=(bool) const { return !term;\
    \ }\n    void operator++() {\n        bool flg = true;\n        int i = r - 1;\n\
    \        for (; i >= 0; --i) {\n            if (indices[i] != i + n - r) {\n \
    \               flg = false;\n                break;\n            }\n        }\n\
    \        if (flg) {\n            term = true;\n            return;\n        }\n\
    \        indices[i]++;\n        for (std::size_t j = i + 1; j < r; ++j) {\n  \
    \          indices[j] = indices[j - 1] + 1;\n        }\n    }\n    const std::array<std::size_t,\
    \ R>& operator*() const { return indices; }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/itertools.hpp
  requiredBy: []
  timestamp: '2022-02-01 04:22:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/itertools.hpp
layout: document
redirect_from:
- /library/utility/itertools.hpp
- /library/utility/itertools.hpp.html
title: utility/itertools.hpp
---
