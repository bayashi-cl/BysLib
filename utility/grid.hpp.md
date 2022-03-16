---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs_grid.test.cpp
    title: test/graph/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u7BA1\u7406"
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
    \ bys\n\nnamespace bys {\n//! @brief \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u7BA1\
    \u7406\nstruct Grid {\n    int h, w;\n    Grid(int row, int col) : h(row), w(col)\
    \ {}\n\n    bool contain(int row, int col) const { return 0 <= row && row < h\
    \ && 0 <= col && col < w; }\n    int area() const { return h * w; }\n    int index(int\
    \ row, int col) const {\n        assert(contain(row, col));\n        return row\
    \ * w + col;\n    }\n    int index(std::pair<int, int> p) const { return index(p.first,\
    \ p.second); }\n\n    pair<int, int> coord(int idx) const {\n        assert(0\
    \ <= idx && idx < area());\n        return {idx / w, idx % w};\n    }\n    vector<pair<int,\
    \ int>> next(int row, int col, const vector<pair<int, int>> delta) const {\n \
    \       assert(contain(row, col));\n        vector<pair<int, int>> res;\n    \
    \    for (auto [di, dj] : delta) {\n            int ni = row + di;\n         \
    \   int nj = col + dj;\n            if (contain(ni, nj)) res.push_back({ni, nj});\n\
    \        }\n        return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\n  \
    \  vector<pair<int, int>> next2(int row, int col) const { return next(row, col,\
    \ {{1, 0}, {0, 1}}); }\n    //! @brief \u4E0A\u4E0B\u5DE6\u53F3\n    vector<pair<int,\
    \ int>> next4(int row, int col) const { return next(row, col, {{1, 0}, {-1, 0},\
    \ {0, 1}, {0, -1}}); }\n    //! @brief 8\u65B9\u5411\n    vector<pair<int, int>>\
    \ next8(int row, int col) const {\n        vector<pair<int, int>> delta;\n   \
    \     for (int di = -1; di <= 1; ++di) {\n            for (int dj = -1; dj <=\
    \ 1; ++dj) {\n                if (di == 0 && dj == 0) continue;\n            \
    \    delta.push_back({di, dj});\n            }\n        }\n        return next(row,\
    \ col, delta);\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\n//! @brief\
    \ \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u7BA1\u7406\nstruct Grid {\n    int h,\
    \ w;\n    Grid(int row, int col) : h(row), w(col) {}\n\n    bool contain(int row,\
    \ int col) const { return 0 <= row && row < h && 0 <= col && col < w; }\n    int\
    \ area() const { return h * w; }\n    int index(int row, int col) const {\n  \
    \      assert(contain(row, col));\n        return row * w + col;\n    }\n    int\
    \ index(std::pair<int, int> p) const { return index(p.first, p.second); }\n\n\
    \    pair<int, int> coord(int idx) const {\n        assert(0 <= idx && idx < area());\n\
    \        return {idx / w, idx % w};\n    }\n    vector<pair<int, int>> next(int\
    \ row, int col, const vector<pair<int, int>> delta) const {\n        assert(contain(row,\
    \ col));\n        vector<pair<int, int>> res;\n        for (auto [di, dj] : delta)\
    \ {\n            int ni = row + di;\n            int nj = col + dj;\n        \
    \    if (contain(ni, nj)) res.push_back({ni, nj});\n        }\n        return\
    \ res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\n    vector<pair<int, int>> next2(int\
    \ row, int col) const { return next(row, col, {{1, 0}, {0, 1}}); }\n    //! @brief\
    \ \u4E0A\u4E0B\u5DE6\u53F3\n    vector<pair<int, int>> next4(int row, int col)\
    \ const { return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n    //!\
    \ @brief 8\u65B9\u5411\n    vector<pair<int, int>> next8(int row, int col) const\
    \ {\n        vector<pair<int, int>> delta;\n        for (int di = -1; di <= 1;\
    \ ++di) {\n            for (int dj = -1; dj <= 1; ++dj) {\n                if\
    \ (di == 0 && dj == 0) continue;\n                delta.push_back({di, dj});\n\
    \            }\n        }\n        return next(row, col, delta);\n    }\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/grid.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/bfs_grid.test.cpp
  - test/graph/bfs_grid.test.cpp
documentation_of: utility/grid.hpp
layout: document
redirect_from:
- /library/utility/grid.hpp
- /library/utility/grid.hpp.html
title: "\u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u7BA1\u7406"
---
