---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: graph/depth_first.hpp
    title: graph/depth_first.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/lca.test.cpp
    title: test/graph/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ = vector<vector<Edge>>;\nusing EdgeList = vector<Edge>;\n}  // namespace bys\n\
    \nnamespace bys {\nstruct DepthFirstSearch {\n    const Adj& graph;\n    int n_node;\n\
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
    \ // namespace bys\n\nnamespace bys {\nstruct LowestCommonAncestor {\n    const\
    \ Adj& graph;\n    const int n_node;\n    DepthFirstSearch dfs;\n    vector<vector<int>>\
    \ parent;\n    int log_size = 1;\n\n    LowestCommonAncestor(const Adj& graph,\
    \ int root = 0) : graph(graph), n_node(graph.size()), dfs(graph, root) {\n   \
    \     while ((1 << log_size) < n_node) ++log_size;\n        parent.assign(log_size,\
    \ vector<int>(n_node, -1));\n        parent[0] = dfs.prev;\n        for (int i\
    \ = 0; i < log_size - 1; i++) {\n            for (int j = 0; j < n_node; j++)\
    \ {\n                if (parent[i][j] < 0) {\n                    parent[i + 1][j]\
    \ = -1;\n                } else {\n                    parent[i + 1][j] = parent[i][parent[i][j]];\n\
    \                }\n            }\n        }\n    }\n    int prev(int n, int x)\
    \ const {\n        // n\u306Ex\u500B\u4E0A\n        for (int k = 0; k < log_size;\
    \ k++) {\n            if (x >> k & 1) n = parent[k][n];\n        }\n        return\
    \ n;\n    }\n    int lca(int a, int b) const {\n        if (dfs.cost[a] < dfs.cost[b])\
    \ std::swap(a, b);\n        a = prev(a, dfs.cost[a] - dfs.cost[b]);\n        if\
    \ (a == b) return a;\n        for (int k = log_size - 1; k >= 0; k--) {\n    \
    \        if (parent[k][a] != parent[k][b]) {\n                a = parent[k][a];\n\
    \                b = parent[k][b];\n            }\n        }\n        return parent[0][a];\n\
    \    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"depth_first.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n\nnamespace bys {\nstruct LowestCommonAncestor {\n    const Adj& graph;\n  \
    \  const int n_node;\n    DepthFirstSearch dfs;\n    vector<vector<int>> parent;\n\
    \    int log_size = 1;\n\n    LowestCommonAncestor(const Adj& graph, int root\
    \ = 0) : graph(graph), n_node(graph.size()), dfs(graph, root) {\n        while\
    \ ((1 << log_size) < n_node) ++log_size;\n        parent.assign(log_size, vector<int>(n_node,\
    \ -1));\n        parent[0] = dfs.prev;\n        for (int i = 0; i < log_size -\
    \ 1; i++) {\n            for (int j = 0; j < n_node; j++) {\n                if\
    \ (parent[i][j] < 0) {\n                    parent[i + 1][j] = -1;\n         \
    \       } else {\n                    parent[i + 1][j] = parent[i][parent[i][j]];\n\
    \                }\n            }\n        }\n    }\n    int prev(int n, int x)\
    \ const {\n        // n\u306Ex\u500B\u4E0A\n        for (int k = 0; k < log_size;\
    \ k++) {\n            if (x >> k & 1) n = parent[k][n];\n        }\n        return\
    \ n;\n    }\n    int lca(int a, int b) const {\n        if (dfs.cost[a] < dfs.cost[b])\
    \ std::swap(a, b);\n        a = prev(a, dfs.cost[a] - dfs.cost[b]);\n        if\
    \ (a == b) return a;\n        for (int k = log_size - 1; k >= 0; k--) {\n    \
    \        if (parent[k][a] != parent[k][b]) {\n                a = parent[k][a];\n\
    \                b = parent[k][b];\n            }\n        }\n        return parent[0][a];\n\
    \    }\n};\n}  // namespace bys\n"
  dependsOn:
  - graph/depth_first.hpp
  - graph/edge.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/lca.test.cpp
documentation_of: graph/lca.hpp
layout: document
redirect_from:
- /library/graph/lca.hpp
- /library/graph/lca.hpp.html
title: graph/lca.hpp
---
