---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/binary_indexed_tree.test.cpp
    title: test/data/binary_indexed_tree.test.cpp
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
    path: test/math/osa_k.test.cpp
    title: test/math/osa_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/utility/range.test.cpp
    title: test/utility/range.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Python\u306Erange"
    links: []
  bundledCode: "\nnamespace bys {\n//! @brief Python\u306Erange\ntemplate <typename\
    \ T>\nstruct Range {\n    Range(T start, T stop, T step = 1) : it(start), stop(stop),\
    \ step(step), dir(step >= 0 ? 1 : -1) {}\n    Range(T stop) : it(0), stop(stop),\
    \ step(1), dir(1) {}\n    Range<T> begin() const { return *this; }\n    T end()\
    \ const { return stop; }\n    bool operator!=(const T val) const { return (val\
    \ - it) * dir > 0; }\n    void operator++() { it += step; }\n    const T& operator*()\
    \ const { return it; }\n\n   private:\n    T it;\n    const T stop, step;\n  \
    \  const int dir;\n\n    friend Range reversed(const Range& r) {\n        auto\
    \ new_start = (r.stop - r.dir - r.it) / r.step * r.step + r.it;\n        return\
    \ {new_start, r.it - r.dir, -r.step};\n    }\n};\ntemplate <class T>\nRange<T>\
    \ irange(T stop) {\n    return Range(stop);\n}\ntemplate <class T>\nRange<T> irange(T\
    \ start, T stop, T step = 1) {\n    return Range(start, stop, step);\n}\n}  //\
    \ namespace bys\n"
  code: "#pragma once\n\nnamespace bys {\n//! @brief Python\u306Erange\ntemplate <typename\
    \ T>\nstruct Range {\n    Range(T start, T stop, T step = 1) : it(start), stop(stop),\
    \ step(step), dir(step >= 0 ? 1 : -1) {}\n    Range(T stop) : it(0), stop(stop),\
    \ step(1), dir(1) {}\n    Range<T> begin() const { return *this; }\n    T end()\
    \ const { return stop; }\n    bool operator!=(const T val) const { return (val\
    \ - it) * dir > 0; }\n    void operator++() { it += step; }\n    const T& operator*()\
    \ const { return it; }\n\n   private:\n    T it;\n    const T stop, step;\n  \
    \  const int dir;\n\n    friend Range reversed(const Range& r) {\n        auto\
    \ new_start = (r.stop - r.dir - r.it) / r.step * r.step + r.it;\n        return\
    \ {new_start, r.it - r.dir, -r.step};\n    }\n};\ntemplate <class T>\nRange<T>\
    \ irange(T stop) {\n    return Range(stop);\n}\ntemplate <class T>\nRange<T> irange(T\
    \ start, T stop, T step = 1) {\n    return Range(start, stop, step);\n}\n}  //\
    \ namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/range.hpp
  requiredBy: []
  timestamp: '2022-02-26 15:56:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/osa_k.test.cpp
  - test/math/combination.test.cpp
  - test/utility/range.test.cpp
  - test/data/binary_indexed_tree.test.cpp
  - test/data/sparse_table.test.cpp
  - test/data/segment_tree.test.cpp
  - test/data/union_find.test.cpp
  - test/graphv2/bfs_grid.test.cpp
  - test/graphv2/warshallfloyd.test.cpp
  - test/graph/warshallfloyd.test.cpp
  - test/graph/bellman_ford.test.cpp
documentation_of: utility/range.hpp
layout: document
redirect_from:
- /library/utility/range.hpp
- /library/utility/range.hpp.html
title: "Python\u306Erange"
---
