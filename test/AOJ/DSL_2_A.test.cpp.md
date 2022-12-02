---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/algebra/monoid.hpp
    title: Monoid
  - icon: ':question:'
    path: byslib/core/constant.hpp
    title: Const
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':x:'
    path: byslib/ds/segment_tree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: byslib/extension/change.hpp
    title: chmin/chmax
  - icon: ':question:'
    path: byslib/extension/enumerate.hpp
    title: Python::enumerate
  - icon: ':question:'
    path: byslib/extension/irange.hpp
    title: Python::range
  - icon: ':question:'
    path: byslib/extension/macro.hpp
    title: Macro
  - icon: ':question:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  - icon: ':question:'
    path: byslib/io/io.hpp
    title: I/O
  - icon: ':question:'
    path: byslib/io/printer.hpp
    title: Output
  - icon: ':question:'
    path: byslib/io/scanner.hpp
    title: Input
  - icon: ':question:'
    path: byslib/ntheory/bit.hpp
    title: Bit
  - icon: ':question:'
    path: byslib/procon/solver.hpp
    title: Solver
  - icon: ':question:'
    path: byslib/procon/stdlib.hpp
    title: STL Template
  - icon: ':question:'
    path: byslib/template.hpp
    title: byslib/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <array>\n#include <optional>\n#include <utility>\n#include <cstdint>\n\
    namespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\nusing i32\
    \ = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\nusing\
    \ u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
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
    \ bys\n\n/**\n * @file monoid.hpp\n * @brief Monoid\n *\n * \u30E2\u30CE\u30A4\
    \u30C9\n */\nnamespace bys {\nstruct Magma {\n    using set_type = std::nullptr_t;\n\
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
    \    }();\n};\n}  // namespace bys\n#include <cassert>\n#include <vector>\n\n\
    #include <algorithm>\n#include <string>\n/**\n * @file bit.hpp\n * @brief Bit\n\
    \ * @note c++20\u3067<bit>\u304C\u8FFD\u52A0\u3055\u308C\u308B\n */\nnamespace\
    \ bys {\n/**\n * @brief bit\u5E45\n *\n * bit_width(x) - 1  < log2(x) <= bit_width(x)\n\
    \ */\ntemplate <class T> constexpr i32 bit_width(T x) {\n    i32 bits = 0;\n \
    \   x = (x < 0) ? (-x) : x;\n    for (; x != 0; bits++) x >>= 1;\n    return bits;\n\
    }\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0B\u3052\ntemplate <class T> constexpr\
    \ T bit_floor(T x) {\n    assert(x >= 0);\n    return x == 0 ? 0 : T(1) << (bit_width(x)\
    \ - 1);\n}\n//! @brief 2\u51AA\u306B\u5207\u308A\u4E0A\u3052\ntemplate <class\
    \ T> constexpr T bit_ceil(T x) {\n    assert(x >= 0);\n    return x == 0 ? 1 :\
    \ T(1) << bit_width(x - 1);\n}\n//! @brief 2\u9032\u6587\u5B57\u5217\u306B\u5909\
    \u63DB\ntemplate <class T> std::string bin(T n) {\n    assert(n >= 0);\n    if\
    \ (n == 0) return \"0\";\n    std::string res;\n    while (n > 0) {\n        res.push_back(n\
    \ & 1 ? '1' : '0');\n        n >>= 1;\n    }\n    std::reverse(res.begin(), res.end());\n\
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
    \ r);\n        return 0;\n    }\n};\n}  // namespace bys\n/**\n * @file template.hpp\n\
    \ * @author bayashi_cl\n *\n * C++ library for competitive programming by bayashi_cl\n\
    \ * Repository: https://github.com/bayashi-cl/byslib\n * Document  : https://bayashi-cl.github.io/byslib/\n\
    \ */\n#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <cstddef>\n#include <limits>\n\
    #include <tuple>\n\n#include <iostream>\n#include <type_traits>\n/**\n * @file\
    \ traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\nnamespace\
    \ bys {\ntemplate <class, class = void> struct has_rshift_from_istream : std::false_type\
    \ {};\ntemplate <class T>\nstruct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
    \ >> std::declval<T&>())>> : std::true_type {};\ntemplate <class T> constexpr\
    \ bool has_rshift_from_istream_v = has_rshift_from_istream<T>::value;\n\ntemplate\
    \ <class, class = void> struct has_lshift_to_ostream : std::false_type {};\ntemplate\
    \ <class T>\nstruct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>()\
    \ << std::declval<T&>())>> : std::true_type {};\ntemplate <class T> constexpr\
    \ bool has_lshft_to_ostream_v = has_lshift_to_ostream<T>::value;\n\ntemplate <class,\
    \ class = void> struct is_tuple_like : std::false_type {};\ntemplate <class T>\
    \ struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type\
    \ {};\ntemplate <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\
    \ntemplate <class, class = void> struct is_iterable : std::false_type {};\ntemplate\
    \ <class T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
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
    \n/**\n * @file constant.hpp\n * @brief Const\n */\nnamespace bys {\nconstexpr\
    \ i32 MOD7 = 1000000007;\nconstexpr i32 MOD9 = 998244353;\nconstexpr i32 MOD =\
    \ MOD9;\n\ntemplate <class T> constexpr T get_inf();\nnamespace impl {\ntemplate\
    \ <class Tp, std::size_t... I> constexpr auto get_inf_tuple(std::index_sequence<I...>)\
    \ {\n    return Tp{get_inf<typename std::tuple_element_t<I, Tp>>()...};\n}\n}\
    \  // namespace impl\ntemplate <class T> constexpr T get_inf() {\n    if constexpr\
    \ (std::is_integral_v<T>) {\n        return std::numeric_limits<T>::max() / (T)2;\n\
    \    } else if constexpr (std::is_floating_point_v<T>) {\n        return std::numeric_limits<T>::infinity();\n\
    \    } else if constexpr (is_tuple_like_v<T>) {\n        return impl::get_inf_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \    } else {\n        static_assert([]() { return false; }, \"Type Error\");\n\
    \    }\n}\ntemplate <class T> constexpr bool is_inf(T x) { return x == get_inf<T>();\
    \ }\nconstexpr auto INF = get_inf<i32>();\nconstexpr auto LINF = get_inf<i64>();\n\
    }  // namespace bys\n/**\n * @file change.hpp\n * @brief chmin/chmax\n */\nnamespace\
    \ bys {\n/**\n * @brief \u6700\u5927\u5024\u3067\u66F4\u65B0\n * @return true\
    \ \u66F4\u65B0\u3055\u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr\
    \ bool chmax(T& a, T const& b) { return a < b ? a = b, true : false; }\n/**\n\
    \ * @brief \u6700\u5C0F\u5024\u3067\u66F4\u65B0\n * @return true \u66F4\u65B0\u3055\
    \u308C\u305F\u3068\u304D\n */\ntemplate <class T> constexpr bool chmin(T& a, T\
    \ const& b) { return a > b ? a = b, true : false; }\n}  // namespace bys\n#include\
    \ <iterator>\n\n\nnamespace bys {\ntemplate <class Iterator> class SubRange {\n\
    \  public:\n    using iterator = Iterator;\n    using reverse_iterator = std::reverse_iterator<iterator>;\n\
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
    \ std::rend(std::forward<Iterable>(iter)));\n}\n}  // namespace bys\n/**\n * @file\
    \ enumerate.hpp\n * @brief Python::enumerate\n *\n * Python\u518D\u73FE\u30B7\u30EA\
    \u30FC\u30BA enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
    \ */\nnamespace bys {\ntemplate <class Iterator> struct EnumerateIterator {\n\
    \  public:\n    using difference_type = typename Iterator::difference_type;\n\
    \    using value_type = std::tuple<i32, typename Iterator::value_type>;\n    //\
    \ using pointer = value_type*;\n    using reference = value_type&;\n    using\
    \ iterator_category = std::forward_iterator_tag;\n\n    EnumerateIterator(const\
    \ Iterator& iterator, i32 idx) : index(idx), value(iterator) {}\n\n    auto& operator++()\
    \ {\n        ++value;\n        ++index;\n        return *this;\n    }\n    bool\
    \ operator!=(const EnumerateIterator& other) const { return value != other.value;\
    \ }\n    auto operator*() const { return std::tie(index, *value); }\n\n  private:\n\
    \    i32 index;\n    Iterator value;\n};\n\n/**\n * @brief enumerate\n *\n * @param\
    \ iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\n */\n\
    template <class Iterable> auto enumerate(Iterable& iterable, i32 start = 0) {\n\
    \    using iterator_t = EnumerateIterator<typename Iterable::iterator>;\n    i32\
    \ end = static_cast<i32>(iterable.size()) + start;\n    return SubRange(iterator_t(std::begin(iterable),\
    \ start), iterator_t(std::end(iterable), end));\n}\n/**\n * @brief const enumerate\n\
    \ *\n * @param iterable \u5BFE\u8C61\n * @param start index\u306E\u521D\u671F\u5024\
    \n */\ntemplate <class Iterable> auto cenumerate(Iterable& iterable, i32 start\
    \ = 0) {\n    using iterator_t = EnumerateIterator<typename Iterable::const_iterator>;\n\
    \    i32 end = static_cast<i32>(iterable.size()) + start;\n    return SubRange(iterator_t(std::cbegin(iterable),\
    \ start), iterator_t(std::cend(iterable), end));\n}\n}  // namespace bys\n/**\n\
    \ * @file irange.hpp\n * @brief Python::range\n *\n * Python\u518D\u73FE\u30B7\
    \u30EA\u30FC\u30BA range\u7DE8\n * See: https://docs.python.org/ja/3/library/stdtypes.html#range\n\
    \ */\nnamespace bys {\ntemplate <class T> class IntegerIncrementIterator {\n \
    \ public:\n    using difference_type = std::ptrdiff_t;\n    using value_type =\
    \ T;\n    using reference = T;\n    using pointer = T*;\n    using iterator_category\
    \ = std::bidirectional_iterator_tag;\n\n    explicit IntegerIncrementIterator(T\
    \ x) : value(x) {}\n\n    reference operator*() noexcept { return value; }\n \
    \   const reference operator*() const noexcept { return value; }\n\n    auto operator++()\
    \ noexcept {\n        ++value;\n        return *this;\n    }\n    auto operator++(int)\
    \ noexcept {\n        auto temp = *this;\n        ++*this;\n        return temp;\n\
    \    }\n    auto operator--() noexcept {\n        --value;\n        return *this;\n\
    \    }\n    auto operator--(int) {\n        auto temp = *this;\n        --*this;\n\
    \        return temp;\n    }\n\n    bool operator!=(IntegerIncrementIterator const&\
    \ other) const { return value != other.value; }\n    bool operator==(IntegerIncrementIterator\
    \ const& other) const { return value == other.value; }\n\n  private:\n    value_type\
    \ value;\n};\n\ntemplate <class T> class IntegerStepIterator {\n  public:\n  \
    \  using difference_type = std::ptrdiff_t;\n    using value_type = T;\n    using\
    \ reference = T;\n    using pointer = T*;\n    using iterator_category = std::bidirectional_iterator_tag;\n\
    \n    explicit IntegerStepIterator(T f, T x, T s) : start(f), value(x), step(s)\
    \ {}\n\n    reference operator*() noexcept { return start + value * step; }\n\
    \    const reference operator*() const noexcept { return start + value * step;\
    \ }\n\n    auto operator++() {\n        ++value;\n        return *this;\n    }\n\
    \    auto operator++(int) {\n        auto temp = *this;\n        ++*this;\n  \
    \      return temp;\n    }\n    auto operator--() {\n        --value;\n      \
    \  return *this;\n    }\n    auto operator--(int) {\n        auto temp = *this;\n\
    \        --*this;\n        return temp;\n    }\n\n    bool operator!=(IntegerStepIterator\
    \ const& other) const { return value != other.value; }\n    bool operator==(IntegerStepIterator\
    \ const& other) const { return value == other.value; }\n\n  private:\n    value_type\
    \ start, value, step;\n};\n\ntemplate <class T> SubRange<IntegerIncrementIterator<T>>\
    \ irange(T stop) {\n    static_assert(std::is_integral_v<T>, \"T is not integer.\"\
    );\n    using iterator_t = IntegerIncrementIterator<T>;\n    if (stop < static_cast<T>(0))\
    \ stop = static_cast<T>(0);\n    return SubRange(iterator_t(static_cast<T>(0)),\
    \ iterator_t(stop));\n}\ntemplate <class T> SubRange<IntegerIncrementIterator<T>>\
    \ irange(T start, T stop) {\n    static_assert(std::is_integral_v<T>, \"T is not\
    \ integer.\");\n    using iterator_t = IntegerIncrementIterator<T>;\n    if (stop\
    \ < start) stop = start;\n    return SubRange(iterator_t(start), iterator_t(stop));\n\
    }\ntemplate <class T> SubRange<IntegerStepIterator<T>> irange(T start, T stop,\
    \ T step) {\n    static_assert(std::is_integral_v<T>, \"T is not integer.\");\n\
    \    using iterator_t = IntegerStepIterator<T>;\n    assert(step != 0);\n    auto\
    \ w = step >= 0 ? stop - start : start - stop;\n    auto s = step >= 0 ? step\
    \ : -step;\n    if (w < 0) w = 0;\n    return SubRange(iterator_t(start, static_cast<T>(0),\
    \ step), iterator_t(start, (w + s - 1) / s, step));\n}\n}  // namespace bys\n\
    using std::literals::string_literals::operator\"\"s;\n/**\n * @file macro.hpp\n\
    \ * @brief Macro\n */\n// clang-format off\n#define CONCAT_IMPL(a, b) a##b\n#define\
    \ CONCAT(a, b) CONCAT_IMPL(a, b)\n//! @brief [[maybe_unused]]\u306A\u5909\u6570\
    \u3092\u751F\u6210\u3002\n#define UV [[maybe_unused]] auto CONCAT(unused_val_,\
    \ __LINE__)\n#define RE std::runtime_error(\"file: \"s + __FILE__ + \", line:\
    \ \"s + std::to_string(__LINE__) + \", func: \"s + __func__)\n#ifdef LOCAL\n#define\
    \ DEBUGBLOCK(block) block\n#else\n#define DEBUGBLOCK(block)\n#endif\n// clang-format\
    \ on\n#include <iomanip>\n\n/**\n * @file printer.hpp\n * @brief Output\n */\n\
    namespace bys {\nclass Printer {\n    std::ostream& _os;\n    // sep1 \"\\n\"\
    \       : iterable<iterable>\n    // sep2 \" \" or \"\\n\": iterable, args\n \
    \   // sep3 \" \"        : tuple_like\n    std::string sep1 = \"\\n\", sep2 =\
    \ \" \", sep3 = \" \", end = \"\\n\";\n\n    template <std::size_t I, class T>\
    \ void print_tuple_element(T&& elem) {\n        if constexpr (I != 0) cat(sep3);\n\
    \        cat(std::forward<T>(elem));\n    }\n    template <class Tp, std::size_t...\
    \ I> void print_tuple(Tp&& tp, std::index_sequence<I...>) {\n        (print_tuple_element<I>(std::forward<std::tuple_element_t<I,\
    \ std::decay_t<Tp>>>(std::get<I>(tp))), ...);\n    }\n\n  public:\n    Printer()\
    \ = delete;\n    Printer(std::ostream& os) : _os(os) { _os << std::fixed << std::setprecision(11)\
    \ << std::boolalpha; }\n    ~Printer() { _os << std::flush; }\n\n    template\
    \ <class T> void cat(T&& v) {\n        if constexpr (has_lshft_to_ostream_v<std::decay_t<T>>)\
    \ {\n            _os << v;\n        } else if constexpr (is_iterable_v<std::decay_t<T>>)\
    \ {\n            std::string sep;\n            if constexpr (is_iterable_v<typename\
    \ std::decay_t<T>::value_type>) {\n                sep = sep1;\n            }\
    \ else {\n                sep = sep2;\n            }\n            bool top = true;\n\
    \            for (auto&& vi : v) {\n                top ? (void)(top = false)\
    \ : cat(sep);\n                cat(vi);\n            }\n        } else if constexpr\
    \ (is_tuple_like_v<std::decay_t<T>>) {\n            print_tuple(std::forward<T>(v),\
    \ std::make_index_sequence<std::tuple_size_v<std::decay_t<T>>>());\n        }\
    \ else {\n            static_assert([] { return false; }(), \"type error\");\n\
    \        }\n    }\n\n    void print() { cat(end); }\n    template <class T> void\
    \ print(T&& v) {\n        cat(std::forward<T>(v));\n        cat(end);\n    }\n\
    \    template <class T, class... Ts> void print(T&& top, Ts&&... args) {\n   \
    \     cat(std::forward<T>(top));\n        cat(sep2);\n        print(std::forward<Ts>(args)...);\n\
    \    }\n    template <class... Ts> void operator()(Ts&&... args) { print(std::forward<Ts>(args)...);\
    \ }\n\n    void flush() { _os << std::flush; }\n    template <class... Ts> void\
    \ send(Ts&&... args) {\n        print(std::forward<Ts>(args)...);\n        flush();\n\
    \    }\n\n    Printer set_sep(const std::string& sep_1, const std::string& sep_2,\
    \ const std::string& sep_3) {\n        sep1 = sep_1;\n        sep2 = sep_2;\n\
    \        sep3 = sep_3;\n        return *this;\n    }\n    Printer set_sep(const\
    \ std::string& sep_2) {\n        sep2 = sep_2;\n        return *this;\n    }\n\
    \    Printer set_end(const std::string& _end) {\n        end = _end;\n       \
    \ return *this;\n    }\n};\n}  // namespace bys\n\n/**\n * @file scanner.hpp\n\
    \ * @brief Input\n */\nnamespace bys {\nclass Scanner {\n    std::istream& _is;\n\
    \    template <class T, std::size_t... I> auto read_tuple(std::index_sequence<I...>)\
    \ {\n        return resolve_type_t<T>{read<typename std::tuple_element_t<I, T>>()...};\n\
    \    }\n\n  public:\n    Scanner() = delete;\n    Scanner(std::istream& is) :\
    \ _is(is) { _is.tie(nullptr); }\n\n    template <class T> auto read() {\n    \
    \    if constexpr (has_rshift_from_istream_v<T>) {\n            T res;\n     \
    \       _is >> res;\n            return res;\n        } else if constexpr (is_tuple_like_v<T>)\
    \ {\n            return read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \        } else if constexpr (is_indexed_v<T>) {\n            typename T::resolve_to\
    \ n;\n            _is >> n;\n            return --n;\n        } else {\n     \
    \       static_assert([] { return false; }(), \"TypeError\");\n        }\n   \
    \ }\n    template <class... Ts, std::enable_if_t<(sizeof...(Ts) >= 2), std::nullptr_t>\
    \ = nullptr> auto read() {\n        return std::tuple{read<Ts>()...};\n    }\n\
    \    template <class T, std::size_t N> auto read() {\n        std::array<resolve_type_t<T>,\
    \ N> res;\n        for (auto&& e : res) e = read<T>();\n        return res;\n\
    \    }\n    template <class T> auto readvec(i32 n) {\n        std::vector<resolve_type_t<T>>\
    \ res(n);\n        for (auto&& e : res) e = read<T>();\n        return res;\n\
    \    }\n    template <class T> auto readvec(i32 n, i32 m) {\n        std::vector<std::vector<resolve_type_t<T>>>\
    \ res(n);\n        for (auto&& e : res) e = readvec<T>(m);\n        return res;\n\
    \    }\n};\n}  // namespace bys\n\n/**\n * @file io.hpp\n * @brief I/O\n */\n\
    namespace bys {\ntemplate <class... Args> std::string debugfmt(i32 line, Args&&...\
    \ args) {\n    std::stringstream ss;\n    Printer printer(ss);\n    ss << \"\U0001F4CC\
    \ line\" << std::setw(4) << line << \": \";\n    printer.set_sep(\"\\n       \
    \      \", \" \", \" \");\n    printer.print(std::forward<Args>(args)...);\n \
    \   return ss.str();\n}\n\nPrinter print(std::cout), debug(std::cerr);\nScanner\
    \ scanner(std::cin);\n\n#ifdef LOCAL\n//! @brief \u30C7\u30D0\u30C3\u30B0\u7528\
    \u51FA\u529B \u30B8\u30E3\u30C3\u30B8\u4E0A\u3067\u306F\u4F55\u3082\u3057\u306A\
    \u3044\u3002\n#define DEBUG(...)                                  \\\n    {  \
    \                                             \\\n        debug.cat(debugfmt(__LINE__,\
    \ __VA_ARGS__)); \\\n        debug.flush();                              \\\n\
    \    }\n#else\n#define DEBUG(...)\n#endif\n#define DEBUGCASE(casenum, ...) \\\n\
    \    if (TESTCASE == casenum) DEBUG(__VA_ARGS__)\n//! @brief print\u3057\u3066\
    return\u3059\u308B\u3002\n#define EXIT(...)           \\\n    {              \
    \         \\\n        print(__VA_ARGS__); \\\n        return;             \\\n\
    \    }\n}  // namespace bys\n\n#include <unistd.h>\n\n\n\n/**\n * @file solver.hpp\n\
    \ * @brief Solver\n */\nnamespace bys {\nstruct Solver {\n    static inline i32\
    \ TESTCASE = 1;\n    static void solve();\n    static i32 main(i32 t = 1) {\n\
    \        std::ios::sync_with_stdio(false);\n\n        for (; TESTCASE <= t; ++TESTCASE)\
    \ solve();\n#ifdef LOCAL\n        if (not std::cin.good()) std::cerr << \"\U0001F7E1\
    \ Input failed.\" << std::endl;\n        if (not isatty(STDIN_FILENO) and not\
    \ std::ws(std::cin).eof()) std::cerr << \"\U0001F7E1 Unused input.\" << std::endl;\n\
    #endif\n        return 0;\n    }\n};\n}  // namespace bys\n/**\n * @file stdlib.hpp\n\
    \ * @brief STL Template\n */\n#include <bitset>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <set>\n#include <stack>\n#include <unordered_map>\n#include <unordered_set>\n\
    \n\nnamespace bys {\nusing std::array, std::vector, std::string, std::set, std::map,\
    \ std::pair;\nusing std::cin, std::cout, std::endl;\nusing std::min, std::max,\
    \ std::sort, std::reverse, std::abs;\n\n// alias\nusing Pa = std::pair<i32, i32>;\n\
    using Pa64 = std::pair<i64, i64>;\ntemplate <class T> using uset = std::unordered_set<T>;\n\
    template <class S, class T> using umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys {\nvoid Solver::solve() {\n    auto [n, q] = scanner.read<int,\
    \ 2>();\n    SegmentTree<Min<int>> seg(n);\n    for (UV : irange(q)) {\n     \
    \   auto [t, x, y] = scanner.read<int, 3>();\n        if (t == 0) {\n        \
    \    seg.update(x, y);\n\n        } else {\n            print(seg.fold(x, y +\
    \ 1));\n        }\n    }\n}\n}  // namespace bys\n\nint main() { return bys::Solver::main(/*\
    \ bys::scanner.read<int>() */); }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../../byslib/algebra/monoid.hpp\"\n#include \"../../byslib/ds/segment_tree.hpp\"\
    \n#include \"../../byslib/template.hpp\"\n\nnamespace bys {\nvoid Solver::solve()\
    \ {\n    auto [n, q] = scanner.read<int, 2>();\n    SegmentTree<Min<int>> seg(n);\n\
    \    for (UV : irange(q)) {\n        auto [t, x, y] = scanner.read<int, 3>();\n\
    \        if (t == 0) {\n            seg.update(x, y);\n\n        } else {\n  \
    \          print(seg.fold(x, y + 1));\n        }\n    }\n}\n}  // namespace bys\n\
    \nint main() { return bys::Solver::main(/* bys::scanner.read<int>() */); }\n"
  dependsOn:
  - byslib/algebra/monoid.hpp
  - byslib/core/int_alias.hpp
  - byslib/ds/segment_tree.hpp
  - byslib/ntheory/bit.hpp
  - byslib/template.hpp
  - byslib/core/constant.hpp
  - byslib/core/traits.hpp
  - byslib/extension/change.hpp
  - byslib/extension/enumerate.hpp
  - byslib/extension/subrange.hpp
  - byslib/extension/irange.hpp
  - byslib/extension/macro.hpp
  - byslib/io/io.hpp
  - byslib/io/printer.hpp
  - byslib/io/scanner.hpp
  - byslib/procon/solver.hpp
  - byslib/procon/stdlib.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-02 16:49:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_A.test.cpp
- /verify/test/AOJ/DSL_2_A.test.cpp.html
title: test/AOJ/DSL_2_A.test.cpp
---
