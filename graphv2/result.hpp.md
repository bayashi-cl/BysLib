---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: Const
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graphv2/breadth_first_search.hpp
    title: Breadth First Search
  - icon: ':heavy_check_mark:'
    path: graphv2/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: graphv2/warshall_floyd.hpp
    title: Warshall Floyd
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/dijkstra.test.cpp
    title: test/graphv2/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Shortest Path Result
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
    \ T>;\n}  // namespace bys\n/**\n * @file const.hpp\n * @author bayashi_cl\n *\
    \ @brief Const\n */\nnamespace bys {\nconstexpr int MOD = 998244353;\nconstexpr\
    \ int MOD7 = 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace\
    \ bys\n/**\n * @file result.hpp\n * @author bayashi_cl\n * @brief Shortest Path\
    \ Result\n */\nnamespace bys {\n/**\n * @brief \u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u7D4C\u8DEF\n *\n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\u304D\u308B\n */\nstruct\
    \ SSSPResult {\n    std::size_t source;\n    std::vector<ll> cost;\n    std::vector<int>\
    \ prev;\n\n    SSSPResult(std::size_t _n, std::size_t _source) : source(_source),\
    \ cost(_n, LINF), prev(_n, -1) {}\n    vector<std::size_t> path(int to) const\
    \ {\n        vector<std::size_t> res;\n        while (to != -1) {\n          \
    \  res.push_back(to);\n            to = prev[to];\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n/**\n * @brief \u5168\u9802\u70B9\
    \u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF\n *\n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\
    \u304D\u308B\n */\nstruct APSPResult {\n    std::vector<std::vector<ll>> cost;\n\
    \    std::vector<std::vector<int>> prev;\n    APSPResult(std::size_t _n) : cost(_n,\
    \ vector(_n, LINF)), prev(_n, vector(_n, -1)) {}\n    std::vector<std::size_t>\
    \ path(int from, int to) {\n        vector<std::size_t> res;\n        for (int\
    \ now = to; now != from; now = prev[from][now]) {\n            res.push_back(now);\n\
    \        }\n        res.push_back(from);\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/const.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n/**\n * @file result.hpp\n * @author bayashi_cl\n * @brief Shortest Path Result\n\
    \ */\nnamespace bys {\n/**\n * @brief \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\
    \u8DEF\n *\n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\u304D\u308B\n */\nstruct SSSPResult\
    \ {\n    std::size_t source;\n    std::vector<ll> cost;\n    std::vector<int>\
    \ prev;\n\n    SSSPResult(std::size_t _n, std::size_t _source) : source(_source),\
    \ cost(_n, LINF), prev(_n, -1) {}\n    vector<std::size_t> path(int to) const\
    \ {\n        vector<std::size_t> res;\n        while (to != -1) {\n          \
    \  res.push_back(to);\n            to = prev[to];\n        }\n        std::reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n/**\n * @brief \u5168\u9802\u70B9\
    \u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF\n *\n * \u7D4C\u8DEF\u5FA9\u5143\u3082\u3067\
    \u304D\u308B\n */\nstruct APSPResult {\n    std::vector<std::vector<ll>> cost;\n\
    \    std::vector<std::vector<int>> prev;\n    APSPResult(std::size_t _n) : cost(_n,\
    \ vector(_n, LINF)), prev(_n, vector(_n, -1)) {}\n    std::vector<std::size_t>\
    \ path(int from, int to) {\n        vector<std::size_t> res;\n        for (int\
    \ now = to; now != from; now = prev[from][now]) {\n            res.push_back(now);\n\
    \        }\n        res.push_back(from);\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/const.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: graphv2/result.hpp
  requiredBy:
  - graphv2/warshall_floyd.hpp
  - graphv2/breadth_first_search.hpp
  - graphv2/dijkstra.hpp
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graphv2/dijkstra.test.cpp
documentation_of: graphv2/result.hpp
layout: document
redirect_from:
- /library/graphv2/result.hpp
- /library/graphv2/result.hpp.html
title: Shortest Path Result
---
