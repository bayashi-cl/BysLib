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
  - icon: ':heavy_check_mark:'
    path: utility/change.hpp
    title: chmin/chmax
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ bys\n/**\n * @file change.hpp\n * @author bayashi_cl\n * @brief chmin/chmax\n\
    \ */\nnamespace bys {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n *\
    \ @return true \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class\
    \ T>\ninline bool chmax(T& a, const T& b) {\n    return a < b ? a = b, true :\
    \ false;\n}\n/**\n * @brief \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true\
    \ \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T>\ninline\
    \ bool chmin(T& a, const T& b) {\n    return a > b ? a = b, true : false;\n}\n\
    }  // namespace bys\n\nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\nstruct Edge {\n    int from, to;\n    ll\
    \ cost;\n\n    //! @brief \u91CD\u307F\u306A\u3057\u5358\u9802\u70B9\n    Edge(int\
    \ to) : from(-1), to(to), cost(1) {}\n    //! @brief \u91CD\u307F\u4ED8\u304D\u5358\
    \u9802\u70B9\n    Edge(int to, ll cost) : from(-1), to(to), cost(cost) {}\n  \
    \  //! @brief \u91CD\u307F\u4ED8\u304D\u4E21\u9802\u70B9\n    Edge(int from, int\
    \ to, ll cost) : from(from), to(to), cost(cost) {}\n    bool operator<(const Edge&\
    \ rh) const { return cost < rh.cost; }\n    operator std::size_t() const { return\
    \ to; }\n    friend std::ostream& operator<<(std::ostream& os, const Edge& e)\
    \ {\n        return os << \"{\" << e.from << \" -> \" << e.to << \": \" << e.cost\
    \ << \"}\";\n    }\n};\nusing Adj = vector<vector<Edge>>;\nusing EdgeList = vector<Edge>;\n\
    }  // namespace bys\n\nnamespace bys {\nstruct BellmanFord {\n    const EdgeList&\
    \ graph;\n    int n_node;\n    vector<ll> cost;\n    bool negative_cycle;\n\n\
    \    BellmanFord(const EdgeList& graph, int n_node, int start) : graph(graph),\
    \ n_node(n_node), cost(n_node, LINF) {\n        negative_cycle = search(start);\n\
    \    }\n\n    bool search(int start) {\n        cost[start] = 0;\n        for\
    \ (int i = 0; i < n_node - 1; ++i) relaxing();\n        return relaxing();\n \
    \   }\n\n   private:\n    bool relaxing() {\n        bool res = false;\n     \
    \   for (auto&& e : graph) {\n            if (cost[e.from] == LINF) continue;\n\
    \            if (chmin(cost[e.to], cost[e.from] + e.cost)) res = true;\n     \
    \   }\n        return res;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/const.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n#include \"../utility/change.hpp\"\n#include \"edge.hpp\"\n\nnamespace bys {\n\
    struct BellmanFord {\n    const EdgeList& graph;\n    int n_node;\n    vector<ll>\
    \ cost;\n    bool negative_cycle;\n\n    BellmanFord(const EdgeList& graph, int\
    \ n_node, int start) : graph(graph), n_node(n_node), cost(n_node, LINF) {\n  \
    \      negative_cycle = search(start);\n    }\n\n    bool search(int start) {\n\
    \        cost[start] = 0;\n        for (int i = 0; i < n_node - 1; ++i) relaxing();\n\
    \        return relaxing();\n    }\n\n   private:\n    bool relaxing() {\n   \
    \     bool res = false;\n        for (auto&& e : graph) {\n            if (cost[e.from]\
    \ == LINF) continue;\n            if (chmin(cost[e.to], cost[e.from] + e.cost))\
    \ res = true;\n        }\n        return res;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - core/const.hpp
  - core/stdlib.hpp
  - utility/change.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bellman_ford.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: graph/bellman_ford.hpp
---
