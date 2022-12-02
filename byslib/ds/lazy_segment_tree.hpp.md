---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/algebra/mapping.hpp
    title: Mapping
  - icon: ':question:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Lazy Segment Tree
    links:
    - https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree
  bundledCode: "#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#include\
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
    \ bys\n#include <array>\n#include <optional>\n#include <utility>\n\n/**\n * @file\
    \ monoid.hpp\n * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\u30C9\n */\nnamespace\
    \ bys {\nstruct Magma {\n    using set_type = std::nullptr_t;\n    static constexpr\
    \ set_type operation(set_type, set_type);\n    static constexpr set_type inverse(set_type);\n\
    \    static constexpr set_type identity{nullptr};\n    static constexpr bool commutative{false};\n\
    };\ntemplate <class T> struct Add : Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return a + b; }\n   \
    \ static constexpr set_type inverse(set_type a) { return -a; }\n    static constexpr\
    \ set_type identity{0};\n    static constexpr bool commutative{true};\n};\ntemplate\
    \ <class T> struct Min : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return std::min(a, b); }\n    static\
    \ constexpr set_type identity{std::numeric_limits<set_type>::max()};\n};\ntemplate\
    \ <class T> struct Max : Magma {\n    using set_type = T;\n    static constexpr\
    \ set_type operation(set_type a, set_type b) { return std::max(a, b); }\n    static\
    \ constexpr set_type identity{std::numeric_limits<set_type>::min()};\n};\ntemplate\
    \ <class T> struct Update : Magma {\n    using set_type = std::optional<T>;\n\
    \    static constexpr set_type operation(set_type a, set_type b) { return b.has_value()\
    \ ? b : a; }\n    static constexpr set_type identity{std::nullopt};\n};\ntemplate\
    \ <class T> struct Affine : Magma {\n    using set_type = std::pair<T, T>;\n \
    \   static constexpr set_type operation(set_type a, set_type b) { return {a.first\
    \ * b.first, a.second * b.first + b.second}; }\n    static constexpr set_type\
    \ identity{1, 0};\n};\ntemplate <class Modint> struct ModMul : Magma {\n    using\
    \ set_type = Modint;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a * b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a.inv(); }\n    static constexpr set_type identity{1};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T> struct Xor : Magma {\n    using\
    \ set_type = T;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return a ^ b; }\n    static constexpr set_type inverse(set_type a) { return\
    \ a; }\n    static constexpr set_type identity{0};\n    static constexpr bool\
    \ commutative{true};\n};\ntemplate <std::size_t N> struct Perm : Magma {\n   \
    \ using set_type = std::array<i32, N>;\n    static constexpr set_type operation(const\
    \ set_type& a, const set_type& b) {\n        set_type res = {};\n        for (auto\
    \ i = 0UL; i < N; ++i) res[i] = b[a[i]];\n        return res;\n    }\n    static\
    \ constexpr set_type inverse(const set_type& a) {\n        set_type res = {};\n\
    \        for (auto i = 0UL; i < N; ++i) res[a[i]] = i;\n        return res;\n\
    \    }\n    static constexpr set_type identity = []() {\n        set_type res\
    \ = {};\n        for (auto i = 0UL; i < N; ++i) res[i] = i;\n        return res;\n\
    \    }();\n};\n}  // namespace bys\n/**\n * @file mapping.hpp\n * @brief Mapping\n\
    \ *\n * \u9045\u5EF6\u30BB\u30B0\u6728 \u4F5C\u7528\u7D20\n */\nnamespace bys\
    \ {\ntemplate <class T, class ActMonoid> struct MappingToSet {\n    static constexpr\
    \ void mapping(T&, typename ActMonoid::set_type) {\n        static_assert([] {\
    \ return false; }(), \"mapping function does not defined.\");\n    }\n};\ntemplate\
    \ <class T, class S> struct MappingToSet<T, Add<S>> {\n    static constexpr void\
    \ mapping(T& t, typename Add<S>::set_type u) { t += u; }\n};\ntemplate <class\
    \ T, class S> struct MappingToSet<T, Min<S>> {\n    static constexpr void mapping(T&\
    \ t, typename Min<S>::set_type u) {\n        if (t > u) t = u;\n    }\n};\ntemplate\
    \ <class T, class S> struct MappingToSet<T, Update<S>> {\n    static constexpr\
    \ void mapping(T& t, typename Update<S>::set_type u) {\n        if (u.has_value())\
    \ t = u.value();\n    }\n};\ntemplate <class Monoid, class ActMonoid> struct Mapping\
    \ {\n    static constexpr void mapping(typename Monoid::set_type&, typename ActMonoid::set_type,\
    \ i32) {\n        static_assert([] { return false; }(), \"mapping function does\
    \ not defined.\");\n    }\n};\ntemplate <class T, class S> struct Mapping<Min<T>,\
    \ Update<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t,\
    \ typename Update<S>::set_type s, i32) {\n        if (s.has_value()) t = s.value();\n\
    \    }\n};\ntemplate <class T, class S> struct Mapping<Add<T>, Add<S>> {\n   \
    \ static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type\
    \ s, i32 w) { t += s * w; }\n};\ntemplate <class T, class S> struct Mapping<Min<T>,\
    \ Add<S>> {\n    static constexpr void mapping(typename Min<T>::set_type& t, typename\
    \ Add<S>::set_type s, i32) { t += s; }\n};\ntemplate <class T, class S> struct\
    \ Mapping<Add<T>, Update<S>> {\n    static constexpr void mapping(typename Add<T>::set_type&\
    \ t, typename Update<S>::set_type s, i32 w) {\n        if (s.has_value()) t =\
    \ s.value() * w;\n    }\n};\ntemplate <class T, class S> struct Mapping<Add<T>,\
    \ Affine<S>> {\n    static constexpr void mapping(typename Add<T>::set_type& t,\
    \ typename Affine<S>::set_type s, i32 w) {\n        t = t * s.first + w * s.second;\n\
    \    }\n};\ntemplate <class T, class S> struct Mapping<Max<T>, Update<S>> {\n\
    \    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type\
    \ s, i32) {\n        if (s.has_value()) t = s.value();\n    }\n};\ntemplate <class\
    \ T, class Modint> struct Mapping<Add<T>, ModMul<Modint>> {\n    static constexpr\
    \ void mapping(typename Add<T>::set_type& t, typename ModMul<Modint>::set_type\
    \ s, i32) { t *= s; }\n};\n}  // namespace bys\n#include <string>\n/**\n * @file\
    \ bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\
    \u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) -\
    \ 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T> constexpr i32 bit_width(T\
    \ x) {\n    i32 bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++)\
    \ x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\
    \ntemplate <class T> constexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\ntemplate <class T> constexpr T bit_ceil(T x) {\n    assert(x >=\
    \ 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\
    \u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T> std::string bin(T n)\
    \ {\n    assert(n >= 0);\n    if (n == 0) return \"0\";\n    std::string res;\n\
    \    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//!\
    \ @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class\
    \ T> constexpr bool pop(T s, i32 d) { return s & (T(1) << d); }\n}  // namespace\
    \ bys\n/**\n * @file lazy_segment_tree.hpp\n * @brief Lazy Segment Tree\n */\n\
    namespace bys {\n/**\n * @brief \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n *\n * \u533A\u9593\u66F4\u65B0: O(logN)\n * \u533A\u9593\u30AF\u30A8\
    \u30EA: O(logN)\n * \u4E00\u70B9\u53D6\u5F97: O(logN)\n * See:\n * https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree\n\
    \ *\n * @tparam Monoid \u30E2\u30CE\u30A4\u30C9\n * @tparam ActMonoid \u4F5C\u7528\
    \u7D20\u30E2\u30CE\u30A4\u30C9\n * @tparam Action \u4F5C\u7528\u95A2\u6570\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8 \u533A\u9593\u306E\u5E45\u3082\u6E21\u3055\u308C\
    \u308B\n * @todo \u4E8C\u5206\u63A2\u7D22: O(logN)\n */\ntemplate <class Monoid,\
    \ class ActMonoid, class Action = Mapping<Monoid, ActMonoid>> class LazySegmentTree\
    \ {\n    using value_type = typename Monoid::set_type;\n    using act_type = typename\
    \ ActMonoid::set_type;\n    i32 _n, n_leaf, logsize;\n    std::vector<act_type>\
    \ lazy;\n    std::vector<value_type> data;\n\n    void reload(i32 p) { data[p]\
    \ = Monoid::operation(data[p * 2], data[p * 2 + 1]); }\n    void push(const i32\
    \ p) {\n        i32 w = n_leaf >> bit_width(p);\n        effect_segment(p * 2,\
    \ lazy[p], w);\n        effect_segment(p * 2 + 1, lazy[p], w);\n        lazy[p]\
    \ = ActMonoid::identity;\n    }\n    void effect_segment(const i32 p, act_type\
    \ f, i32 w) {\n        Action::mapping(data[p], f, w);\n        if (p < n_leaf)\
    \ lazy[p] = ActMonoid::operation(lazy[p], f);\n    }\n\n  public:\n    LazySegmentTree(i32\
    \ n)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {}\n    LazySegmentTree(i32 n, value_type init)\n   \
    \     : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::fill_n(data.begin() + n_leaf, _n, init);\n\
    \        for (i32 i = n_leaf - 1; i > 0; --i) {\n            data[i] = Monoid::operation(data[i\
    \ * 2], data[i * 2 + 1]);\n        }\n    }\n    LazySegmentTree(std::vector<value_type>\
    \ v)\n        : _n(v.size()),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (i32 i = n_leaf - 1; i > 0; --i) {\n            data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n        }\n    }\n    value_type\
    \ operator[](i32 p) {\n        assert(0 <= p && p < _n);\n        p += n_leaf;\n\
    \        for (i32 i = logsize; i > 0; --i) push(p >> i);\n        return data[p];\n\
    \    }\n    void update(i32 p, const value_type& x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += n_leaf;\n        for (i32 i = logsize; i > 0; --i) push(p\
    \ >> i);\n        data[p] = x;\n        for (i32 i = 1; i <= logsize; ++i) reload(p\
    \ >> i);\n    }\n    value_type fold(i32 l, i32 r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r <= _n);\n        if (l == r) return\
    \ Monoid::identity;\n\n        l += n_leaf;\n        r += n_leaf;\n\n        for\
    \ (i32 i = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        value_type left = Monoid::identity, right = Monoid::identity;\n    \
    \    for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left,\
    \ data[l++]);\n            if (r & 1) right = Monoid::operation(data[--r], right);\n\
    \        }\n        return Monoid::operation(left, right);\n    }\n\n    value_type\
    \ fold_all() { return data[1]; }\n    void effect(i32 i, act_type f) { effect(i,\
    \ i + 1, f); }\n\n    void effect(i32 l, i32 r, act_type f) {\n        assert(0\
    \ <= l);\n        assert(l <= r);\n        assert(r <= _n);\n        if (l ==\
    \ r) return;\n        l += n_leaf;\n        r += n_leaf;\n\n        for (i32 i\
    \ = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    i32 l2 = l, r2 = r;\n        i32 w = 1;\n        while (l2 < r2) {\n    \
    \        if (l2 & 1) effect_segment(l2++, f, w);\n            if (r2 & 1) effect_segment(--r2,\
    \ f, w);\n            l2 >>= 1;\n            r2 >>= 1;\n            w <<= 1;\n\
    \        }\n\n        for (i32 i = 1; i <= logsize; i++) {\n            if (((l\
    \ >> i) << i) != l) reload(l >> i);\n            if (((r >> i) << i) != r) reload((r\
    \ - 1) >> i);\n        }\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../algebra/mapping.hpp\"\n#include \"../core/int_alias.hpp\"\n#include\
    \ \"../ntheory/bit.hpp\"\n/**\n * @file lazy_segment_tree.hpp\n * @brief Lazy\
    \ Segment Tree\n */\nnamespace bys {\n/**\n * @brief \u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n *\n * \u533A\u9593\u66F4\u65B0: O(logN)\n * \u533A\
    \u9593\u30AF\u30A8\u30EA: O(logN)\n * \u4E00\u70B9\u53D6\u5F97: O(logN)\n * See:\n\
    \ * https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree\n\
    \ *\n * @tparam Monoid \u30E2\u30CE\u30A4\u30C9\n * @tparam ActMonoid \u4F5C\u7528\
    \u7D20\u30E2\u30CE\u30A4\u30C9\n * @tparam Action \u4F5C\u7528\u95A2\u6570\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8 \u533A\u9593\u306E\u5E45\u3082\u6E21\u3055\u308C\
    \u308B\n * @todo \u4E8C\u5206\u63A2\u7D22: O(logN)\n */\ntemplate <class Monoid,\
    \ class ActMonoid, class Action = Mapping<Monoid, ActMonoid>> class LazySegmentTree\
    \ {\n    using value_type = typename Monoid::set_type;\n    using act_type = typename\
    \ ActMonoid::set_type;\n    i32 _n, n_leaf, logsize;\n    std::vector<act_type>\
    \ lazy;\n    std::vector<value_type> data;\n\n    void reload(i32 p) { data[p]\
    \ = Monoid::operation(data[p * 2], data[p * 2 + 1]); }\n    void push(const i32\
    \ p) {\n        i32 w = n_leaf >> bit_width(p);\n        effect_segment(p * 2,\
    \ lazy[p], w);\n        effect_segment(p * 2 + 1, lazy[p], w);\n        lazy[p]\
    \ = ActMonoid::identity;\n    }\n    void effect_segment(const i32 p, act_type\
    \ f, i32 w) {\n        Action::mapping(data[p], f, w);\n        if (p < n_leaf)\
    \ lazy[p] = ActMonoid::operation(lazy[p], f);\n    }\n\n  public:\n    LazySegmentTree(i32\
    \ n)\n        : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {}\n    LazySegmentTree(i32 n, value_type init)\n   \
    \     : _n(n),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::fill_n(data.begin() + n_leaf, _n, init);\n\
    \        for (i32 i = n_leaf - 1; i > 0; --i) {\n            data[i] = Monoid::operation(data[i\
    \ * 2], data[i * 2 + 1]);\n        }\n    }\n    LazySegmentTree(std::vector<value_type>\
    \ v)\n        : _n(v.size()),\n          n_leaf(bit_ceil(_n)),\n          logsize(bit_width(_n\
    \ - 1)),\n          lazy(n_leaf, ActMonoid::identity),\n          data(n_leaf\
    \ * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + n_leaf);\n        for (i32 i = n_leaf - 1; i > 0; --i) {\n            data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n        }\n    }\n    value_type\
    \ operator[](i32 p) {\n        assert(0 <= p && p < _n);\n        p += n_leaf;\n\
    \        for (i32 i = logsize; i > 0; --i) push(p >> i);\n        return data[p];\n\
    \    }\n    void update(i32 p, const value_type& x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p += n_leaf;\n        for (i32 i = logsize; i > 0; --i) push(p\
    \ >> i);\n        data[p] = x;\n        for (i32 i = 1; i <= logsize; ++i) reload(p\
    \ >> i);\n    }\n    value_type fold(i32 l, i32 r) {\n        assert(0 <= l);\n\
    \        assert(l <= r);\n        assert(r <= _n);\n        if (l == r) return\
    \ Monoid::identity;\n\n        l += n_leaf;\n        r += n_leaf;\n\n        for\
    \ (i32 i = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        value_type left = Monoid::identity, right = Monoid::identity;\n    \
    \    for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left,\
    \ data[l++]);\n            if (r & 1) right = Monoid::operation(data[--r], right);\n\
    \        }\n        return Monoid::operation(left, right);\n    }\n\n    value_type\
    \ fold_all() { return data[1]; }\n    void effect(i32 i, act_type f) { effect(i,\
    \ i + 1, f); }\n\n    void effect(i32 l, i32 r, act_type f) {\n        assert(0\
    \ <= l);\n        assert(l <= r);\n        assert(r <= _n);\n        if (l ==\
    \ r) return;\n        l += n_leaf;\n        r += n_leaf;\n\n        for (i32 i\
    \ = logsize; i > 0; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    i32 l2 = l, r2 = r;\n        i32 w = 1;\n        while (l2 < r2) {\n    \
    \        if (l2 & 1) effect_segment(l2++, f, w);\n            if (r2 & 1) effect_segment(--r2,\
    \ f, w);\n            l2 >>= 1;\n            r2 >>= 1;\n            w <<= 1;\n\
    \        }\n\n        for (i32 i = 1; i <= logsize; i++) {\n            if (((l\
    \ >> i) << i) != l) reload(l >> i);\n            if (((r >> i) << i) != r) reload((r\
    \ - 1) >> i);\n        }\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/algebra/mapping.hpp
  - byslib/core/int_alias.hpp
  - byslib/algebra/monoid.hpp
  - byslib/ntheory/bit.hpp
  isVerificationFile: false
  path: byslib/ds/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:14:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/ds/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/byslib/ds/lazy_segment_tree.hpp
- /library/byslib/ds/lazy_segment_tree.hpp.html
title: Lazy Segment Tree
---
