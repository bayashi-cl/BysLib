---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/cumulative_sum_2D.test.cpp
    title: test/data/cumulative_sum_2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RAQ.test.cpp
    title: test/data/dual_segment_tree_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RUQ.test.cpp
    title: test/data/dual_segment_tree_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
    title: test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
    title: test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RMQ.test.cpp
    title: test/data/segment_tree_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ.test.cpp
    title: test/data/segment_tree_RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/segment_tree_RSQ2.test.cpp
    title: test/data/segment_tree_RSQ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/sparse_table.test.cpp
    title: test/data/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/union_find.test.cpp
    title: test/data/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford.test.cpp
    title: test/graph/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshallfloyd.test.cpp
    title: test/graph/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/bfs_grid.test.cpp
    title: test/graphv2/bfs_grid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graphv2/warshallfloyd.test.cpp
    title: test/graphv2/warshallfloyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/combination.test.cpp
    title: test/math/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/euclid.test.cpp
    title: test/math/euclid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: test/math/osa_k.test.cpp
  - icon: ':x:'
    path: test/utility/range.test.cpp
    title: test/utility/range.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Python::range
    links:
    - https://docs.python.org/ja/3/library/stdtypes.html#range
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
    \ T>;\n}  // namespace bys\n/**\n * @file range.hpp\n * @author bayashi_cl\n *\
    \ @brief Python::range\n *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA range\u7DE8\
    \n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n */\nnamespace\
    \ bys {\ntemplate <typename T>\nclass Range {\n    T it;\n    const T stop, step;\n\
    \    const int dir;\n\n   public:\n    Range(T start, T stop, T step = 1) : it(start),\
    \ stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}\n    Range(T stop) : it(0),\
    \ stop(stop), step(1), dir(1) {}\n    Range<T> begin() const { return *this; }\n\
    \    T end() const { return stop; }\n    bool operator!=(const T val) const {\
    \ return (val - it) * dir > 0; }\n    void operator++() { it += step; }\n    const\
    \ T& operator*() const { return it; }\n\n    friend Range reversed(const Range&\
    \ r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step + r.it;\n\
    \        return {new_start, r.it - r.dir, -r.step};\n    }\n};\n//! @brief range(stop)\n\
    template <class T>\nRange<T> irange(T stop) {\n    return Range(stop);\n}\n//!\
    \ @brief range(start, stop[, step])\ntemplate <class T>\nRange<T> irange(T start,\
    \ T stop, T step = 1) {\n    return Range(start, stop, step);\n}\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n/**\n * @file range.hpp\n\
    \ * @author bayashi_cl\n * @brief Python::range\n *\n * Python\u518D\u73FE\u30B7\
    \u30EA\u30FC\u30BA range\u7DE8\n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n\
    \ */\nnamespace bys {\ntemplate <typename T>\nclass Range {\n    T it;\n    const\
    \ T stop, step;\n    const int dir;\n\n   public:\n    Range(T start, T stop,\
    \ T step = 1) : it(start), stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}\n\
    \    Range(T stop) : it(0), stop(stop), step(1), dir(1) {}\n    Range<T> begin()\
    \ const { return *this; }\n    T end() const { return stop; }\n    bool operator!=(const\
    \ T val) const { return (val - it) * dir > 0; }\n    void operator++() { it +=\
    \ step; }\n    const T& operator*() const { return it; }\n\n    friend Range reversed(const\
    \ Range& r) {\n        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step\
    \ + r.it;\n        return {new_start, r.it - r.dir, -r.step};\n    }\n};\n//!\
    \ @brief range(stop)\ntemplate <class T>\nRange<T> irange(T stop) {\n    return\
    \ Range(stop);\n}\n//! @brief range(start, stop[, step])\ntemplate <class T>\n\
    Range<T> irange(T start, T stop, T step = 1) {\n    return Range(start, stop,\
    \ step);\n}\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: utility/range.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/osa_k.test.cpp
  - test/math/combination.test.cpp
  - test/math/euclid.test.cpp
  - test/utility/range.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/segment_tree_RSQ2.test.cpp
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - test/data/cumulative_sum_2D.test.cpp
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
  - test/data/union_find.test.cpp
  - test/data/segment_tree_RMQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
  - test/data/segment_tree_RSQ.test.cpp
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: utility/range.hpp
layout: document
redirect_from:
- /library/utility/range.hpp
- /library/utility/range.hpp.html
title: Python::range
---
