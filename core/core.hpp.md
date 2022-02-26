---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/const.hpp
    title: core/const.hpp
  - icon: ':heavy_check_mark:'
    path: core/io.hpp
    title: core/io.hpp
  - icon: ':heavy_check_mark:'
    path: core/macro.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\
      \u3067\u306F\u4F55\u3082\u3057\u306A\u3044\u3002"
  - icon: ':heavy_check_mark:'
    path: core/printer.hpp
    title: core/printer.hpp
  - icon: ':heavy_check_mark:'
    path: core/scanner.hpp
    title: core/scanner.hpp
  - icon: ':heavy_check_mark:'
    path: core/solver.hpp
    title: core/solver.hpp
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: core/types.hpp
    title: core/types.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree_aux.test.cpp
    title: test/data/binary_indexed_tree_aux.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum.test.cpp
    title: test/data/cumulative_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree.test.cpp
    title: test/data/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/union_find.test.cpp
    title: test/data/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/counter_clockwise.test.cpp
    title: test/geometry/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
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
    path: test/graphv2/dijkstra.test.cpp
    title: test/graphv2/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: test/math/osa_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/prime.test.cpp
    title: test/math/prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/test.test.cpp
    title: test/test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/utility/range.test.cpp
    title: test/utility/range.test.cpp
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
    \ bys\n#line 3 \"core/const.hpp\"\n\nnamespace bys {\nconstexpr int MOD = 998244353;\n\
    constexpr int MOD7 = 1000000007;\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll LINF = std::numeric_limits<ll>::max() / 2;\n}  // namespace\
    \ bys\n#line 4 \"core/types.hpp\"\n#include <utility>\n\nnamespace bys {\ntemplate\
    \ <class, class = void>\nstruct has_lshift_to_ostream : std::false_type {};\n\
    template <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\n\ntemplate <class, class = void>\n\
    struct has_rshift_from_istream : std::false_type {};\ntemplate <class T>\nstruct\
    \ has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\n\ntemplate <class T, class =\
    \ void>\nstruct has_tuple_interface : std::false_type {};\ntemplate <class T>\n\
    struct has_tuple_interface<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\n\ntemplate <class, class = void>\nstruct has_iterator : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_iterator<T, std::void_t<typename T::iterator>>\
    \ : std::true_type {};\n\nstruct Int1 {};\n}  // namespace bys\n#line 4 \"core/printer.hpp\"\
    \n\nnamespace bys {\nstruct Printer {\n    Printer(std::ostream& os_) : os(os_)\
    \ {}\n    ~Printer() { os << std::flush; }\n\n    template <class T>\n    void\
    \ cat(T&& v) {\n        if constexpr (has_lshift_to_ostream<std::decay_t<T>>::value)\
    \ {\n            os << v;\n        } else if constexpr (has_iterator<std::decay_t<T>>::value)\
    \ {\n            string sep2;\n            if constexpr (has_iterator<std::decay_t<typename\
    \ std::decay_t<T>::value_type>>::value) {\n                sep2 = _end;\n    \
    \        } else {\n                sep2 = _sep;\n            }\n            for\
    \ (auto &&itr = std::begin(v), end = std::end(v); itr != end; ++itr) {\n     \
    \           cat(*itr);\n                if (std::next(itr) != end) cat(sep2);\n\
    \            }\n        } else if constexpr (has_tuple_interface<std::decay_t<T>>::value)\
    \ {\n            print_tuple(std::forward<T>(v), std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n\
    \        } else {\n            static_assert([] { return false; }(), \"type error\"\
    );\n        }\n    }\n    void print() { cat(_end); }\n    template <class T>\n\
    \    void print(T&& top) {\n        cat(std::forward<T>(top));\n        cat(_end);\n\
    \    }\n    template <class T, class... Ts>\n    void print(T&& top, Ts&&... args)\
    \ {\n        cat(std::forward<T>(top));\n        cat(_sep);\n        print(std::forward<Ts>(args)...);\n\
    \    }\n    template <class... Ts>\n    void operator()(Ts&&... args) {\n    \
    \    print(std::forward<Ts>(args)...);\n    }\n\n    void flush() { os << std::flush;\
    \ }\n    template <class... Ts>\n    void send(Ts&&... args) {\n        print(std::forward<Ts>(args)...);\n\
    \        flush();\n    }\n\n    Printer set(string sep_ = \" \", string end_ =\
    \ \"\\n\") {\n        _sep = sep_;\n        _end = end_;\n        return *this;\n\
    \    }\n    void lf() { cat(_end); }\n\n   private:\n    std::ostream& os;\n \
    \   std::string _sep = \" \", _end = \"\\n\";\n    template <std::size_t I, class\
    \ T>\n    inline void print_tuple_element(T&& elem) {\n        if constexpr (I\
    \ != 0) cat(_sep);\n        cat(std::forward<T>(elem));\n    }\n    template <class\
    \ Tp, std::size_t... I>\n    inline void print_tuple(Tp&& tp, std::index_sequence<I...>)\
    \ {\n        (print_tuple_element<I>(std::forward<decltype(std::get<I>(tp))>(std::get<I>(tp))),\
    \ ...);\n    }\n};\n}  // namespace bys\n#line 4 \"core/scanner.hpp\"\n\nnamespace\
    \ bys {\nstruct Scanner {\n    Scanner(std::istream& is_) : is(is_){};\n\n   \
    \ template <class... Ts>\n    void scan(Ts&... args) {\n        (is >> ... >>\
    \ args);\n    }\n\n    template <class T, class... Us>\n    decltype(auto) read()\
    \ {\n        if constexpr (sizeof...(Us) == 0) {\n            if constexpr (has_rshift_from_istream<T>::value)\
    \ {\n                T res;\n                is >> res;\n                return\
    \ res;\n            } else if constexpr (has_tuple_interface<T>::value) {\n  \
    \              auto res = read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \                return res;\n            } else if constexpr (std::is_same_v<T,\
    \ Int1>) {\n                int res;\n                is >> res;\n           \
    \     --res;\n                return res;\n            } else if constexpr (has_iterator<T>::value)\
    \ {\n                //! TODO: \u4E00\u884C\u8AAD\u3093\u3067split\n         \
    \       static_assert([] { return false; }(), \"NotImplementedError\");\n    \
    \        } else {\n                static_assert([] { return false; }(), \"TypeError\"\
    );\n            }\n        } else {\n            return std::tuple{read<T>(),\
    \ read<Us>()...};\n        }\n    }\n\n    template <class T, std::size_t N, typename\
    \ R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>\n    std::array<R,\
    \ N> read() {\n        std::array<R, N> res;\n        for (auto&& e : res) e =\
    \ read<T>();\n        return res;\n    }\n\n    template <class T, typename R\
    \ = std::conditional_t<std::is_same_v<T, Int1>, int, T>>\n    vector<R> readvec(int\
    \ n) {\n        vector<R> res(n);\n        for (auto&& e : res) e = read<T>();\n\
    \        return res;\n    }\n    template <class T, typename R = std::conditional_t<std::is_same_v<T,\
    \ Int1>, int, T>>\n    vector<vector<R>> readvec(int n, int m) {\n        vector<vector<R>>\
    \ res(n);\n        for (auto&& e : res) e = readvec<T>(m);\n        return res;\n\
    \    }\n\n    template <class Lambda = std::function<int(std::string)>,\n    \
    \          typename T = std::invoke_result_t<std::decay_t<Lambda>, std::string>>\n\
    \    std::vector<T> readln(\n        Lambda f = [](string x) { return std::stoi(x);\
    \ }, char sep = ' ') {\n        std::ws(is);\n        std::string elem;\n    \
    \    std::getline(is, elem);\n        std::stringstream ss{elem};\n        std::vector<T>\
    \ res;\n        while (std::getline(ss, elem, sep)) res.emplace_back(f(elem));\n\
    \        return res;\n    }\n    std::string getline(bool skip_ws = true) {\n\
    \        if (skip_ws) std::ws(is);\n        std::string res;\n        std::getline(is,\
    \ res);\n        return res;\n    }\n\n   private:\n    std::istream& is;\n  \
    \  template <class Tp, std::size_t... I>\n    inline decltype(auto) read_tuple(std::index_sequence<I...>)\
    \ {\n        return Tp{read<typename std::tuple_element_t<I, Tp>>()...};\n   \
    \ }\n};\n}  // namespace bys\n#line 5 \"core/io.hpp\"\n\nnamespace bys {\n__attribute__((constructor))\
    \ void setup_io() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::cout << std::fixed << std::setprecision(11);\n    std::cerr << std::fixed\
    \ << std::setprecision(11);\n    std::cerr << std::boolalpha;\n}\n\nPrinter print(std::cout),\
    \ debug(std::cerr);\nScanner scanner(std::cin);\n}  // namespace bys\n#line 2\
    \ \"core/macro.hpp\"\n// clang-format off\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\
    \u30C3\u30B0\u7528\u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\
    \u3082\u3057\u306A\u3044\u3002\n#define DEBUG(...) { std::cerr << \"[debug] line\"\
    \ << std::setw(4) << __LINE__ << \": \"; debug(__VA_ARGS__); }\n#else\n#define\
    \ DEBUG(...)\n#endif\n//! @brief print\u3057\u3066return\u3059\u308B\u3002\n#define\
    \ EXIT(...) { print(__VA_ARGS__); return; }\n#define CONCAT_IMPL(a, b) a##b\n\
    #define CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\u5909\
    \u6570\u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"line: \" + std::to_string(__LINE__)\
    \ + \", func: \" + __func__)\n// clang-format on\n#line 2 \"core/solver.hpp\"\n\
    \nnamespace bys {\nstruct Solver {\n    int IT = 1;\n    Solver() {}\n    void\
    \ solve();\n    void solve(int rep) {\n        for (; IT <= rep; ++IT) solve();\n\
    \    }\n};\n}  // namespace bys\n#line 7 \"core/core.hpp\"\n"
  code: '#pragma once

    #include "stdlib.hpp"

    #include "const.hpp"

    #include "io.hpp"

    #include "macro.hpp"

    #include "solver.hpp"

    '
  dependsOn:
  - core/stdlib.hpp
  - core/const.hpp
  - core/io.hpp
  - core/printer.hpp
  - core/types.hpp
  - core/scanner.hpp
  - core/macro.hpp
  - core/solver.hpp
  isVerificationFile: false
  path: core/core.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2022-02-09 20:18:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime.test.cpp
  - test/math/osa_k.test.cpp
  - test/geometry/area.test.cpp
  - test/geometry/counter_clockwise.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
  - test/geometry/is_convex.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/intersection.test.cpp
  - test/geometry/cross_point.test.cpp
  - test/utility/range.test.cpp
  - test/test.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/binary_indexed_tree_aux.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
  - test/data/cumulative_sum.test.cpp
  - test/data/union_find.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graphv2/dijkstra.test.cpp
  - test/graph/bfs_grid.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/lca.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/dijkstra.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: core/core.hpp
layout: document
redirect_from:
- /library/core/core.hpp
- /library/core/core.hpp.html
title: core/core.hpp
---
