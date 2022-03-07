---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/fixpoint.hpp
    title: utility/fixpoint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <utility>\nnamespace bys {\ntemplate <typename F>\nstruct\
    \ FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)} {}\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \        return F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\
    template <typename F>\ninline FixPoint<std::decay_t<F>> fix(F&& f) {\n    return\
    \ std::forward<std::decay_t<F>>(f);\n}\n}  // namespace bys\n#ifndef LOCAL\n#define\
    \ NDEBUG\n#endif\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
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
    \ T>;\n}  // namespace bys\n\nnamespace bys {\n/**\n * @brief \u30B0\u30E9\u30D5\
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
    \ EdgeList = vector<Edge>;\n}  // namespace bys\nnamespace bys {\nAdj make_directed_tree(const\
    \ Adj& graph, int root = 0) {\n    Adj res(graph.size());\n    FixPoint dfs([&](auto&&\
    \ self, int now, int prev = -1) -> void {\n        for (auto&& nxt : graph[now])\
    \ {\n            if (nxt.to != prev) {\n                res[now].push_back(nxt);\n\
    \                self(nxt.to, now);\n            }\n        }\n    });\n    dfs(root);\n\
    \    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include \"utility/fixpoint.hpp\"\n#include \"edge.hpp\"\n\
    namespace bys {\nAdj make_directed_tree(const Adj& graph, int root = 0) {\n  \
    \  Adj res(graph.size());\n    FixPoint dfs([&](auto&& self, int now, int prev\
    \ = -1) -> void {\n        for (auto&& nxt : graph[now]) {\n            if (nxt.to\
    \ != prev) {\n                res[now].push_back(nxt);\n                self(nxt.to,\
    \ now);\n            }\n        }\n    });\n    dfs(root);\n    return res;\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - utility/fixpoint.hpp
  - graph/edge.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: graph/util.hpp
  requiredBy: []
  timestamp: '2022-02-26 20:23:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/util.hpp
layout: document
redirect_from:
- /library/graph/util.hpp
- /library/graph/util.hpp.html
title: graph/util.hpp
---
