---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/mapping.hpp
    title: Mapping
  - icon: ':question:'
    path: algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: math/bit.hpp
    title: Bit
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RAQ.test.cpp
    title: test/data/dual_segment_tree_RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data/dual_segment_tree_RUQ.test.cpp
    title: test/data/dual_segment_tree_RUQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dual Segment Tree
    links:
    - https://kmyk.github.io/blog/blog/2019/02/22/dual-segment-tree/
  bundledCode: "#include <optional>\n#include <utility>\n/**\n * @file monoid.hpp\n\
    \ * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace bys {\ntemplate\
    \ <class T>\nstruct Magma {\n    using set_type = T;\n    static constexpr set_type\
    \ operation(set_type a, set_type b);\n    static constexpr bool commutative{false};\n\
    };\ntemplate <class T>\nstruct Add : Magma<T> {\n    using typename Magma<T>::set_type;\n\
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
    \ identity{1, 0};\n};\n}  // namespace bys\n/**\n * @file mapping.hpp\n * @brief\
    \ Mapping\n *\n * \u9045\u5EF6\u30BB\u30B0\u6728 \u4F5C\u7528\u7D20\n */\nnamespace\
    \ bys {\ntemplate <class T, class ActMonoid>\nstruct MappingToSet {\n    static\
    \ constexpr void mapping(T&, typename ActMonoid::set_type) {\n        static_assert([]\
    \ { return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S>\nstruct MappingToSet<T, Add<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class\
    \ T, class S>\nstruct MappingToSet<T, Update<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Update<S>::set_type u) {\n        if (u.has_value())\
    \ t = u.value();\n    }\n};\ntemplate <class Monoid, class ActMonoid>\nstruct\
    \ Mapping {\n    static constexpr void mapping(typename Monoid::set_type&, typename\
    \ ActMonoid::set_type, int) {\n        static_assert([] { return false; }(), \"\
    mapping function does not defined.\");\n    }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Min<T>::set_type& t, typename Update<S>::set_type s, int) {\n        if (s.has_value())\
    \ t = s.value();\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t, typename\
    \ Add<S>::set_type s, int w) { t += s * w; }\n};\ntemplate <class T, class S>\n\
    struct Mapping<Min<T>, Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type&\
    \ t, typename Add<S>::set_type s, int) { t += s; }\n};\ntemplate <class T, class\
    \ S>\nstruct Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename\
    \ Add<T>::set_type& t, typename Update<S>::set_type s, int w) {\n        if (s.has_value())\
    \ t = s.value() * w;\n    }\n};\ntemplate <class T, class S>\nstruct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, int w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S>\nstruct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, int) {\n        if (s.has_value()) t = s.value();\n    }\n};\n}  // namespace\
    \ bys\n/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\
    \u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n\
    \ * bit_width(x) - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T>\nconstexpr\
    \ int bit_width(T x) {\n    int bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for\
    \ (; x != 0; bits++) x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\
    \u308A\u4E0B\u3052\ntemplate <class T>\nconstexpr T bit_floor(T x) {\n    assert(x\
    \ >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\
    \u306B\u5207\u308A\u4E0A\u3052\ntemplate <class T>\nconstexpr T bit_ceil(T x)\
    \ {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n\
    }\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T>\n\
    std::string bin(T n) {\n    assert(n > 0);\n    if (n == 0) return \"0\";\n  \
    \  std::string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1' :\
    \ '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\ntemplate <class T>\nconstexpr bool pop(T s, int d) {\n    return s & (T(1)\
    \ << d);\n}\n}  // namespace bys\n/**\n * @file dual_segment_tree.hpp\n * @brief\
    \ Dual Segment Tree\n *\n * \u53CC\u5BFE\u30BB\u30B0\u6728\n */\nnamespace bys\
    \ {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u533A\
    \u9593\u66F4\u65B0: O(logN)\n * \u4E00\u70B9\u53D6\u5F97: O(logN)\n * See: https://kmyk.github.io/blog/blog/2019/02/22/dual-segment-tree/\n\
    \ *\n * @tparam T \u8981\u7D20\u578B\n * @tparam ActMonoid \u4F5C\u7528\u7D20\u30E2\
    \u30CE\u30A4\u30C9\n * @tparam Action T\u306B\u5BFE\u3059\u308B\u4F5C\u7528\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n */\ntemplate <class T, class ActMonoid,\
    \ class Action = MappingToSet<T, ActMonoid>>\nclass DualSegmentTree {\n    int\
    \ _n, n_leaf, logsize;\n    std::vector<typename ActMonoid::set_type> lazy;\n\
    \    std::vector<T> data;\n\n    void push(int p) {\n        for (int i = logsize;\
    \ i > 0; --i) {\n            int a = p >> i;\n            if (lazy[a] == ActMonoid::identity)\
    \ continue;\n            if (a * 2 < n_leaf) {\n                lazy[a * 2] =\
    \ ActMonoid::operation(lazy[a * 2], lazy[a]);\n                lazy[a * 2 + 1]\
    \ = ActMonoid::operation(lazy[a * 2 + 1], lazy[a]);\n            } else {\n  \
    \              int t = a * 2 - n_leaf;\n                Action::mapping(data[t],\
    \ lazy[a]);\n                Action::mapping(data[t + 1], lazy[a]);\n        \
    \    }\n            lazy[a] = ActMonoid::identity;\n        }\n    }\n\n   public:\n\
    \    DualSegmentTree(int n, T ident)\n        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n\
    \ - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf, ident) {}\n    DualSegmentTree(const\
    \ std::vector<T>& v)\n        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n\
    \ - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf) {\n        std::copy(v.begin(),\
    \ v.end(), data.begin());\n    }\n\n    T operator[](int i) const {\n        T\
    \ res = data[i];\n        for (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {\n    \
    \        Action::mapping(res, lazy[i]);\n        }\n        return res;\n    }\n\
    \    void update(int i, T val) {\n        if constexpr (!ActMonoid::commutative)\
    \ {\n            push(i + n_leaf);\n        }\n        data[i] = val;\n    }\n\
    \    void apply(int l, int r, T val) {\n        assert(l < r);\n        l += n_leaf;\n\
    \        r += n_leaf;\n        if constexpr (!ActMonoid::commutative) {\n    \
    \        push(l);\n            push(r - 1);\n        }\n        if (l & 1) Action::mapping(data[l++\
    \ - n_leaf], val);\n        if (r & 1) Action::mapping(data[--r - n_leaf], val);\n\
    \        for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                lazy[l] = ActMonoid::operation(lazy[l], val);\n    \
    \            ++l;\n            }\n            if (r & 1) {\n                --r;\n\
    \                lazy[r] = ActMonoid::operation(lazy[r], val);\n            }\n\
    \        }\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../algebra/mapping.hpp\"\n#include \"../core/stdlib.hpp\"\
    \n#include \"../math/bit.hpp\"\n/**\n * @file dual_segment_tree.hpp\n * @brief\
    \ Dual Segment Tree\n *\n * \u53CC\u5BFE\u30BB\u30B0\u6728\n */\nnamespace bys\
    \ {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u533A\
    \u9593\u66F4\u65B0: O(logN)\n * \u4E00\u70B9\u53D6\u5F97: O(logN)\n * See: https://kmyk.github.io/blog/blog/2019/02/22/dual-segment-tree/\n\
    \ *\n * @tparam T \u8981\u7D20\u578B\n * @tparam ActMonoid \u4F5C\u7528\u7D20\u30E2\
    \u30CE\u30A4\u30C9\n * @tparam Action T\u306B\u5BFE\u3059\u308B\u4F5C\u7528\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n */\ntemplate <class T, class ActMonoid,\
    \ class Action = MappingToSet<T, ActMonoid>>\nclass DualSegmentTree {\n    int\
    \ _n, n_leaf, logsize;\n    std::vector<typename ActMonoid::set_type> lazy;\n\
    \    std::vector<T> data;\n\n    void push(int p) {\n        for (int i = logsize;\
    \ i > 0; --i) {\n            int a = p >> i;\n            if (lazy[a] == ActMonoid::identity)\
    \ continue;\n            if (a * 2 < n_leaf) {\n                lazy[a * 2] =\
    \ ActMonoid::operation(lazy[a * 2], lazy[a]);\n                lazy[a * 2 + 1]\
    \ = ActMonoid::operation(lazy[a * 2 + 1], lazy[a]);\n            } else {\n  \
    \              int t = a * 2 - n_leaf;\n                Action::mapping(data[t],\
    \ lazy[a]);\n                Action::mapping(data[t + 1], lazy[a]);\n        \
    \    }\n            lazy[a] = ActMonoid::identity;\n        }\n    }\n\n   public:\n\
    \    DualSegmentTree(int n, T ident)\n        : _n(n), n_leaf(bit_ceil(_n)), logsize(bit_width(n\
    \ - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf, ident) {}\n    DualSegmentTree(const\
    \ std::vector<T>& v)\n        : _n(v.size()), n_leaf(bit_ceil(_n)), logsize(bit_width(_n\
    \ - 1)), lazy(n_leaf, ActMonoid::identity), data(n_leaf) {\n        std::copy(v.begin(),\
    \ v.end(), data.begin());\n    }\n\n    T operator[](int i) const {\n        T\
    \ res = data[i];\n        for (i = (i + n_leaf) >> 1; i > 0; i >>= 1) {\n    \
    \        Action::mapping(res, lazy[i]);\n        }\n        return res;\n    }\n\
    \    void update(int i, T val) {\n        if constexpr (!ActMonoid::commutative)\
    \ {\n            push(i + n_leaf);\n        }\n        data[i] = val;\n    }\n\
    \    void apply(int l, int r, T val) {\n        assert(l < r);\n        l += n_leaf;\n\
    \        r += n_leaf;\n        if constexpr (!ActMonoid::commutative) {\n    \
    \        push(l);\n            push(r - 1);\n        }\n        if (l & 1) Action::mapping(data[l++\
    \ - n_leaf], val);\n        if (r & 1) Action::mapping(data[--r - n_leaf], val);\n\
    \        for (l >>= 1, r >>= 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                lazy[l] = ActMonoid::operation(lazy[l], val);\n    \
    \            ++l;\n            }\n            if (r & 1) {\n                --r;\n\
    \                lazy[r] = ActMonoid::operation(lazy[r], val);\n            }\n\
    \        }\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - algebra/mapping.hpp
  - algebra/monoid.hpp
  - core/stdlib.hpp
  - math/bit.hpp
  isVerificationFile: false
  path: data/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data/dual_segment_tree_RAQ.test.cpp
  - test/data/dual_segment_tree_RUQ.test.cpp
documentation_of: data/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data/dual_segment_tree.hpp
- /library/data/dual_segment_tree.hpp.html
title: Dual Segment Tree
---
