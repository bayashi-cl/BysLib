---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':question:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/linalg/coo.hpp
    title: byslib/linalg/coo.hpp
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
  bundledCode: "#include <numeric>\n#include <utility>\n#include <vector>\n\n#include\
    \ <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\n#include <cstddef>\n#include <iterator>\n\n#include <array>\n#include <iostream>\n\
    #include <type_traits>\n/**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\
    \u5F35\n */\nnamespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_rshift_from_istream<T,\
    \ std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_rshift_from_istream_v\
    \ = has_rshift_from_istream<T>::value;\n\ntemplate <class, class = void> struct\
    \ has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T,\
    \ std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_lshft_to_ostream_v\
    \ = has_lshift_to_ostream<T>::value;\n\ntemplate <class, class = void> struct\
    \ is_tuple_like : std::false_type {};\ntemplate <class T> struct is_tuple_like<T,\
    \ std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};\ntemplate\
    \ <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\ntemplate\
    \ <class, class = void> struct is_iterable : std::false_type {};\ntemplate <class\
    \ T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \ntemplate <class T> struct Indexed {\n    static_assert(std::is_integral_v<T>);\n\
    \    using resolve_to = T;\n};\nusing i32_1 = Indexed<i32>;\nusing i64_1 = Indexed<i64>;\n\
    \ntemplate <class, class = void> struct is_indexed : std::false_type {};\ntemplate\
    \ <class T> struct is_indexed<Indexed<T>> : std::true_type {};\ntemplate <class\
    \ T> constexpr bool is_indexed_v = is_indexed<T>::value;\n\ntemplate <class T,\
    \ class = void> struct resolve_type { using type = T; };\ntemplate <class T> struct\
    \ resolve_type<T, std::void_t<typename T::resolve_to>> { using type = typename\
    \ T::resolve_to; };\ntemplate <class T, std::size_t N> struct resolve_type<std::array<T,\
    \ N>> {\n    using type = std::array<typename resolve_type<T>::type, N>;\n};\n\
    template <class T, class U> struct resolve_type<std::pair<T, U>> {\n    using\
    \ type = std::pair<typename resolve_type<T>::type, typename resolve_type<U>::type>;\n\
    };\ntemplate <class... Args> struct resolve_type<std::tuple<Args...>> {\n    using\
    \ type = std::tuple<typename resolve_type<Args>::type...>;\n};\ntemplate <class\
    \ T> using resolve_type_t = typename resolve_type<T>::type;\n}  // namespace bys\n\
    \nnamespace bys {\ntemplate <class Iterator> class SubRange {\n  public:\n   \
    \ using iterator = Iterator;\n    using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \    using value_type = typename iterator::value_type;\n\n    SubRange() = default;\n\
    \    SubRange(const SubRange& s) : _begin(s._begin), _end(s._end) {}\n    SubRange(const\
    \ iterator& begin, const iterator& end) : _begin(begin), _end(end) {}\n\n    iterator\
    \ begin() const noexcept { return _begin; }\n    iterator end() const noexcept\
    \ { return _end; }\n    reverse_iterator rbegin() const noexcept { return reverse_iterator{_end};\
    \ }\n    reverse_iterator rend() const { return reverse_iterator{_begin}; }\n\
    \    auto operator[](std::size_t i) const noexcept { return *(_begin + i); }\n\
    \    auto size() const noexcept { return _end - _begin; }\n    bool empty() const\
    \ noexcept { return _begin == _end; }\n\n    auto to_vec() const { return std::vector(_begin,\
    \ _end); }\n\n  private:\n    iterator _begin, _end;\n};\ntemplate <class Iterable>\
    \ auto reversed(Iterable&& iter) {\n    static_assert(is_iterable_v<Iterable>,\
    \ \"iter is not iterable\");\n    return SubRange(std::rbegin(std::forward<Iterable>(iter)),\
    \ std::rend(std::forward<Iterable>(iter)));\n}\n}  // namespace bys\n#include\
    \ <algorithm>\n#include <cassert>\n\nnamespace bys {\ntemplate <class T> struct\
    \ CSRMatrix;\n}\n\nnamespace bys {\ntemplate <class T> class COOMatrix {\n  public:\n\
    \    using value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n\
    \    std::vector<std::tuple<i32, i32, T>> _data;\n    std::vector<i32> _col_cnt;\n\
    \n  public:\n    COOMatrix(i32 n, i32 m = -1) : shape{n, m}, _col_cnt(n) {}\n\n\
    \    void set(i32 i, i32 j, const T& v) {\n        assert(0 <= i and i < shape.first);\n\
    \        ++_col_cnt[i];\n        _data.emplace_back(i, j, v);\n    }\n    void\
    \ push_back(i32 i, T&& v) { set(i, _col_cnt[i], std::forward<T>(v)); }\n    template\
    \ <class... Args> void emplace_back(i32 i, Args&&... args) { set(i, _col_cnt[i],\
    \ {std::forward<Args>(args)...}); }\n    auto begin() const { return _data.begin();\
    \ }\n    auto end() const { return _data.end(); }\n\n    void sort() {\n     \
    \   std::sort(_data.begin(), _data.end(), [](const std::tuple<i32, i32, T>& a,\
    \ const std::tuple<i32, i32, T>& b) {\n            return std::get<2>(a) < std::get<2>(b);\n\
    \        });\n    }\n    std::size_t size() const { return shape.first; }\n  \
    \  std::ptrdiff_t ssize() const { return shape.first; }\n    std::size_t nonzero()\
    \ const { return _data.size(); }\n\n    friend CSRMatrix<T>;\n};\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T> class CSRMatrix {\n  public:\n  \
    \  using value_type = T;\n    const std::pair<i32, i32> shape;\n\n  private:\n\
    \    std::vector<i32> _indptr, _indices;\n    std::vector<T> _data;\n\n  public:\n\
    \    CSRMatrix(const COOMatrix<T>& coo)\n        : shape(coo.shape), _indptr(coo._col_cnt),\
    \ _indices(coo._data.size()), _data(coo._data.size()) {\n        _indptr.push_back(0);\n\
    \n        std::partial_sum(_indptr.begin(), _indptr.end(), _indptr.begin());\n\
    \        for (auto&& [i, j, v] : coo._data) {\n            i32 index = --_indptr[i];\n\
    \            _indices[index] = j;\n            _data[index] = v;\n        }\n\
    \    }\n    CSRMatrix(std::pair<i32, i32> shape, const std::vector<std::vector<std::pair<i32,\
    \ T>>>& data)\n        : shape(shape), _indptr(shape.first + 1) {\n        for\
    \ (i32 i = 0; i < shape.first; ++i) {\n            for (auto&& [index, elem] :\
    \ data[i]) {\n                _indices.push_back(index);\n                _data.push_back(elem);\n\
    \            }\n            _indptr[i + 1] += _indptr[i] + data[i].size();\n \
    \       }\n    }\n    auto operator[](std::size_t i) const { return SubRange(_data.cbegin()\
    \ + _indptr[i], _data.cbegin() + _indptr[i + 1]); }\n    std::size_t size() const\
    \ { return shape.first; }\n    std::ptrdiff_t ssize() const { return shape.first;\
    \ }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \n#include \"../core/int_alias.hpp\"\n#include \"../extension/subrange.hpp\"\n\
    #include \"coo.hpp\"\n\nnamespace bys {\ntemplate <class T> class CSRMatrix {\n\
    \  public:\n    using value_type = T;\n    const std::pair<i32, i32> shape;\n\n\
    \  private:\n    std::vector<i32> _indptr, _indices;\n    std::vector<T> _data;\n\
    \n  public:\n    CSRMatrix(const COOMatrix<T>& coo)\n        : shape(coo.shape),\
    \ _indptr(coo._col_cnt), _indices(coo._data.size()), _data(coo._data.size()) {\n\
    \        _indptr.push_back(0);\n\n        std::partial_sum(_indptr.begin(), _indptr.end(),\
    \ _indptr.begin());\n        for (auto&& [i, j, v] : coo._data) {\n          \
    \  i32 index = --_indptr[i];\n            _indices[index] = j;\n            _data[index]\
    \ = v;\n        }\n    }\n    CSRMatrix(std::pair<i32, i32> shape, const std::vector<std::vector<std::pair<i32,\
    \ T>>>& data)\n        : shape(shape), _indptr(shape.first + 1) {\n        for\
    \ (i32 i = 0; i < shape.first; ++i) {\n            for (auto&& [index, elem] :\
    \ data[i]) {\n                _indices.push_back(index);\n                _data.push_back(elem);\n\
    \            }\n            _indptr[i + 1] += _indptr[i] + data[i].size();\n \
    \       }\n    }\n    auto operator[](std::size_t i) const { return SubRange(_data.cbegin()\
    \ + _indptr[i], _data.cbegin() + _indptr[i + 1]); }\n    std::size_t size() const\
    \ { return shape.first; }\n    std::ptrdiff_t ssize() const { return shape.first;\
    \ }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/extension/subrange.hpp
  - byslib/core/traits.hpp
  - byslib/linalg/coo.hpp
  - byslib/linalg/sparsefwd.hpp
  isVerificationFile: false
  path: byslib/linalg/csr.hpp
  requiredBy:
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
documentation_of: byslib/linalg/csr.hpp
layout: document
redirect_from:
- /library/byslib/linalg/csr.hpp
- /library/byslib/linalg/csr.hpp.html
title: byslib/linalg/csr.hpp
---
