---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':warning:'
    path: byslib/algorithm/compress.hpp
    title: Coordinate Compression
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':x:'
    path: byslib/ds/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <algorithm>\n#include <vector>\n\n#include <cassert>\n#include\
    \ <iterator>\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
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
    }  // namespace bys\n/**\n * @file compress.hpp\n * @brief Coordinate Compression\n\
    \ *\n * \u5EA7\u6A19\u5727\u7E2E\n */\nnamespace bys {\n/**\n * @brief \u5EA7\u6A19\
    \u5727\u7E2E\n */\ntemplate <class T> class Compress {\n    std::vector<T> cp;\n\
    \    Compress(std::vector<T> const& v) : cp(v) {\n        sort(std::begin(cp),\
    \ std::end(cp));\n        cp.erase(std::unique(std::begin(cp), std::end(cp)),\
    \ cp.end());\n    }\n    //! @brief \u5727\u7E2E\u3055\u308C\u305F\u5024\u3092\
    \u53D6\u5F97 O(log N)\n    i32 get(T v) const {\n        auto itr = std::lower_bound(std::begin(cp),\
    \ std::end(cp), v);\n        assert(*itr == v);\n        return std::distance(cp.begin(),\
    \ itr);\n    }\n\n    //! @brief \u89E3\u51CD\u3055\u308C\u305F\u5024\u3092\u53D6\
    \u5F97 O(1)\n    T unzip(i32 i) const { return cp[i]; }\n    std::size_t size()\
    \ const { return cp.size(); }\n    std::ptrdiff_t ssize() const { return cp.size();\
    \ }\n};\n}  // namespace bys\n\n#include <array>\n#include <optional>\n#include\
    \ <utility>\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\u30CE\
    \u30A4\u30C9\n */\nnamespace bys {\nstruct Magma {\n    using set_type = std::nullptr_t;\n\
    \    static constexpr set_type operation(set_type, set_type);\n    static constexpr\
    \ set_type inverse(set_type);\n    static constexpr set_type identity{nullptr};\n\
    \    static constexpr bool commutative{false};\n};\ntemplate <class T> struct\
    \ Add : Magma {\n    using set_type = T;\n    static constexpr set_type operation(set_type\
    \ a, set_type b) { return a + b; }\n    static constexpr set_type inverse(set_type\
    \ a) { return -a; }\n    static constexpr set_type identity{0};\n    static constexpr\
    \ bool commutative{true};\n};\ntemplate <class T> struct Min : Magma {\n    using\
    \ set_type = T;\n    static constexpr set_type operation(set_type a, set_type\
    \ b) { return std::min(a, b); }\n    static constexpr set_type identity{std::numeric_limits<set_type>::max()};\n\
    };\ntemplate <class T> struct Max : Magma {\n    using set_type = T;\n    static\
    \ constexpr set_type operation(set_type a, set_type b) { return std::max(a, b);\
    \ }\n    static constexpr set_type identity{std::numeric_limits<set_type>::min()};\n\
    };\ntemplate <class T> struct Update : Magma {\n    using set_type = std::optional<T>;\n\
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
    \    }();\n};\n}  // namespace bys\n#include <string>\n/**\n * @file bit.hpp\n\
    \ * @brief Bit\n * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n\
    \ */\nnamespace bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x)\
    \ <= bit_width(x)\n */\ntemplate <class T> constexpr i32 bit_width(T x) {\n  \
    \  i32 bits = 0;\n    x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>=\
    \ 1;\n    return bits;\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\n\
    template <class T> constexpr T bit_floor(T x) {\n    assert(x >= 0);\n    return\
    \ x == 0 ? 0 : T(1) << (bit_width(x) - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\
    \u4E0A\u3052\ntemplate <class T> constexpr T bit_ceil(T x) {\n    assert(x >=\
    \ 0);\n    return x == 0 ? 1 : T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\
    \u6587\u5B57\u5217\u306B\u5909\u63DB\ntemplate <class T> std::string bin(T n)\
    \ {\n    assert(n >= 0);\n    if (n == 0) return \"0\";\n    std::string res;\n\
    \    while (n > 0) {\n        res.push_back(n & 1 ? '1' : '0');\n        n >>=\
    \ 1;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n//!\
    \ @brief d bit\u76EE\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B\ntemplate <class\
    \ T> constexpr bool pop(T s, i32 d) { return s & (T(1) << d); }\n}  // namespace\
    \ bys\n/**\n * @file binary_indexed_tree.hpp\n * @brief Binary Indexed Tree\n\
    \ */\nnamespace bys {\n/**\n * @brief Binary Indexed Tree\n *\n * \u4E00\u70B9\
    \u66F4\u65B0: O(logN)\n * \u533A\u9593\u548C: O(logN)\n * See: https://algo-logic.info/binary-indexed-tree/\n\
    \ */\ntemplate <class Abelian> struct BinaryIndexedTree {\n    using T = typename\
    \ Abelian::set_type;\n    static_assert(Abelian::commutative);\n    const i32\
    \ _n;\n    std::vector<T> data;\n\n    BinaryIndexedTree(i32 n) : _n(n), data(_n\
    \ + 1, Abelian::identity) {}\n    BinaryIndexedTree(const std::vector<T>& val)\
    \ : _n(val.size()), data(_n + 1, Abelian::identity) {\n        std::copy(val.begin(),\
    \ val.end(), data.begin() + 1);\n        for (i32 i = 1; i <= _n; i++) {\n   \
    \         if (i32 j = i + (i & -i); j <= _n) data[j] = Abelian::operation(data[j],\
    \ data[i]);\n        }\n    }\n\n    void point_append(i32 i, T val) {\n     \
    \   assert(0 <= i && i < _n);\n        for (++i; i <= _n; i += i & -i) data[i]\
    \ = Abelian::operation(data[i], val);\n    }\n\n    void set(i32 i, T val) {\n\
    \        assert(0 <= i and i < _n);\n        point_append(i, Abelian::operation(Abelian::inverse(fold(i,\
    \ i + 1)), val));\n    }\n    T operator[](std::size_t i) const { return fold(i,\
    \ i + 1); }\n\n    T prefix_fold(i32 right) const {\n        assert(0 <= right\
    \ and right <= _n);\n        T res = Abelian::identity;\n        for (; right\
    \ > 0; right -= right & -right) res = Abelian::operation(res, data[right]);\n\
    \        return res;\n    }\n    T fold(i32 left, i32 right) const {\n       \
    \ if (left < right) {\n            return Abelian::operation(Abelian::inverse(prefix_fold(left)),\
    \ prefix_fold(right));\n        } else {\n            return Abelian::identity;\n\
    \        }\n    }\n};\n\ntemplate <class T> struct BinaryIndexedTree<Add<T>> {\n\
    \    const i32 _n;\n    std::vector<T> data;\n\n    BinaryIndexedTree(i32 n) :\
    \ _n(n), data(_n + 1) {}\n    BinaryIndexedTree(const std::vector<T>& val) : _n(val.size()),\
    \ data(_n + 1) {\n        std::copy(val.begin(), val.end(), data.begin() + 1);\n\
    \        for (i32 i = 1; i <= _n; i++) {\n            if (i32 j = i + (i & -i);\
    \ j <= _n) data[j] += data[i];\n        }\n    }\n\n    void point_append(i32\
    \ i, T val) {\n        assert(0 <= i && i < _n);\n        for (++i; i <= _n; i\
    \ += i & -i) data[i] += val;\n    }\n\n    void set(i32 i, T val) {\n        assert(0\
    \ <= i and i < _n);\n        point_append(i, val - fold(i, i + 1));\n    }\n \
    \   T operator[](std::size_t i) const { return fold(i, i + 1); }\n\n    T prefix_fold(i32\
    \ right) const {\n        assert(0 <= right and right <= _n);\n        T res =\
    \ 0;\n        for (; right > 0; right -= right & -right) res += data[right];\n\
    \        return res;\n    }\n    T fold(i32 left, i32 right) const { return left\
    \ < right ? prefix_fold(right) - prefix_fold(left) : 0; }\n\n    //! @brief sum[0,\
    \ r) >= x\u3068\u306A\u308B\u6700\u5C0F\u306Er\u3092\u6C42\u3081\u308B\n    i32\
    \ bisect(T x) const {\n        if (x <= 0) return 0;\n        if (x > prefix_fold(_n))\
    \ return -1;\n        i32 res = 0;\n        for (i32 w = bit_floor(_n); w > 0;\
    \ w >>= 1) {\n            if (res + w < _n && data[res + w] < x) {\n         \
    \       x -= data[res + w];\n                res += w;\n            }\n      \
    \  }\n        return res + 1;\n    }\n};\n\ntemplate <class T> using FenwickTree\
    \ = BinaryIndexedTree<Add<T>>;\ntemplate <class T> BinaryIndexedTree<Add<T>> fenwick_tree(const\
    \ std::vector<T>& val) { return BinaryIndexedTree<Add<T>>(val); }\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T> i64 inversion(const std::vector<T>&\
    \ v) {\n    Compress<T> cp(v);\n    std::vector<i32> cp_v;\n    cp_v.reserve(v.size());\n\
    \    std::transform(v.begin(), v.end(), std::back_inserter(cp_v), [&](const T&\
    \ e) { return cp.get(e); });\n    auto sz = cp.size();\n    FenwickTree<i32> bit(sz);\n\
    \    i64 res = 0;\n    for (auto e : cp_v) {\n        bit.point_append(e, 1);\n\
    \        res += bit.fold(e + 1, sz);\n    }\n    return res;\n}\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n#include \"../algorithm/compress.hpp\"\
    \n#include \"../core/int_alias.hpp\"\n#include \"../ds/binary_indexed_tree.hpp\"\
    \n\nnamespace bys {\ntemplate <class T> i64 inversion(const std::vector<T>& v)\
    \ {\n    Compress<T> cp(v);\n    std::vector<i32> cp_v;\n    cp_v.reserve(v.size());\n\
    \    std::transform(v.begin(), v.end(), std::back_inserter(cp_v), [&](const T&\
    \ e) { return cp.get(e); });\n    auto sz = cp.size();\n    FenwickTree<i32> bit(sz);\n\
    \    i64 res = 0;\n    for (auto e : cp_v) {\n        bit.point_append(e, 1);\n\
    \        res += bit.fold(e + 1, sz);\n    }\n    return res;\n}\n}  // namespace\
    \ bys\n"
  dependsOn:
  - byslib/algorithm/compress.hpp
  - byslib/core/int_alias.hpp
  - byslib/ds/binary_indexed_tree.hpp
  - byslib/algebra/monoid.hpp
  - byslib/ntheory/bit.hpp
  isVerificationFile: false
  path: byslib/algorithm/inversion.hpp
  requiredBy: []
  timestamp: '2022-12-02 16:15:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/algorithm/inversion.hpp
layout: document
redirect_from:
- /library/byslib/algorithm/inversion.hpp
- /library/byslib/algorithm/inversion.hpp.html
title: byslib/algorithm/inversion.hpp
---
