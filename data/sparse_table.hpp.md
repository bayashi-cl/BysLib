---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
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
    \ bys\n#line 3 \"data/sparse_table.hpp\"\nnamespace bys {\ntemplate <class A>\n\
    class SparseTable {\n    using T = typename A::value_type;\n    int n;\n    std::vector<int>\
    \ lookup;\n    std::vector<std::vector<T>> table;\n\n   public:\n    SparseTable()\
    \ {}\n    SparseTable(const std::vector<T>& v) { build(v); }\n\n    void build(const\
    \ std::vector<T>& v) {\n        n = v.size();\n        lookup.resize(n + 1);\n\
    \n        for (int i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n  \
    \      int max_k = lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n\
    \        std::copy(v.begin(), v.end(), table[0].begin());\n        for (int i\
    \ = 1; i <= max_k; ++i) {\n            for (int j = 0; j <= n - (1 << i); ++j)\
    \ {\n                table[i][j] = A::op(table[i - 1][j], table[i - 1][j + (1\
    \ << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int r)\
    \ {\n        assert(0 <= l && l < r && r <= n);\n        int w = r - l;\n    \
    \    return A::op(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\nnamespace bys {\ntemplate\
    \ <class A>\nclass SparseTable {\n    using T = typename A::value_type;\n    int\
    \ n;\n    std::vector<int> lookup;\n    std::vector<std::vector<T>> table;\n\n\
    \   public:\n    SparseTable() {}\n    SparseTable(const std::vector<T>& v) {\
    \ build(v); }\n\n    void build(const std::vector<T>& v) {\n        n = v.size();\n\
    \        lookup.resize(n + 1);\n\n        for (int i = 2; i < n + 1; ++i) lookup[i]\
    \ = lookup[i >> 1] + 1;\n        int max_k = lookup.back();\n        table.assign(max_k\
    \ + 1, std::vector<T>(n));\n        std::copy(v.begin(), v.end(), table[0].begin());\n\
    \        for (int i = 1; i <= max_k; ++i) {\n            for (int j = 0; j <=\
    \ n - (1 << i); ++j) {\n                table[i][j] = A::op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= n);\n        int w = r -\
    \ l;\n        return A::op(table[lookup[w]][l], table[lookup[w]][r - (1 << lookup[w])]);\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-02-15 02:39:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/sparse_table.test.cpp
documentation_of: data/sparse_table.hpp
layout: document
redirect_from:
- /library/data/sparse_table.hpp
- /library/data/sparse_table.hpp.html
title: data/sparse_table.hpp
---
