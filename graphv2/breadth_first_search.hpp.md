---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/const.hpp
    title: Const
  - icon: ':question:'
    path: core/macro.hpp
    title: Macro
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':heavy_check_mark:'
    path: graphv2/edge.hpp
    title: Edge
  - icon: ':heavy_check_mark:'
    path: graphv2/result.hpp
    title: Shortest Path Result
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Breadth First Search
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
    \ bys\n/**\n * @file macro.hpp\n * @author bayashi_cl\n * @brief Macro\n */\n\
    // clang-format off\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\u30B0\u7528\u51FA\
    \u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\u3057\u306A\u3044\
    \u3002\n#define DEBUG(...) { std::cerr << \"[debug] line\" << std::setw(4) <<\
    \ __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n#define DEBUG(...)\n#endif\n\
    //! @brief print\u3057\u3066return\u3059\u308B\u3002\n#define EXIT(...) { print(__VA_ARGS__);\
    \ return; }\n#define CONCAT_IMPL(a, b) a##b\n#define CONCAT(a, b) CONCAT_IMPL(a,\
    \ b)\n//! @brief [[maybe_unused]]\u306A\u5909\u6570\u3092\u751F\u6210\u3002\n\
    #define UV [[maybe_unused]] auto CONCAT(unused_val_, __LINE__)\n#define RE std::runtime_error(\"\
    line: \" + std::to_string(__LINE__) + \", func: \" + __func__)\n// clang-format\
    \ on\n/**\n * @file edge.hpp\n * @author bayashi_cl\n * @brief Edge\n * @todo\
    \ concept\n */\nnamespace bys {\n//! @brief \u8FBA\nstruct Edge {\n    std::size_t\
    \ src, dest;\n    ll weight;\n    Edge() {}\n    Edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) : src(src), dest(dest), weight(weight) {}\n    bool operator<(const\
    \ Edge& rh) const { return weight < rh.weight; }\n    operator int() const { return\
    \ dest; }\n    friend std::ostream& operator<<(std::ostream& os, const Edge& e)\
    \ {\n        return os << \"{\" << e.src << \" -> \" << e.dest << \": \" << e.weight\
    \ << \"}\";\n    }\n};\n//! @brief \u96A3\u63A5\u30EA\u30B9\u30C8\nstruct DynamicAdjacencyList\
    \ {\n    std::vector<std::vector<Edge>> data;\n    DynamicAdjacencyList(std::size_t\
    \ n) : data(n, vector<Edge>()), _n(n) {}\n    std::vector<vector<Edge>>::reference\
    \ operator[](std::size_t i) { return *(data.begin() + i); }\n    const std::vector<vector<Edge>>::const_reference\
    \ operator[](std::size_t i) const { return *(data.cbegin() + i); }\n    void add_edge(const\
    \ Edge& e) { data[e.src].push_back(e); }\n    void add_edge(std::size_t src, std::size_t\
    \ dest, ll weight = 1) { data[src].push_back({src, dest, weight}); }\n    std::size_t\
    \ size() const { return _n; }\n\n   private:\n    std::size_t _n;\n};\n/**\n *\
    \ @brief \u96A3\u63A5\u30EA\u30B9\u30C8\n *\n * CSR\u5F62\u5F0F\n * See: https://qiita.com/Nachia/items/d420c08b333296f54526\n\
    \ */\nstruct AdjacencyList {\n    AdjacencyList(std::size_t n, std::size_t m)\
    \ : _n(n), _m(m), index(n + 1), _build_flg(m == 0) { buf.reserve(m); }\n\n   \
    \ struct AdjacencyRange {\n        using iterator = std::vector<Edge>::const_iterator;\n\
    \        using reference = std::vector<Edge>::const_reference;\n        iterator\
    \ _begin, _end;\n        iterator begin() const { return _begin; }\n        iterator\
    \ end() const { return _end; }\n        reference operator[](std::size_t i) const\
    \ { return *(_begin + i); }\n        std::size_t size() const { return std::distance(_begin,\
    \ _end); }\n        bool empty() const { return size() == 0; }\n    };\n    AdjacencyRange\
    \ operator[](std::size_t i) const {\n        return AdjacencyRange{data.begin()\
    \ + index[i], data.begin() + index[i + 1]};\n    }\n\n    void build() {\n   \
    \     std::partial_sum(index.begin(), index.end(), index.begin());\n        data.resize(_m);\n\
    \        for (auto&& e : buf) data[--index[e.src]] = e;\n        _build_flg =\
    \ true;\n    }\n    void add_edge(const Edge& e) {\n        ++index[e.src];\n\
    \        buf.emplace_back(e);\n        if (buf.size() == _m) build();\n    }\n\
    \    void add_edge(std::size_t src, std::size_t dest, ll weight = 1) { add_edge(Edge(src,\
    \ dest, weight)); }\n    std::size_t size() const { return _n; }\n    std::size_t\
    \ n_edge() const { return _m; }\n    bool build_flg() const { return _build_flg;\
    \ }\n\n   private:\n    std::size_t _n, _m;\n    std::vector<Edge> buf, data;\n\
    \    std::vector<std::size_t> index;\n    bool _build_flg;\n};\n}  // namespace\
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
    \        return res;\n    }\n};\n}  // namespace bys\n/**\n * @file breadth_first_search.hpp\n\
    \ * @author bayashi_cl\n * @brief Breadth First Search\n *\n * \u5E45\u512A\u5148\
    \u63A2\u7D22\n */\nnamespace bys {\n/**\n * @brief \u5E45\u512A\u5148\u63A2\u7D22\
    \n *\n * O(V + E)\n *\n * @param graph AdjacencyList or DynamicAdjacencyList\n\
    \ * @param source \u59CB\u70B9\n * @return SSSPResult\n * @todo \u591A\u59CB\u70B9\
    \u5BFE\u5FDC\n */\ntemplate <class Adj>\nSSSPResult breadth_first_search(const\
    \ Adj& graph, std::size_t source) {\n    std::size_t n = graph.size();\n    SSSPResult\
    \ res(n, source);\n    std::queue<std::size_t> que;\n    que.emplace(source);\n\
    \    res.cost[source] = 0;\n    while (!que.empty()) {\n        auto top = que.front();\n\
    \        que.pop();\n        for (auto&& next : graph[top]) {\n            if\
    \ (res.cost[next] == LINF) {\n                res.prev[next] = top;\n        \
    \        res.cost[next] = res.cost[top] + 1;\n                que.emplace(next.dest);\n\
    \            }\n        }\n    }\n    return res;\n}\n/**\n * @brief 01BFS\n *\n\
    \ * O(V + E)\n *\n * @param graph AdjacencyList or DynamicAdjacencyList\n * @param\
    \ source \u59CB\u70B9\n * @return SSSPResult\n */\ntemplate <class Adj>\nSSSPResult\
    \ zero_one_bfs(const Adj& graph, std::size_t source) {\n    std::size_t n = graph.size();\n\
    \    SSSPResult res(n, source);\n    std::deque<std::size_t> que;\n    que.emplace_back(source);\n\
    \    res.cost[source] = 0;\n    while (!que.empty()) {\n        auto top = que.front();\n\
    \        que.pop_front();\n        for (auto&& next : graph[top]) {\n        \
    \    ll next_cost = res.cost[top] + next.weight;\n            if (next_cost >=\
    \ res.cost[next]) continue;\n            res.cost[next] = next_cost;\n       \
    \     res.prev[next] = top;\n            if (next.weight == 0) {\n           \
    \     que.emplace_front(next.dest);\n            } else if (next.weight == 1)\
    \ {\n                que.emplace_back(next.dest);\n            } else {\n    \
    \            throw RE;\n            }\n        }\n    }\n    return res;\n}\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include \"../core/const.hpp\"\n#include \"../core/macro.hpp\"\
    \n#include \"../core/stdlib.hpp\"\n#include \"edge.hpp\"\n#include \"result.hpp\"\
    \n/**\n * @file breadth_first_search.hpp\n * @author bayashi_cl\n * @brief Breadth\
    \ First Search\n *\n * \u5E45\u512A\u5148\u63A2\u7D22\n */\nnamespace bys {\n\
    /**\n * @brief \u5E45\u512A\u5148\u63A2\u7D22\n *\n * O(V + E)\n *\n * @param\
    \ graph AdjacencyList or DynamicAdjacencyList\n * @param source \u59CB\u70B9\n\
    \ * @return SSSPResult\n * @todo \u591A\u59CB\u70B9\u5BFE\u5FDC\n */\ntemplate\
    \ <class Adj>\nSSSPResult breadth_first_search(const Adj& graph, std::size_t source)\
    \ {\n    std::size_t n = graph.size();\n    SSSPResult res(n, source);\n    std::queue<std::size_t>\
    \ que;\n    que.emplace(source);\n    res.cost[source] = 0;\n    while (!que.empty())\
    \ {\n        auto top = que.front();\n        que.pop();\n        for (auto&&\
    \ next : graph[top]) {\n            if (res.cost[next] == LINF) {\n          \
    \      res.prev[next] = top;\n                res.cost[next] = res.cost[top] +\
    \ 1;\n                que.emplace(next.dest);\n            }\n        }\n    }\n\
    \    return res;\n}\n/**\n * @brief 01BFS\n *\n * O(V + E)\n *\n * @param graph\
    \ AdjacencyList or DynamicAdjacencyList\n * @param source \u59CB\u70B9\n * @return\
    \ SSSPResult\n */\ntemplate <class Adj>\nSSSPResult zero_one_bfs(const Adj& graph,\
    \ std::size_t source) {\n    std::size_t n = graph.size();\n    SSSPResult res(n,\
    \ source);\n    std::deque<std::size_t> que;\n    que.emplace_back(source);\n\
    \    res.cost[source] = 0;\n    while (!que.empty()) {\n        auto top = que.front();\n\
    \        que.pop_front();\n        for (auto&& next : graph[top]) {\n        \
    \    ll next_cost = res.cost[top] + next.weight;\n            if (next_cost >=\
    \ res.cost[next]) continue;\n            res.cost[next] = next_cost;\n       \
    \     res.prev[next] = top;\n            if (next.weight == 0) {\n           \
    \     que.emplace_front(next.dest);\n            } else if (next.weight == 1)\
    \ {\n                que.emplace_back(next.dest);\n            } else {\n    \
    \            throw RE;\n            }\n        }\n    }\n    return res;\n}\n\
    }  // namespace bys\n"
  dependsOn:
  - core/const.hpp
  - core/stdlib.hpp
  - core/macro.hpp
  - graphv2/edge.hpp
  - graphv2/result.hpp
  isVerificationFile: false
  path: graphv2/breadth_first_search.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/bfs_grid.test.cpp
documentation_of: graphv2/breadth_first_search.hpp
layout: document
redirect_from:
- /library/graphv2/breadth_first_search.hpp
- /library/graphv2/breadth_first_search.hpp.html
title: Breadth First Search
---
