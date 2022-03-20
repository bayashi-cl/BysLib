---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: graph/breadth_first.hpp
    title: graph/breadth_first.hpp
  - icon: ':heavy_check_mark:'
    path: graph/depth_first.hpp
    title: graph/depth_first.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: graph/lca.hpp
  - icon: ':heavy_check_mark:'
    path: graph/reader.hpp
    title: graph/reader.hpp
  - icon: ':warning:'
    path: graph/util.hpp
    title: graph/util.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs_grid.test.cpp
    title: test/graph/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: test/graph/kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/test.test.cpp
    title: test/test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    \ bys\n\nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\nstruct Edge {\n    int from, to;\n    ll cost;\n\n    //! @brief\
    \ \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\n    Edge(int to) : from(-1), to(to),\
    \ cost(1) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u5358\u9802\u70B9\n    Edge(int\
    \ to, ll cost) : from(-1), to(to), cost(cost) {}\n    //! @brief \u91CD\u307F\u4ED8\
    \u304D\u4E21\u9802\u70B9\n    Edge(int from, int to, ll cost) : from(from), to(to),\
    \ cost(cost) {}\n    bool operator<(const Edge& rh) const { return cost < rh.cost;\
    \ }\n    operator std::size_t() const { return to; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Edge& e) {\n        return os << \"{\" <<\
    \ e.from << \" -> \" << e.to << \": \" << e.cost << \"}\";\n    }\n};\nusing Adj\
    \ = vector<vector<Edge>>;\nusing EdgeList = vector<Edge>;\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\nstruct Edge\
    \ {\n    int from, to;\n    ll cost;\n\n    //! @brief \u91CD\u307F\u306A\u3057\
    \u5358\u9802\u70B9\n    Edge(int to) : from(-1), to(to), cost(1) {}\n    //! @brief\
    \ \u91CD\u307F\u4ED8\u304D\u5358\u9802\u70B9\n    Edge(int to, ll cost) : from(-1),\
    \ to(to), cost(cost) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u4E21\u9802\u70B9\
    \n    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}\n  \
    \  bool operator<(const Edge& rh) const { return cost < rh.cost; }\n    operator\
    \ std::size_t() const { return to; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Edge& e) {\n        return os << \"{\" << e.from << \" -> \" << e.to\
    \ << \": \" << e.cost << \"}\";\n    }\n};\nusing Adj = vector<vector<Edge>>;\n\
    using EdgeList = vector<Edge>;\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - graph/depth_first.hpp
  - graph/reader.hpp
  - graph/util.hpp
  - graph/kruskal.hpp
  - graph/breadth_first.hpp
  - graph/warshall_floyd.hpp
  - graph/lca.hpp
  - graph/dijkstra.hpp
  - graph/bellman_ford.hpp
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/test.test.cpp
  - test/graph/bfs_grid.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/lca.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
