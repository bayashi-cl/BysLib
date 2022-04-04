---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':x:'
    path: graphv2/lca.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':x:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Sparse Table
    links:
    - https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table
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
    \ bys\n/**\n * @file sparse_table.hpp\n * @brief Sparse Table\n */\nnamespace\
    \ bys {\n/**\n * @brief Sparse Table\n *\n * \u69CB\u7BC9: O(NlogN)\n * \u30AF\
    \u30A8\u30EA: O(1)\n * See: https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band>\nclass SparseTable {\n    using\
    \ T = typename Band::set_type;\n    int n;\n    std::vector<int> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n   public:\n    SparseTable() {}\n   \
    \ SparseTable(const std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>&\
    \ v) {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (int\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        int max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (int i = 1; i\
    \ <= max_k; ++i) {\n            for (int j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int\
    \ r) {\n        assert(0 <= l && l < r && r <= n);\n        int w = r - l;\n \
    \       return Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 <<\
    \ lookup[w])]);\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file sparse_table.hpp\n\
    \ * @brief Sparse Table\n */\nnamespace bys {\n/**\n * @brief Sparse Table\n *\n\
    \ * \u69CB\u7BC9: O(NlogN)\n * \u30AF\u30A8\u30EA: O(1)\n * See: https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table\n\
    \ *\n * @tparam Band \u30E2\u30CE\u30A4\u30C9\u3067\u51AA\u7B49\u6027\u304C\u3042\
    \u308B\u3082\u306E\n */\ntemplate <class Band>\nclass SparseTable {\n    using\
    \ T = typename Band::set_type;\n    int n;\n    std::vector<int> lookup;\n   \
    \ std::vector<std::vector<T>> table;\n\n   public:\n    SparseTable() {}\n   \
    \ SparseTable(const std::vector<T>& v) { build(v); }\n\n    void build(const std::vector<T>&\
    \ v) {\n        n = v.size();\n        lookup.resize(n + 1);\n\n        for (int\
    \ i = 2; i < n + 1; ++i) lookup[i] = lookup[i >> 1] + 1;\n        int max_k =\
    \ lookup.back();\n        table.assign(max_k + 1, std::vector<T>(n));\n      \
    \  std::copy(v.begin(), v.end(), table[0].begin());\n        for (int i = 1; i\
    \ <= max_k; ++i) {\n            for (int j = 0; j <= n - (1 << i); ++j) {\n  \
    \              table[i][j] = Band::operation(table[i - 1][j], table[i - 1][j +\
    \ (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int\
    \ r) {\n        assert(0 <= l && l < r && r <= n);\n        int w = r - l;\n \
    \       return Band::operation(table[lookup[w]][l], table[lookup[w]][r - (1 <<\
    \ lookup[w])]);\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/sparse_table.hpp
  requiredBy:
  - graphv2/lca.hpp
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graphv2/lca.test.cpp
  - test/data/sparse_table.test.cpp
documentation_of: data/sparse_table.hpp
layout: document
redirect_from:
- /library/data/sparse_table.hpp
- /library/data/sparse_table.hpp.html
title: Sparse Table
---
