---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  - icon: ':question:'
    path: byslib/core/traits.hpp
    title: Types
  - icon: ':question:'
    path: byslib/extension/subrange.hpp
    title: byslib/extension/subrange.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <cstddef>\n#include <iterator>\n#include <vector>\n\n#include\
    \ <array>\n#include <iostream>\n#include <type_traits>\n#include <cstdint>\nnamespace\
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
    #undef DEFINE_NUM_LITERAL\n}  // namespace bys\n/**\n * @file traits.hpp\n * @brief\
    \ Types\n *\n * type_traits\u62E1\u5F35\n */\nnamespace bys {\ntemplate <class,\
    \ class = void> struct has_rshift_from_istream : std::false_type {};\ntemplate\
    \ <class T>\nstruct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>()\
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
    \ std::rend(std::forward<Iterable>(iter)));\n}\n}  // namespace bys\nnamespace\
    \ bys {\ntemplate <class T> class SubsetIterator {\n    static_assert(std::is_integral_v<T>,\
    \ \"T is not integral.\");\n\n  public:\n    using difference_type = std::ptrdiff_t;\n\
    \    using value_type = T;\n    using reference = T;\n    using pointer = T*;\n\
    \    using iterator_category = std::forward_iterator_tag;\n\n    SubsetIterator(T\
    \ s) : _t(s), _s(s) {}\n\n    reference operator*() { return _t; }\n    const\
    \ reference operator*() const { return _t; }\n\n    SubsetIterator& operator++()\
    \ {\n        if (_t == 0) {\n            sentinel = true;\n        } else {\n\
    \            _t = (_t - 1) & _s;\n        }\n        return *this;\n    }\n  \
    \  SubsetIterator operator++(int) {\n        auto temp = *this;\n        ++*this;\n\
    \        return temp;\n    }\n\n    bool operator!=(const SubsetIterator& other)\
    \ const { return not sentinel; }\n    bool operator==(const SubsetIterator& other)\
    \ const { return not(*this != other); }\n\n  private:\n    T _t;\n    const T\
    \ _s;\n    bool sentinel = false;\n};\ntemplate <class T> SubRange<SubsetIterator<T>>\
    \ subset(T s) { return SubRange(SubsetIterator<T>(s), SubsetIterator<T>(s)); }\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include \"../extension/subrange.hpp\"\nnamespace bys {\ntemplate\
    \ <class T> class SubsetIterator {\n    static_assert(std::is_integral_v<T>, \"\
    T is not integral.\");\n\n  public:\n    using difference_type = std::ptrdiff_t;\n\
    \    using value_type = T;\n    using reference = T;\n    using pointer = T*;\n\
    \    using iterator_category = std::forward_iterator_tag;\n\n    SubsetIterator(T\
    \ s) : _t(s), _s(s) {}\n\n    reference operator*() { return _t; }\n    const\
    \ reference operator*() const { return _t; }\n\n    SubsetIterator& operator++()\
    \ {\n        if (_t == 0) {\n            sentinel = true;\n        } else {\n\
    \            _t = (_t - 1) & _s;\n        }\n        return *this;\n    }\n  \
    \  SubsetIterator operator++(int) {\n        auto temp = *this;\n        ++*this;\n\
    \        return temp;\n    }\n\n    bool operator!=(const SubsetIterator& other)\
    \ const { return not sentinel; }\n    bool operator==(const SubsetIterator& other)\
    \ const { return not(*this != other); }\n\n  private:\n    T _t;\n    const T\
    \ _s;\n    bool sentinel = false;\n};\ntemplate <class T> SubRange<SubsetIterator<T>>\
    \ subset(T s) { return SubRange(SubsetIterator<T>(s), SubsetIterator<T>(s)); }\n\
    }  // namespace bys\n"
  dependsOn:
  - byslib/extension/subrange.hpp
  - byslib/core/traits.hpp
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ntheory/subset.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/subset.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/subset.hpp
- /library/byslib/ntheory/subset.hpp.html
title: byslib/ntheory/subset.hpp
---
