---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: "\u91CD\u307F\u306A\u3057\u5358\u9802\u70B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: graph/lca.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
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
    \ bys\n#line 3 \"graph/edge.hpp\"\n\nnamespace bys {\nstruct Edge {\n    int from,\
    \ to;\n    ll cost;\n\n    //! @brief \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\
    \n    Edge(int to) : from(-1), to(to), cost(1) {}\n    //! @brief \u91CD\u307F\
    \u4ED8\u304D\u5358\u9802\u70B9\n    Edge(int to, ll cost) : from(-1), to(to),\
    \ cost(cost) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u4E21\u9802\u70B9\n \
    \   Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}\n    bool\
    \ operator<(const Edge& rh) const { return cost < rh.cost; }\n    operator std::size_t()\
    \ const { return to; }\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Edge& e) {\n        return os << \"{\" << e.from << \" -> \" << e.to <<\
    \ \": \" << e.cost << \"}\";\n    }\n};\nusing Adj = vector<vector<Edge>>;\nusing\
    \ EdgeList = vector<Edge>;\n}  // namespace bys\n#line 4 \"graph/depth_first.hpp\"\
    \n\nnamespace bys {\nstruct DepthFirstSearch {\n    const Adj& graph;\n    int\
    \ n_node;\n    vector<int> cost;\n    vector<int> pre_order;\n    vector<int>\
    \ post_order;\n    vector<int> tour;\n    vector<int> prev;\n\n    DepthFirstSearch(const\
    \ Adj& graph, int start) : graph(graph), n_node(graph.size()), cost(n_node, -1),\
    \ prev(n_node, -1) {\n        cost[start] = 0;\n        search(start);\n    }\n\
    \    DepthFirstSearch(const Adj& graph) : graph(graph), n_node(graph.size()),\
    \ cost(n_node, -1), prev(n_node, -1) {}\n\n    void crawl() {\n        for (int\
    \ i = 0; i < n_node; ++i) {\n            if (cost[i] == -1) {\n              \
    \  cost[i] = 0;\n                search(i);\n            }\n        }\n    }\n\
    \n    void search(int now) {\n        // cost[now] = true;\n        pre_order.push_back(now);\n\
    \        tour.push_back(now);\n        for (auto&& to : graph[now]) {\n      \
    \      if (cost[to.to] != -1) continue;\n            cost[to.to] = cost[now] +\
    \ 1;\n            prev[to.to] = now;\n            search(to.to);\n           \
    \ tour.push_back(now);\n        }\n        post_order.push_back(now);\n    }\n\
    \    vector<int> path(int to) {\n        assert(to < n_node);\n        vector<int>\
    \ res;\n        while (to != -1) {\n            res.push_back(to);\n         \
    \   to = prev[to];\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"edge.hpp\"\n#include \"../core/stdlib.hpp\"\n\n\
    namespace bys {\nstruct DepthFirstSearch {\n    const Adj& graph;\n    int n_node;\n\
    \    vector<int> cost;\n    vector<int> pre_order;\n    vector<int> post_order;\n\
    \    vector<int> tour;\n    vector<int> prev;\n\n    DepthFirstSearch(const Adj&\
    \ graph, int start) : graph(graph), n_node(graph.size()), cost(n_node, -1), prev(n_node,\
    \ -1) {\n        cost[start] = 0;\n        search(start);\n    }\n    DepthFirstSearch(const\
    \ Adj& graph) : graph(graph), n_node(graph.size()), cost(n_node, -1), prev(n_node,\
    \ -1) {}\n\n    void crawl() {\n        for (int i = 0; i < n_node; ++i) {\n \
    \           if (cost[i] == -1) {\n                cost[i] = 0;\n             \
    \   search(i);\n            }\n        }\n    }\n\n    void search(int now) {\n\
    \        // cost[now] = true;\n        pre_order.push_back(now);\n        tour.push_back(now);\n\
    \        for (auto&& to : graph[now]) {\n            if (cost[to.to] != -1) continue;\n\
    \            cost[to.to] = cost[now] + 1;\n            prev[to.to] = now;\n  \
    \          search(to.to);\n            tour.push_back(now);\n        }\n     \
    \   post_order.push_back(now);\n    }\n    vector<int> path(int to) {\n      \
    \  assert(to < n_node);\n        vector<int> res;\n        while (to != -1) {\n\
    \            res.push_back(to);\n            to = prev[to];\n        }\n     \
    \   std::reverse(res.begin(), res.end());\n        return res;\n    }\n};\n} \
    \ // namespace bys\n"
  dependsOn:
  - graph/edge.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: graph/depth_first.hpp
  requiredBy:
  - graph/lca.hpp
  timestamp: '2022-02-09 20:18:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/lca.test.cpp
documentation_of: graph/depth_first.hpp
layout: document
redirect_from:
- /library/graph/depth_first.hpp
- /library/graph/depth_first.hpp.html
title: graph/depth_first.hpp
---
