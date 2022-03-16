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
    path: test/data/segment_tree.test.cpp
    title: test/data/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
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
    namespace bys {\ntemplate <class A>\nclass SegmentTree {\n    using T = typename\
    \ A::value_type;\n    int _n, n_leaf;\n    std::vector<T> data;\n\n   public:\n\
    \    SegmentTree(int n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, A::id)\
    \ {}\n    SegmentTree(const vector<T>& v) : _n(v.size()), n_leaf(bit_ceil(_n)),\
    \ data(n_leaf * 2, A::id) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) data[i] = A::op(data[i\
    \ * 2], data[i * 2 + 1]);\n    }\n\n    T query(int l, int r) const {\n      \
    \  assert(0 <= l && l < _n);\n        assert(l <= r);\n        assert(r <= _n);\n\
    \n        T left = A::id, right = A::id;\n        for (l += n_leaf, r += n_leaf;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = A::op(left, data[l++]);\n\
    \            if (r & 1) right = A::op(data[--r], right);\n        }\n        return\
    \ A::op(left, right);\n    }\n\n    T query_all() const { return data[1]; }\n\n\
    \    void update(int i, T val) {\n        assert(0 <= i && i < _n);\n        i\
    \ += n_leaf;\n        data[i] = val;\n        for (i >>= 1; i > 0; i >>= 1) data[i]\
    \ = A::op(data[i * 2], data[i * 2 + 1]);\n    }\n\n    T operator[](int i) const\
    \ {\n        assert(0 <= i && i < _n);\n        return data[i + n_leaf];\n   \
    \ }\n\n    // int bisect_from_left(int l, std::function<bool(S)> f) const {}\n\
    \    // int bisect_from_right(int r, std::function<bool(S)> f) const {}\n};\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n#include \"../math/bit.hpp\"\
    \nnamespace bys {\ntemplate <class A>\nclass SegmentTree {\n    using T = typename\
    \ A::value_type;\n    int _n, n_leaf;\n    std::vector<T> data;\n\n   public:\n\
    \    SegmentTree(int n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, A::id)\
    \ {}\n    SegmentTree(const vector<T>& v) : _n(v.size()), n_leaf(bit_ceil(_n)),\
    \ data(n_leaf * 2, A::id) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) data[i] = A::op(data[i\
    \ * 2], data[i * 2 + 1]);\n    }\n\n    T query(int l, int r) const {\n      \
    \  assert(0 <= l && l < _n);\n        assert(l <= r);\n        assert(r <= _n);\n\
    \n        T left = A::id, right = A::id;\n        for (l += n_leaf, r += n_leaf;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = A::op(left, data[l++]);\n\
    \            if (r & 1) right = A::op(data[--r], right);\n        }\n        return\
    \ A::op(left, right);\n    }\n\n    T query_all() const { return data[1]; }\n\n\
    \    void update(int i, T val) {\n        assert(0 <= i && i < _n);\n        i\
    \ += n_leaf;\n        data[i] = val;\n        for (i >>= 1; i > 0; i >>= 1) data[i]\
    \ = A::op(data[i * 2], data[i * 2 + 1]);\n    }\n\n    T operator[](int i) const\
    \ {\n        assert(0 <= i && i < _n);\n        return data[i + n_leaf];\n   \
    \ }\n\n    // int bisect_from_left(int l, std::function<bool(S)> f) const {}\n\
    \    // int bisect_from_right(int r, std::function<bool(S)> f) const {}\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: data/segment_tree.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/segment_tree.test.cpp
documentation_of: data/segment_tree.hpp
layout: document
redirect_from:
- /library/data/segment_tree.hpp
- /library/data/segment_tree.hpp.html
title: data/segment_tree.hpp
---
