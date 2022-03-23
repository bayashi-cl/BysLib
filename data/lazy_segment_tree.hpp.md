---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  - icon: ':heavy_check_mark:'
    path: math/bit.hpp
    title: math/bit.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/mapping.hpp
    title: monoid/mapping.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/monoid.hpp
    title: monoid/monoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#include <cassert>\n#include <vector>\n\n#ifndef LOCAL\n#define NDEBUG\n\
    #endif\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
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
    #include <optional>\n#include <utility>\nnamespace bys {\ntemplate <class T>\n\
    struct Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b);\n    static constexpr bool commutative{false};\n};\ntemplate\
    \ <class T>\nstruct Add : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return a +\
    \ b; }\n    static constexpr set_type identity{0};\n    static constexpr bool\
    \ commutative{true};\n};\ntemplate <class T>\nstruct Min : Magma<T> {\n    using\
    \ typename Magma<T>::set_type;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T>\nstruct Max : Magma<T> {\n    using typename Magma<T>::set_type;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return std::max(a,\
    \ b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T>\nstruct Update : Magma<T> {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T>\nstruct Affine : Magma<T> {\n    using set_type = std::pair<T, T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\n}  // namespace bys\nnamespace bys {\ntemplate <class T,\
    \ class ActMonoid>\nstruct MappingToSet {\n    static constexpr void mapping(T&,\
    \ typename ActMonoid::set_type) {\n        static_assert([] { return false; }(),\
    \ \"mapping function does not defined.\");\n    }\n};\ntemplate <class T, class\
    \ S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void mapping(T& t,\
    \ typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class T, class S>\n\
    struct MappingToSet<T, Update<S>> {\n    static constexpr void mapping(T& t, typename\
    \ Update<S>::set_type u) {\n        if (u.has_value()) t = u.value();\n    }\n\
    };\ntemplate <class Monoid, class ActMonoid>\nstruct Mapping {\n    static constexpr\
    \ void mapping(typename Monoid::set_type&, typename ActMonoid::set_type, int)\
    \ {\n        static_assert([] { return false; }(), \"mapping function does not\
    \ defined.\");\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Update<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t,\
    \ typename Update<S>::set_type s, int) {\n        if (s.has_value()) t = s.value();\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>, Add<S>> {\n  \
    \  static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type\
    \ s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\nstruct Mapping<Min<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t, typename\
    \ Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class S>\nstruct\
    \ Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename Add<T>::set_type&\
    \ t, typename Update<S>::set_type s, int w) {\n        if (s.has_value()) t =\
    \ s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, int) {\n        if (s.has_value()) t = s.value();\n    }\n};\n}  // namespace\
    \ bys\nnamespace bys {\ntemplate <class Monoid, class ActMonoid, class Action\
    \ = Mapping<Monoid, ActMonoid>>\nclass LazySegmentTree {\n    using value_type\
    \ = typename Monoid::set_type;\n    using act_type = typename ActMonoid::set_type;\n\
    \    int _n, n_leaf, logsize;\n    std::vector<act_type> lazy;\n    std::vector<value_type>\
    \ data;\n\n    void reload(int p) { data[p] = Monoid::operation(data[p * 2], data[p\
    \ * 2 + 1]); }\n    void push(const int p) {\n        int w = n_leaf >> bit_width(p);\n\
    \        apply_segment(p * 2, lazy[p], w);\n        apply_segment(p * 2 + 1, lazy[p],\
    \ w);\n        lazy[p] = ActMonoid::identity;\n    }\n    void apply_segment(const\
    \ int p, act_type f, int w) {\n        Action::mapping(data[p], f, w);\n     \
    \   if (p < n_leaf) lazy[p] = ActMonoid::operation(lazy[p], f);\n    }\n\n   public:\n\
    \    LazySegmentTree(int n)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n\
    \          logsize(bit_width(_n - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n\
    \          data(n_leaf * 2, Monoid::identity) {}\n    LazySegmentTree(int n, value_type\
    \ init)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::fill_n(data.begin() + n_leaf, _n, init);\n\
    \        for (int i = n_leaf - 1; i > 0; --i) {\n            data[i] = Monoid::operation(data[i\
    \ * 2], data[i * 2 + 1]);\n        }\n    }\n    LazySegmentTree(std::vector<value_type>\
    \ v)\n        : _n(v.size()),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) {\n            data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n        }\n    }\n    value_type\
    \ operator[](int p) {\n        assert(0 <= p && p < _n);\n        p += n_leaf;\n\
    \        for (int i = logsize; i > 0; --i) push(p >> i);\n        return data[p];\n\
    \    }\n    void update(int p, const value_type& x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += n_leaf;\n        for (int i = logsize; i > 0; --i) push(p\
    \ >> i);\n        data[p] = x;\n        for (int i = 1; i <= logsize; ++i) reload(p\
    \ >> i);\n    }\n    value_type query(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r <= _n);\n        if (l == r) return\
    \ Monoid::identity;\n\n        l += n_leaf;\n        r += n_leaf;\n\n        for\
    \ (int i = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        value_type left = Monoid::identity, right = Monoid::identity;\n    \
    \    for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left,\
    \ data[l++]);\n            if (r & 1) right = Monoid::operation(data[--r], right);\n\
    \        }\n        return Monoid::operation(left, right);\n    }\n\n    value_type\
    \ query_all() { return data[1]; }\n    void apply(int i, act_type f) { apply(i,\
    \ i + 1, f); }\n\n    void apply(int l, int r, act_type f) {\n        assert(0\
    \ <= l);\n        assert(l <= r);\n        assert(r <= _n);\n        if (l ==\
    \ r) return;\n        l += n_leaf;\n        r += n_leaf;\n\n        for (int i\
    \ = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    int l2 = l, r2 = r;\n        int w = 1;\n        while (l2 < r2) {\n    \
    \        if (l2 & 1) apply_segment(l2++, f, w);\n            if (r2 & 1) apply_segment(--r2,\
    \ f, w);\n            l2 >>= 1;\n            r2 >>= 1;\n            w <<= 1;\n\
    \        }\n\n        for (int i = 1; i <= logsize; i++) {\n            if (((l\
    \ >> i) << i) != l) reload(l >> i);\n            if (((r >> i) << i) != r) reload((r\
    \ - 1) >> i);\n        }\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"../math/bit.hpp\"\
    \n#include \"../monoid/mapping.hpp\"\nnamespace bys {\ntemplate <class Monoid,\
    \ class ActMonoid, class Action = Mapping<Monoid, ActMonoid>>\nclass LazySegmentTree\
    \ {\n    using value_type = typename Monoid::set_type;\n    using act_type = typename\
    \ ActMonoid::set_type;\n    int _n, n_leaf, logsize;\n    std::vector<act_type>\
    \ lazy;\n    std::vector<value_type> data;\n\n    void reload(int p) { data[p]\
    \ = Monoid::operation(data[p * 2], data[p * 2 + 1]); }\n    void push(const int\
    \ p) {\n        int w = n_leaf >> bit_width(p);\n        apply_segment(p * 2,\
    \ lazy[p], w);\n        apply_segment(p * 2 + 1, lazy[p], w);\n        lazy[p]\
    \ = ActMonoid::identity;\n    }\n    void apply_segment(const int p, act_type\
    \ f, int w) {\n        Action::mapping(data[p], f, w);\n        if (p < n_leaf)\
    \ lazy[p] = ActMonoid::operation(lazy[p], f);\n    }\n\n   public:\n    LazySegmentTree(int\
    \ n)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {}\n    LazySegmentTree(int n, value_type init)\n   \
    \     : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::fill_n(data.begin() + n_leaf, _n, init);\n\
    \        for (int i = n_leaf - 1; i > 0; --i) {\n            data[i] = Monoid::operation(data[i\
    \ * 2], data[i * 2 + 1]);\n        }\n    }\n    LazySegmentTree(std::vector<value_type>\
    \ v)\n        : _n(v.size()),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (int i = n_leaf - 1; i > 0; --i) {\n            data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n        }\n    }\n    value_type\
    \ operator[](int p) {\n        assert(0 <= p && p < _n);\n        p += n_leaf;\n\
    \        for (int i = logsize; i > 0; --i) push(p >> i);\n        return data[p];\n\
    \    }\n    void update(int p, const value_type& x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += n_leaf;\n        for (int i = logsize; i > 0; --i) push(p\
    \ >> i);\n        data[p] = x;\n        for (int i = 1; i <= logsize; ++i) reload(p\
    \ >> i);\n    }\n    value_type query(int l, int r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r <= _n);\n        if (l == r) return\
    \ Monoid::identity;\n\n        l += n_leaf;\n        r += n_leaf;\n\n        for\
    \ (int i = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        value_type left = Monoid::identity, right = Monoid::identity;\n    \
    \    for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left,\
    \ data[l++]);\n            if (r & 1) right = Monoid::operation(data[--r], right);\n\
    \        }\n        return Monoid::operation(left, right);\n    }\n\n    value_type\
    \ query_all() { return data[1]; }\n    void apply(int i, act_type f) { apply(i,\
    \ i + 1, f); }\n\n    void apply(int l, int r, act_type f) {\n        assert(0\
    \ <= l);\n        assert(l <= r);\n        assert(r <= _n);\n        if (l ==\
    \ r) return;\n        l += n_leaf;\n        r += n_leaf;\n\n        for (int i\
    \ = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    int l2 = l, r2 = r;\n        int w = 1;\n        while (l2 < r2) {\n    \
    \        if (l2 & 1) apply_segment(l2++, f, w);\n            if (r2 & 1) apply_segment(--r2,\
    \ f, w);\n            l2 >>= 1;\n            r2 >>= 1;\n            w <<= 1;\n\
    \        }\n\n        for (int i = 1; i <= logsize; i++) {\n            if (((l\
    \ >> i) << i) != l) reload(l >> i);\n            if (((r >> i) << i) != r) reload((r\
    \ - 1) >> i);\n        }\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - math/bit.hpp
  - core/stdlib.hpp
  - monoid/mapping.hpp
  - monoid/monoid.hpp
  isVerificationFile: false
  path: data/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-03-23 17:02:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/lazy_segment_tree_Range_Affine_Range_Sum.test.cpp
  - test/data/lazy_segment_tree_RMQ_RUQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RAQ.test.cpp
  - test/data/lazy_segment_tree_RSQ_RUQ.test.cpp
  - test/data/lazy_segment_tree_RMQ_RAQ.test.cpp
documentation_of: data/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/data/lazy_segment_tree.hpp
- /library/data/lazy_segment_tree.hpp.html
title: data/lazy_segment_tree.hpp
---
