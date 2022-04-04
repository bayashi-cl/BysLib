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
  - icon: ':question:'
    path: utility/change.hpp
    title: chmin/chmax
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
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
    /**\n * @file const.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr int\
    \ MOD = 998244353;\nconstexpr int MOD7 = 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace\
    \ bys\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace bys {\n\
    /**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\
    \u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmax(T&\
    \ a, const T& b) {\n    return a < b ? a = b, true : false;\n}\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\u308C\
    \u305F\u3068\u304D\n */\ntemplate <class T>\ninline bool chmin(T& a, const T&\
    \ b) {\n    return a > b ? a = b, true : false;\n}\n}  // namespace bys\n\nnamespace\
    \ bys {\nstruct WarshallFloyd {\n    int n_node;\n    vector<vector<ll>> cost;\n\
    \    vector<vector<int>> prev;\n\n    WarshallFloyd(const EdgeList& graph, int\
    \ n_node)\n        : n_node(n_node), cost(n_node, vector(n_node, LINF)), prev(n_node,\
    \ vector(n_node, -1)) {\n        for (auto&& e : graph) cost[e.from][e.to] = e.cost;\n\
    \        for (int i = 0; i < n_node; ++i) cost[i][i] = 0;\n        for (int i\
    \ = 0; i < n_node; ++i) {\n            for (int j = 0; j < n_node; ++j) {\n  \
    \              prev[i][j] = i;\n            }\n        }\n        search();\n\
    \    }\n\n    void search() {\n        for (int k = 0; k < n_node; k++) {\n  \
    \          for (int i = 0; i < n_node; i++) {\n                for (int j = 0;\
    \ j < n_node; j++) {\n                    if (chmin(cost[i][j], cost[i][k] + cost[k][j]))\
    \ {\n                        prev[i][j] = prev[k][j];\n                    }\n\
    \                }\n            }\n        }\n    }\n    vector<int> path(int\
    \ from, int to) {\n        vector<int> res;\n        for (int now = to; now !=\
    \ from; now = prev[from][now]) {\n            res.push_back(now);\n        }\n\
    \        res.push_back(from);\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"edge.hpp\"\n#include \"../core/stdlib.hpp\"\n#include\
    \ \"../core/const.hpp\"\n#include \"../utility/change.hpp\"\n\nnamespace bys {\n\
    struct WarshallFloyd {\n    int n_node;\n    vector<vector<ll>> cost;\n    vector<vector<int>>\
    \ prev;\n\n    WarshallFloyd(const EdgeList& graph, int n_node)\n        : n_node(n_node),\
    \ cost(n_node, vector(n_node, LINF)), prev(n_node, vector(n_node, -1)) {\n   \
    \     for (auto&& e : graph) cost[e.from][e.to] = e.cost;\n        for (int i\
    \ = 0; i < n_node; ++i) cost[i][i] = 0;\n        for (int i = 0; i < n_node; ++i)\
    \ {\n            for (int j = 0; j < n_node; ++j) {\n                prev[i][j]\
    \ = i;\n            }\n        }\n        search();\n    }\n\n    void search()\
    \ {\n        for (int k = 0; k < n_node; k++) {\n            for (int i = 0; i\
    \ < n_node; i++) {\n                for (int j = 0; j < n_node; j++) {\n     \
    \               if (chmin(cost[i][j], cost[i][k] + cost[k][j])) {\n          \
    \              prev[i][j] = prev[k][j];\n                    }\n             \
    \   }\n            }\n        }\n    }\n    vector<int> path(int from, int to)\
    \ {\n        vector<int> res;\n        for (int now = to; now != from; now = prev[from][now])\
    \ {\n            res.push_back(now);\n        }\n        res.push_back(from);\n\
    \        std::reverse(res.begin(), res.end());\n        return res;\n    }\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - graph/edge.hpp
  - core/stdlib.hpp
  - core/const.hpp
  - utility/change.hpp
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshallfloyd.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
