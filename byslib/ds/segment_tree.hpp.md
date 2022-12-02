---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#include <cassert>\n#include <vector>\n\n#include <cstdint>\nnamespace\
    \ bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\n\
    using i64 = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    using u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128\
    \ = long double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    \n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n#include <algorithm>\n#include\
    \ <string>\n/**\n * @file bit.hpp\n * @brief Bit\n * @note c++20\u3067<bit>\u304C\
    \u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace bys {\n/**\n * @brief bit\u5E45\
    \n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n */\ntemplate <class T>\
    \ constexpr i32 bit_width(T x) {\n    i32 bits = 0;\n    x = (x < 0) ? (-x) :\
    \ x;\n    for (; x != 0; bits++) x >>= 1;\n    return bits;\n}\n//! @brief 2\u51AA\
    \u306B\u5207\u308A\u4E0B\u3052\ntemplate <class T> constexpr T bit_floor(T x)\
    \ {\n    assert(x >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n\
    }\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\u3052\ntemplate <class T> constexpr\
    \ T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 : T(1) << bit_width(x\
    \ - 1);\n}\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class\
    \ T> std::string bin(T n) {\n    assert(n >= 0);\n    if (n == 0) return \"0\"\
    ;\n    std::string res;\n    while (n > 0) {\n        res.push_back(n & 1 ? '1'\
    \ : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n//! @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\ntemplate <class T> constexpr bool pop(T s, i32 d) { return s & (T(1) <<\
    \ d); }\n}  // namespace bys\n/**\n * @file segment_tree.hpp\n * @brief Segment\
    \ Tree\n */\nnamespace bys {\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n *\n * \u4E00\u70B9\u66F4\u65B0: O(logN)\n * \u533A\u9593\u53D6\u5F97: O(logN)\n\
    \ *\n * @tparam Monoid \u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class Monoid>\
    \ class SegmentTree {\n    using value_type = typename Monoid::set_type;\n   \
    \ i32 _n, n_leaf;\n    std::vector<value_type> data;\n\n  public:\n    SegmentTree(i32\
    \ n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, Monoid::identity) {}\n   \
    \ SegmentTree(const std::vector<value_type>& v) : _n(v.size()), n_leaf(bit_ceil(_n)),\
    \ data(n_leaf * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(),\
    \ data.begin() + n_leaf);\n        for (i32 i = n_leaf - 1; i > 0; --i) data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n    }\n\n    value_type\
    \ fold(i32 l, i32 r) const {\n        assert(0 <= l && l <= _n);\n        assert(l\
    \ <= r);\n        assert(r <= _n);\n\n        value_type left = Monoid::identity,\
    \ right = Monoid::identity;\n        for (l += n_leaf, r += n_leaf; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left, data[l++]);\n\
    \            if (r & 1) right = Monoid::operation(data[--r], right);\n       \
    \ }\n        return Monoid::operation(left, right);\n    }\n\n    value_type fold_all()\
    \ const { return data[1]; }\n\n    void update(i32 i, value_type val) {\n    \
    \    assert(0 <= i && i < _n);\n        i += n_leaf;\n        data[i] = val;\n\
    \        for (i >>= 1; i > 0; i >>= 1) data[i] = Monoid::operation(data[i * 2],\
    \ data[i * 2 + 1]);\n    }\n\n    value_type operator[](i32 i) const {\n     \
    \   assert(0 <= i && i < _n);\n        return data[i + n_leaf];\n    }\n\n   \
    \ // f(fold(l, r)) == true \u3068\u306A\u308B\u6700\u5927\u306Er\n    template\
    \ <class Lambda, class... Args> i32 bisect_from_left(i32 l, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= l && l < _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        l += n_leaf;\n        value_type sm = Monoid::identity;\n\
    \        do {\n            l /= l & -l;\n            if (!f(Monoid::operation(sm,\
    \ data[l]), args...)) {\n                while (l < n_leaf) {\n              \
    \      l *= 2;\n                    if (value_type op = Monoid::operation(sm,\
    \ data[l]); f(op, args...)) {\n                        sm = op;\n            \
    \            ++l;\n                    }\n                }\n                return\
    \ l - n_leaf;\n            }\n            sm = Monoid::operation(sm, data[l]);\n\
    \            ++l;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    // f(fold(l, r)) == true \u3068\u306A\u308B\u6700\u5C0F\u306El\n    template\
    \ <class Lambda, class... Args> i32 bisect_from_right(i32 r, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= r && r <= _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        if (r == 0) return 0;\n        r += n_leaf;\n        value_type\
    \ sm = Monoid::identity;\n        do {\n            --r;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!f(Monoid::operation(data[r], sm)))\
    \ {\n                while (r < n_leaf) {\n                    r = (2 * r + 1);\n\
    \                    if (value_type op = Monoid::operation(data[r], sm); f(op,\
    \ args...)) {\n                        sm = op;\n                        --r;\n\
    \                    }\n                }\n                return r + 1 - n_leaf;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"../core/int_alias.hpp\"\
    \n#include \"../ntheory/bit.hpp\"\n/**\n * @file segment_tree.hpp\n * @brief Segment\
    \ Tree\n */\nnamespace bys {\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n *\n * \u4E00\u70B9\u66F4\u65B0: O(logN)\n * \u533A\u9593\u53D6\u5F97: O(logN)\n\
    \ *\n * @tparam Monoid \u30E2\u30CE\u30A4\u30C9\n */\ntemplate <class Monoid>\
    \ class SegmentTree {\n    using value_type = typename Monoid::set_type;\n   \
    \ i32 _n, n_leaf;\n    std::vector<value_type> data;\n\n  public:\n    SegmentTree(i32\
    \ n) : _n(n), n_leaf(bit_ceil(n)), data(n_leaf * 2, Monoid::identity) {}\n   \
    \ SegmentTree(const std::vector<value_type>& v) : _n(v.size()), n_leaf(bit_ceil(_n)),\
    \ data(n_leaf * 2, Monoid::identity) {\n        std::copy(v.begin(), v.end(),\
    \ data.begin() + n_leaf);\n        for (i32 i = n_leaf - 1; i > 0; --i) data[i]\
    \ = Monoid::operation(data[i * 2], data[i * 2 + 1]);\n    }\n\n    value_type\
    \ fold(i32 l, i32 r) const {\n        assert(0 <= l && l <= _n);\n        assert(l\
    \ <= r);\n        assert(r <= _n);\n\n        value_type left = Monoid::identity,\
    \ right = Monoid::identity;\n        for (l += n_leaf, r += n_leaf; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) left = Monoid::operation(left, data[l++]);\n\
    \            if (r & 1) right = Monoid::operation(data[--r], right);\n       \
    \ }\n        return Monoid::operation(left, right);\n    }\n\n    value_type fold_all()\
    \ const { return data[1]; }\n\n    void update(i32 i, value_type val) {\n    \
    \    assert(0 <= i && i < _n);\n        i += n_leaf;\n        data[i] = val;\n\
    \        for (i >>= 1; i > 0; i >>= 1) data[i] = Monoid::operation(data[i * 2],\
    \ data[i * 2 + 1]);\n    }\n\n    value_type operator[](i32 i) const {\n     \
    \   assert(0 <= i && i < _n);\n        return data[i + n_leaf];\n    }\n\n   \
    \ // f(fold(l, r)) == true \u3068\u306A\u308B\u6700\u5927\u306Er\n    template\
    \ <class Lambda, class... Args> i32 bisect_from_left(i32 l, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= l && l < _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        l += n_leaf;\n        value_type sm = Monoid::identity;\n\
    \        do {\n            l /= l & -l;\n            if (!f(Monoid::operation(sm,\
    \ data[l]), args...)) {\n                while (l < n_leaf) {\n              \
    \      l *= 2;\n                    if (value_type op = Monoid::operation(sm,\
    \ data[l]); f(op, args...)) {\n                        sm = op;\n            \
    \            ++l;\n                    }\n                }\n                return\
    \ l - n_leaf;\n            }\n            sm = Monoid::operation(sm, data[l]);\n\
    \            ++l;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    // f(fold(l, r)) == true \u3068\u306A\u308B\u6700\u5C0F\u306El\n    template\
    \ <class Lambda, class... Args> i32 bisect_from_right(i32 r, Lambda f, Args...\
    \ args) const {\n        static_assert(std::is_same_v<std::invoke_result_t<Lambda,\
    \ value_type, Args...>, bool>,\n                      \"The function signature\
    \ is invalid.\");\n        assert(0 <= r && r <= _n);\n        assert(f(Monoid::identity,\
    \ args...));\n        if (r == 0) return 0;\n        r += n_leaf;\n        value_type\
    \ sm = Monoid::identity;\n        do {\n            --r;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!f(Monoid::operation(data[r], sm)))\
    \ {\n                while (r < n_leaf) {\n                    r = (2 * r + 1);\n\
    \                    if (value_type op = Monoid::operation(data[r], sm); f(op,\
    \ args...)) {\n                        sm = op;\n                        --r;\n\
    \                    }\n                }\n                return r + 1 - n_leaf;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/ntheory/bit.hpp
  isVerificationFile: false
  path: byslib/ds/segment_tree.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:14:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
documentation_of: byslib/ds/segment_tree.hpp
layout: document
redirect_from:
- /library/byslib/ds/segment_tree.hpp
- /library/byslib/ds/segment_tree.hpp.html
title: Segment Tree
---
