---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs_grid.test.cpp
    title: test/graph/bfs_grid.test.cpp
  - icon: ':x:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Grid Manager
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
    \ bys\n/**\n * @file grid.hpp\n * @brief Grid Manager\n */\nnamespace bys {\n\
    //! @brief \u30B0\u30EA\u30C3\u30C9\u63A2\u7D22\u88DC\u52A9\u30C4\u30FC\u30EB\u8A70\
    \u3081\u5408\u308F\u305B\nstruct Grid {\n    int h, w;\n    //! @brief row*col\u306E\
    \u30B0\u30EA\u30C3\u30C9\n    Grid(int row, int col) : h(row), w(col) {}\n\n \
    \   //! @brief \u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u304B\u5224\
    \u5B9A\n    bool contain(int row, int col) const { return 0 <= row && row < h\
    \ && 0 <= col && col < w; }\n    //! @brief \u30B0\u30EA\u30C3\u30C9\u306E\u9762\
    \u7A4D\n    int area() const { return h * w; }\n    //! @brief \u4E00\u6B21\u5143\
    \u5316\u3057\u305F\u3068\u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n   \
    \ int index(int row, int col) const {\n        assert(contain(row, col));\n  \
    \      return row * w + col;\n    }\n    int index(std::pair<int, int> p) const\
    \ { return index(p.first, p.second); }\n    //! @brief \u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\u304B\u3089\u5FA9\u5143\n    std::pair<int, int> coord(int idx) const\
    \ {\n        assert(0 <= idx && idx < area());\n        return {idx / w, idx %\
    \ w};\n    }\n    //! \u5468\u56F2\u306E\u30DE\u30B9\u306E\u3046\u3061\u30B0\u30EA\
    \u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u3082\u306E\n    auto next(int row,\
    \ int col, const vector<pair<int, int>> delta) const {\n        assert(contain(row,\
    \ col));\n        std::vector<std::pair<int, int>> res;\n        for (auto [di,\
    \ dj] : delta) {\n            int ni = row + di;\n            int nj = col + dj;\n\
    \            if (contain(ni, nj)) res.push_back({ni, nj});\n        }\n      \
    \  return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\n    auto next2(int row,\
    \ int col) const { return next(row, col, {{1, 0}, {0, 1}}); }\n    //! @brief\
    \ \u4E0A\u4E0B\u5DE6\u53F3\n    auto next4(int row, int col) const { return next(row,\
    \ col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n    //! @brief 8\u65B9\u5411\n\
    \    auto next8(int row, int col) const {\n        vector<pair<int, int>> delta;\n\
    \        for (int di = -1; di <= 1; ++di) {\n            for (int dj = -1; dj\
    \ <= 1; ++dj) {\n                if (di == 0 && dj == 0) continue;\n         \
    \       delta.push_back({di, dj});\n            }\n        }\n        return next(row,\
    \ col, delta);\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file grid.hpp\n *\
    \ @brief Grid Manager\n */\nnamespace bys {\n//! @brief \u30B0\u30EA\u30C3\u30C9\
    \u63A2\u7D22\u88DC\u52A9\u30C4\u30FC\u30EB\u8A70\u3081\u5408\u308F\u305B\nstruct\
    \ Grid {\n    int h, w;\n    //! @brief row*col\u306E\u30B0\u30EA\u30C3\u30C9\n\
    \    Grid(int row, int col) : h(row), w(col) {}\n\n    //! @brief \u30B0\u30EA\
    \u30C3\u30C9\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\n    bool contain(int\
    \ row, int col) const { return 0 <= row && row < h && 0 <= col && col < w; }\n\
    \    //! @brief \u30B0\u30EA\u30C3\u30C9\u306E\u9762\u7A4D\n    int area() const\
    \ { return h * w; }\n    //! @brief \u4E00\u6B21\u5143\u5316\u3057\u305F\u3068\
    \u304D\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    int index(int row, int col)\
    \ const {\n        assert(contain(row, col));\n        return row * w + col;\n\
    \    }\n    int index(std::pair<int, int> p) const { return index(p.first, p.second);\
    \ }\n    //! @brief \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304B\u3089\u5FA9\u5143\
    \n    std::pair<int, int> coord(int idx) const {\n        assert(0 <= idx && idx\
    \ < area());\n        return {idx / w, idx % w};\n    }\n    //! \u5468\u56F2\u306E\
    \u30DE\u30B9\u306E\u3046\u3061\u30B0\u30EA\u30C3\u30C9\u306B\u542B\u307E\u308C\
    \u308B\u3082\u306E\n    auto next(int row, int col, const vector<pair<int, int>>\
    \ delta) const {\n        assert(contain(row, col));\n        std::vector<std::pair<int,\
    \ int>> res;\n        for (auto [di, dj] : delta) {\n            int ni = row\
    \ + di;\n            int nj = col + dj;\n            if (contain(ni, nj)) res.push_back({ni,\
    \ nj});\n        }\n        return res;\n    }\n    //! @brief \u53F3\u30FB\u4E0B\
    \n    auto next2(int row, int col) const { return next(row, col, {{1, 0}, {0,\
    \ 1}}); }\n    //! @brief \u4E0A\u4E0B\u5DE6\u53F3\n    auto next4(int row, int\
    \ col) const { return next(row, col, {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}); }\n\
    \    //! @brief 8\u65B9\u5411\n    auto next8(int row, int col) const {\n    \
    \    vector<pair<int, int>> delta;\n        for (int di = -1; di <= 1; ++di) {\n\
    \            for (int dj = -1; dj <= 1; ++dj) {\n                if (di == 0 &&\
    \ dj == 0) continue;\n                delta.push_back({di, dj});\n           \
    \ }\n        }\n        return next(row, col, delta);\n    }\n};\n}  // namespace\
    \ bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/grid.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graphv2/bfs_grid.test.cpp
  - test/graph/bfs_grid.test.cpp
documentation_of: utility/grid.hpp
layout: document
redirect_from:
- /library/utility/grid.hpp
- /library/utility/grid.hpp.html
title: Grid Manager
---
