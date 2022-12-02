---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/sparsefwd.hpp
    title: byslib/linalg/sparsefwd.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: byslib/graph/bellman_ford.hpp
    title: Bellman Ford
  - icon: ':warning:'
    path: byslib/graph/bfs.hpp
    title: byslib/graph/bfs.hpp
  - icon: ':warning:'
    path: byslib/graph/dfs.hpp
    title: byslib/graph/dfs.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/dijkstra.hpp
    title: byslib/graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/edge.hpp
    title: byslib/graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/graph.hpp
    title: byslib/graph/graph.hpp
  - icon: ':warning:'
    path: byslib/graph/kruskal.hpp
    title: byslib/graph/kruskal.hpp
  - icon: ':warning:'
    path: byslib/graph/lca.hpp
    title: Lowest Common Ancestor
  - icon: ':warning:'
    path: byslib/graph/reader.hpp
    title: Reader
  - icon: ':warning:'
    path: byslib/graph/shortest_path_tree.hpp
    title: byslib/graph/shortest_path_tree.hpp
  - icon: ':warning:'
    path: byslib/graph/topological_sort.hpp
    title: Topological Sort
  - icon: ':warning:'
    path: byslib/graph/tree.hpp
    title: byslib/graph/tree.hpp
  - icon: ':warning:'
    path: byslib/graph/util.hpp
    title: byslib/graph/util.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/graph/warshall_floyd.hpp
    title: Warshall Floyd
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/csr.hpp
    title: byslib/linalg/csr.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
    using i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\nusing isize\
    \ = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name,\
    \ type) \\\n    constexpr auto operator\"\" name(unsigned long long x) { return\
    \ static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16,\
    \ std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64,\
    \ std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8,\
    \ std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32,\
    \ std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128,\
    \ __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n\
    }  // namespace bys\nnamespace bys {\ntemplate <class T> struct CSRMatrix;\n}\n\
    \nnamespace bys {\ntemplate <class T> class COOMatrix {\n  public:\n    using\
    \ value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n    std::vector<std::tuple<i32,\
    \ i32, T>> _data;\n    std::vector<i32> _col_cnt;\n\n  public:\n    COOMatrix(i32\
    \ n, i32 m = -1) : shape{n, m}, _col_cnt(n) {}\n\n    void set(i32 i, i32 j, const\
    \ T& v) {\n        assert(0 <= i and i < shape.first);\n        ++_col_cnt[i];\n\
    \        _data.emplace_back(i, j, v);\n    }\n    void push_back(i32 i, T&& v)\
    \ { set(i, _col_cnt[i], std::forward<T>(v)); }\n    template <class... Args> void\
    \ emplace_back(i32 i, Args&&... args) { set(i, _col_cnt[i], {std::forward<Args>(args)...});\
    \ }\n    auto begin() const { return _data.begin(); }\n    auto end() const {\
    \ return _data.end(); }\n\n    void sort() {\n        std::sort(_data.begin(),\
    \ _data.end(), [](const std::tuple<i32, i32, T>& a, const std::tuple<i32, i32,\
    \ T>& b) {\n            return std::get<2>(a) < std::get<2>(b);\n        });\n\
    \    }\n    std::size_t size() const { return shape.first; }\n    std::ptrdiff_t\
    \ ssize() const { return shape.first; }\n    std::size_t nonzero() const { return\
    \ _data.size(); }\n\n    friend CSRMatrix<T>;\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#include \"../core/int_alias.hpp\"\n#include \"sparsefwd.hpp\"\
    \n\nnamespace bys {\ntemplate <class T> class COOMatrix {\n  public:\n    using\
    \ value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n    std::vector<std::tuple<i32,\
    \ i32, T>> _data;\n    std::vector<i32> _col_cnt;\n\n  public:\n    COOMatrix(i32\
    \ n, i32 m = -1) : shape{n, m}, _col_cnt(n) {}\n\n    void set(i32 i, i32 j, const\
    \ T& v) {\n        assert(0 <= i and i < shape.first);\n        ++_col_cnt[i];\n\
    \        _data.emplace_back(i, j, v);\n    }\n    void push_back(i32 i, T&& v)\
    \ { set(i, _col_cnt[i], std::forward<T>(v)); }\n    template <class... Args> void\
    \ emplace_back(i32 i, Args&&... args) { set(i, _col_cnt[i], {std::forward<Args>(args)...});\
    \ }\n    auto begin() const { return _data.begin(); }\n    auto end() const {\
    \ return _data.end(); }\n\n    void sort() {\n        std::sort(_data.begin(),\
    \ _data.end(), [](const std::tuple<i32, i32, T>& a, const std::tuple<i32, i32,\
    \ T>& b) {\n            return std::get<2>(a) < std::get<2>(b);\n        });\n\
    \    }\n    std::size_t size() const { return shape.first; }\n    std::ptrdiff_t\
    \ ssize() const { return shape.first; }\n    std::size_t nonzero() const { return\
    \ _data.size(); }\n\n    friend CSRMatrix<T>;\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/linalg/sparsefwd.hpp
  isVerificationFile: false
  path: byslib/linalg/coo.hpp
  requiredBy:
  - byslib/linalg/csr.hpp
  - byslib/graph/bellman_ford.hpp
  - byslib/graph/topological_sort.hpp
  - byslib/graph/bfs.hpp
  - byslib/graph/shortest_path_tree.hpp
  - byslib/graph/dijkstra.hpp
  - byslib/graph/kruskal.hpp
  - byslib/graph/util.hpp
  - byslib/graph/lca.hpp
  - byslib/graph/graph.hpp
  - byslib/graph/tree.hpp
  - byslib/graph/reader.hpp
  - byslib/graph/edge.hpp
  - byslib/graph/dfs.hpp
  - byslib/graph/warshall_floyd.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_A.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
documentation_of: byslib/linalg/coo.hpp
layout: document
redirect_from:
- /library/byslib/linalg/coo.hpp
- /library/byslib/linalg/coo.hpp.html
title: byslib/linalg/coo.hpp
---
