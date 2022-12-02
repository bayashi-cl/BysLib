---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':heavy_check_mark:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/dp/lcs.hpp
    title: byslib/dp/lcs.hpp
  - icon: ':heavy_check_mark:'
    path: byslib/template.hpp
    title: byslib/template.hpp
  - icon: ':warning:'
    path: template.cpp
    title: template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_A.test.cpp
    title: test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_B.test.cpp
    title: test/AOJ/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_C.test.cpp
    title: test/AOJ/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_A.test.cpp
    title: test/AOJ/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_B.test.cpp
    title: test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_D.test.cpp
    title: test/AOJ/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_A.test.cpp
    title: test/AOJ/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_B.test.cpp
    title: test/AOJ/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_A.test.cpp
    title: test/AOJ/DSL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_5_B.test.cpp
    title: test/AOJ/DSL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/test.test.cpp
    title: test/test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Python::enumerate
    links:
    - https://docs.python.org/ja/3/library/functions.html#enumerate
  bundledCode: "#include <tuple>\n#include <cstdint>\nnamespace bys {\nusing i8 =\
    \ std::int8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64\
    \ = std::int64_t;\nusing i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing\
    \ u128 = __uint128_t;\nusing f32 = float;\nusing f64 = double;\nusing f128 = long\
    \ double;\n\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define\
    \ DEFINE_NUM_LITERAL(name, type) \\\n    constexpr auto operator\"\" name(unsigned\
    \ long long x) { return static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\n\
    DEFINE_NUM_LITERAL(_i16, std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\n\
    DEFINE_NUM_LITERAL(_i64, std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\n\
    DEFINE_NUM_LITERAL(_u8, std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\n\
    DEFINE_NUM_LITERAL(_u32, std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\n\
    DEFINE_NUM_LITERAL(_u128, __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n\
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n#include <cstddef>\n#include <iterator>\n\
    #include <vector>\n\n#include <array>\n#include <iostream>\n#include <type_traits>\n\
    /**\n * @file traits.hpp\n * @brief Types\n *\n * type_traits\u62E1\u5F35\n */\n\
    namespace bys {\ntemplate <class, class = void> struct has_rshift_from_istream\
    \ : std::false_type {};\ntemplate <class T>\nstruct has_rshift_from_istream<T,\
    \ std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_rshift_from_istream_v\
    \ = has_rshift_from_istream<T>::value;\n\ntemplate <class, class = void> struct\
    \ has_lshift_to_ostream : std::false_type {};\ntemplate <class T>\nstruct has_lshift_to_ostream<T,\
    \ std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>\
    \ : std::true_type {};\ntemplate <class T> constexpr bool has_lshft_to_ostream_v\
    \ = has_lshift_to_ostream<T>::value;\n\ntemplate <class, class = void> struct\
    \ is_tuple_like : std::false_type {};\ntemplate <class T> struct is_tuple_like<T,\
    \ std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};\ntemplate\
    \ <class T> constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\n\ntemplate\
    \ <class, class = void> struct is_iterable : std::false_type {};\ntemplate <class\
    \ T> struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>\
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
    \nnamespace bys {\ntemplate <class Iterator> class SubRange {\n  public:\n   \
    \ using iterator = Iterator;\n    using reverse_iterator = std::reverse_iterator<iterator>;\n\
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
    \ start), iterator_t(std::cend(iterable), end));\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <tuple>\n#include \"../core/int_alias.hpp\"\n#include\
    \ \"subrange.hpp\"\n/**\n * @file enumerate.hpp\n * @brief Python::enumerate\n\
    \ *\n * Python\u518D\u73FE\u30B7\u30EA\u30FC\u30BA enumerate\u7DE8\n * See: https://docs.python.org/ja/3/library/functions.html#enumerate\n\
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
    \ start), iterator_t(std::cend(iterable), end));\n}\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  - byslib/extension/subrange.hpp
  - byslib/core/traits.hpp
  isVerificationFile: false
  path: byslib/extension/enumerate.hpp
  requiredBy:
  - template.cpp
  - byslib/template.hpp
  - byslib/dp/lcs.hpp
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_5_B.test.cpp
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/GRL_1_A.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/CGL_2_B.test.cpp
  - test/AOJ/CGL_2_A.test.cpp
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_1_C.test.cpp
  - test/AOJ/CGL_1_B.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/DSL_5_A.test.cpp
  - test/AOJ/CGL_2_D.test.cpp
  - test/AOJ/DSL_1_A.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/CGL_3_A.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/CGL_1_A.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/CGL_3_B.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
  - test/test.test.cpp
  - test/yosupo/staticrmq.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/unionfind.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: byslib/extension/enumerate.hpp
layout: document
redirect_from:
- /library/byslib/extension/enumerate.hpp
- /library/byslib/extension/enumerate.hpp.html
title: Python::enumerate
---
