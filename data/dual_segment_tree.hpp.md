---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: math/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree.test.cpp
    title: test/data/dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <vector>\n\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\n\
    namespace bys {\nusing std::array, std::vector, std::string, std::set, std::map,\
    \ std::pair;\nusing std::cin, std::cout, std::endl;\nusing std::min, std::max,\
    \ std::sort, std::reverse, std::abs, std::pow;\n\n// alias\nusing ll = long long\
    \ int;\nusing ld = long double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll,\
    \ ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\n\
    template <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T>\nint bit_width(T x) {\n    int bits\
    \ = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n   \
    \ return bits;\n}\ntemplate <class T>\nT bit_floor(T x) {\n    assert(x >= 0);\n\
    \    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\ntemplate <class T>\n\
    T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x\
    \ - 1);\n}\n\nstring bin(ll n) {\n    assert(n > 0);\n    if (n == 0) return \"\
    0\";\n    string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1'\
    \ : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\ninline bool pop(int s, int d) { return s & (1 << d); }\n\
    inline bool pop(ll s, int d) { return s & (1LL << d); }\n}  // namespace bys\n\
    namespace bys {\ntemplate <class T, class A>\nclass DualSegmentTree {\n    using\
    \ L = typename A::value_type;\n    int _n, n_leaf, logsize;\n    std::vector<L>\
    \ lazy;\n    std::vector<T> data;\n    void push(int p) {\n        for (int i\
    \ = logsize; i > 0; --i) {\n            int a = p >> i;\n            if (lazy[a]\
    \ == A::id) continue;\n            if (a * 2 < n_leaf) {\n                lazy[a\
    \ * 2] = A::composition(lazy[a], lazy[a * 2]);\n                lazy[a * 2 + 1]\
    \ = A::composition(lazy[a], lazy[a * 2 + 1]);\n\n            } else {\n      \
    \          int t = a * 2 - n_leaf;\n                data[t] = A::mapping(lazy[a],\
    \ data[t]);\n                data[t + 1] = A::mapping(lazy[a], data[t + 1]);\n\
    \            }\n            lazy[a] = A::id;\n        }\n    }\n\n   public:\n\
    \    DualSegmentTree(int n, T ident)\n        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n\
    \ - 1)), lazy(n_leaf, A::id), data(n_leaf, ident) {}\n    DualSegmentTree(const\
    \ std::vector<T>& v)\n        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n\
    \ - 1)), lazy(n_leaf, A::id), data(n_leaf) {\n        std::copy(v.begin(), v.end(),\
    \ data.begin());\n    }\n\n    T operator[](int i) const {\n        T res = data[i];\n\
    \        for (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {\n            res = A::mapping(lazy[i],\
    \ res);\n        }\n        return res;\n    }\n    void update(int i, T val)\
    \ {\n        push(i + n_leaf);\n        data[i] = val;\n    }\n    void apply(int\
    \ l, int r, T val) {\n        assert(l < r);\n        l += n_leaf;\n        r\
    \ += n_leaf;\n        push(l);\n        push(r - 1);\n        if (l & 1) data[l\
    \ - n_leaf] = A::mapping(val, data[l - n_leaf]), l++;\n        if (r & 1) --r,\
    \ data[r - n_leaf] = A::mapping(val, data[r - n_leaf]);\n        for (l >>= 1,\
    \ r >>= 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n            \
    \    lazy[l] = A::composition(val, lazy[l]);\n                ++l;\n         \
    \   }\n            if (r & 1) {\n                --r;\n                lazy[r]\
    \ = A::composition(val, lazy[r]);\n            }\n        }\n    }\n};\n}  //\
    \ namespace bys\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../math/bit.hpp\"\nnamespace\
    \ bys {\ntemplate <class T, class A>\nclass DualSegmentTree {\n    using L = typename\
    \ A::value_type;\n    int _n, n_leaf, logsize;\n    std::vector<L> lazy;\n   \
    \ std::vector<T> data;\n    void push(int p) {\n        for (int i = logsize;\
    \ i > 0; --i) {\n            int a = p >> i;\n            if (lazy[a] == A::id)\
    \ continue;\n            if (a * 2 < n_leaf) {\n                lazy[a * 2] =\
    \ A::composition(lazy[a], lazy[a * 2]);\n                lazy[a * 2 + 1] = A::composition(lazy[a],\
    \ lazy[a * 2 + 1]);\n\n            } else {\n                int t = a * 2 - n_leaf;\n\
    \                data[t] = A::mapping(lazy[a], data[t]);\n                data[t\
    \ + 1] = A::mapping(lazy[a], data[t + 1]);\n            }\n            lazy[a]\
    \ = A::id;\n        }\n    }\n\n   public:\n    DualSegmentTree(int n, T ident)\n\
    \        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n - 1)), lazy(n_leaf,\
    \ A::id), data(n_leaf, ident) {}\n    DualSegmentTree(const std::vector<T>& v)\n\
    \        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n - 1)), lazy(n_leaf,\
    \ A::id), data(n_leaf) {\n        std::copy(v.begin(), v.end(), data.begin());\n\
    \    }\n\n    T operator[](int i) const {\n        T res = data[i];\n        for\
    \ (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {\n            res = A::mapping(lazy[i],\
    \ res);\n        }\n        return res;\n    }\n    void update(int i, T val)\
    \ {\n        push(i + n_leaf);\n        data[i] = val;\n    }\n    void apply(int\
    \ l, int r, T val) {\n        assert(l < r);\n        l += n_leaf;\n        r\
    \ += n_leaf;\n        push(l);\n        push(r - 1);\n        if (l & 1) data[l\
    \ - n_leaf] = A::mapping(val, data[l - n_leaf]), l++;\n        if (r & 1) --r,\
    \ data[r - n_leaf] = A::mapping(val, data[r - n_leaf]);\n        for (l >>= 1,\
    \ r >>= 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n            \
    \    lazy[l] = A::composition(val, lazy[l]);\n                ++l;\n         \
    \   }\n            if (r & 1) {\n                --r;\n                lazy[r]\
    \ = A::composition(val, lazy[r]);\n            }\n        }\n    }\n};\n}  //\
    \ namespace bys\n"
  dependsOn:
  - math/bit.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: data/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-03-18 03:24:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/dual_segment_tree.test.cpp
documentation_of: data/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data/dual_segment_tree.hpp
- /library/data/dual_segment_tree.hpp.html
title: data/dual_segment_tree.hpp
---
