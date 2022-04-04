---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/const.hpp
    title: Const
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs_grid.test.cpp
    title: test/graph/bfs_grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ bys\n/**\n * @file const.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr\
    \ int MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\nconstexpr int INF =\
    \ std::numeric_limits<int>::max() / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max()\
    \ / 2;\n}  // namespace bys\n\nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\nstruct Edge {\n    int from, to;\n\
    \    ll cost;\n\n    //! @brief \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\n \
    \   Edge(int to) : from(-1), to(to), cost(1) {}\n    //! @brief \u91CD\u307F\u4ED8\
    \u304D\u5358\u9802\u70B9\n    Edge(int to, ll cost) : from(-1), to(to), cost(cost)\
    \ {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u4E21\u9802\u70B9\n    Edge(int\
    \ from, int to, ll cost) : from(from), to(to), cost(cost) {}\n    bool operator<(const\
    \ Edge& rh) const { return cost < rh.cost; }\n    operator std::size_t() const\
    \ { return to; }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Edge& e) {\n        return os << \"{\" << e.from << \" -> \" << e.to << \":\
    \ \" << e.cost << \"}\";\n    }\n};\nusing Adj = vector<vector<Edge>>;\nusing\
    \ EdgeList = vector<Edge>;\n}  // namespace bys\n\nnamespace bys {\nstruct BreadthFirstSearch\
    \ {\n    int n_node;\n    vector<int> prev;\n    vector<int> cost;\n\n    BreadthFirstSearch(const\
    \ Adj& graph, int start, int err_val = -1)\n        : n_node(graph.size()), prev(n_node,\
    \ -1), cost(n_node, INF) {\n        search(graph, start);\n        std::replace(cost.begin(),\
    \ cost.end(), INF, err_val);\n    }\n\n    void search(const Adj& graph, int start)\
    \ {\n        cost[start] = 0;\n        std::queue<int> que;\n        que.push(start);\n\
    \        while (!que.empty()) {\n            int from = que.front();\n       \
    \     que.pop();\n            for (auto&& to : graph[from]) {\n              \
    \  if (cost[to.to] == INF) {\n                    prev[to.to] = from;\n      \
    \              cost[to.to] = cost[from] + 1;\n                    que.push(to.to);\n\
    \                }\n            }\n        }\n    }\n    vector<int> path(int\
    \ to) {\n        assert(to < n_node);\n        vector<int> res;\n        while\
    \ (to != -1) {\n            res.push_back(to);\n            to = prev[to];\n \
    \       }\n        std::reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n};\nstruct ZeroOneBFS {\n    int n_node;\n    vector<int> cost;\n    vector<int>\
    \ prev;\n\n    ZeroOneBFS(Adj& graph, int start, int err_val = -1) : n_node(graph.size()),\
    \ cost(n_node, INF), prev(n_node, -1) {\n        search(graph, start);\n     \
    \   std::replace(cost.begin(), cost.end(), INF, err_val);\n    }\n\n    void search(const\
    \ Adj& graph, int start) {\n        std::deque<int> que;\n        cost[start]\
    \ = 0;\n        que.push_back(start);\n        while (!que.empty()) {\n      \
    \      int now = que.front();\n            que.pop_front();\n            for (auto&&\
    \ to : graph[now]) {\n                int dist = cost[now] + to.cost;\n      \
    \          if (dist >= cost[to.to]) continue;\n                cost[to.to] = dist;\n\
    \                prev[to.to] = now;\n                if (to.cost == 0) {\n   \
    \                 que.push_front(to.to);\n                } else {\n         \
    \           que.push_back(to.to);\n                }\n            }\n        }\n\
    \    }\n    vector<int> path(int to) {\n        assert(to < n_node);\n       \
    \ vector<int> res;\n        while (to != -1) {\n            res.push_back(to);\n\
    \            to = prev[to];\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../core/const.hpp\"\
    \n#include \"edge.hpp\"\n\nnamespace bys {\nstruct BreadthFirstSearch {\n    int\
    \ n_node;\n    vector<int> prev;\n    vector<int> cost;\n\n    BreadthFirstSearch(const\
    \ Adj& graph, int start, int err_val = -1)\n        : n_node(graph.size()), prev(n_node,\
    \ -1), cost(n_node, INF) {\n        search(graph, start);\n        std::replace(cost.begin(),\
    \ cost.end(), INF, err_val);\n    }\n\n    void search(const Adj& graph, int start)\
    \ {\n        cost[start] = 0;\n        std::queue<int> que;\n        que.push(start);\n\
    \        while (!que.empty()) {\n            int from = que.front();\n       \
    \     que.pop();\n            for (auto&& to : graph[from]) {\n              \
    \  if (cost[to.to] == INF) {\n                    prev[to.to] = from;\n      \
    \              cost[to.to] = cost[from] + 1;\n                    que.push(to.to);\n\
    \                }\n            }\n        }\n    }\n    vector<int> path(int\
    \ to) {\n        assert(to < n_node);\n        vector<int> res;\n        while\
    \ (to != -1) {\n            res.push_back(to);\n            to = prev[to];\n \
    \       }\n        std::reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n};\nstruct ZeroOneBFS {\n    int n_node;\n    vector<int> cost;\n    vector<int>\
    \ prev;\n\n    ZeroOneBFS(Adj& graph, int start, int err_val = -1) : n_node(graph.size()),\
    \ cost(n_node, INF), prev(n_node, -1) {\n        search(graph, start);\n     \
    \   std::replace(cost.begin(), cost.end(), INF, err_val);\n    }\n\n    void search(const\
    \ Adj& graph, int start) {\n        std::deque<int> que;\n        cost[start]\
    \ = 0;\n        que.push_back(start);\n        while (!que.empty()) {\n      \
    \      int now = que.front();\n            que.pop_front();\n            for (auto&&\
    \ to : graph[now]) {\n                int dist = cost[now] + to.cost;\n      \
    \          if (dist >= cost[to.to]) continue;\n                cost[to.to] = dist;\n\
    \                prev[to.to] = now;\n                if (to.cost == 0) {\n   \
    \                 que.push_front(to.to);\n                } else {\n         \
    \           que.push_back(to.to);\n                }\n            }\n        }\n\
    \    }\n    vector<int> path(int to) {\n        assert(to < n_node);\n       \
    \ vector<int> res;\n        while (to != -1) {\n            res.push_back(to);\n\
    \            to = prev[to];\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - core/const.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/breadth_first.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs_grid.test.cpp
documentation_of: graph/breadth_first.hpp
layout: document
redirect_from:
- /library/graph/breadth_first.hpp
- /library/graph/breadth_first.hpp.html
title: graph/breadth_first.hpp
---
