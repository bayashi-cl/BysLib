#pragma once
#include "stdlib.hpp"
/**
 * @file traits.hpp
 * @brief Types
 *
 * type_traits拡張
 */
namespace bys {
template <class, class = void>
struct has_rshift_from_istream : std::false_type {};
template <class T>
struct has_rshift_from_istream<T, std::void_t<decltype(std::declval<std::istream&>() >> std::declval<T&>())>>
    : std::true_type {};
template <class T>
constexpr bool has_rshift_from_istream_v = has_rshift_from_istream<T>::value;

template <class, class = void>
struct has_lshift_to_ostream : std::false_type {};
template <class T>
struct has_lshift_to_ostream<T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>>
    : std::true_type {};
template <class T>
constexpr bool has_lshft_to_ostream_v = has_lshift_to_ostream<T>::value;

template <class, class = void>
struct is_tuple_like : std::false_type {};
template <class T>
struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>())>> : std::true_type {};
template <class T>
constexpr bool is_tuple_like_v = is_tuple_like<T>::value;

template <class, class = void>
struct is_iterable : std::false_type {};
template <class T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>> : std::true_type {};
template <class T>
constexpr bool is_iterable_v = is_iterable<T>::value;

template <class T>
struct Indexed {
    static_assert(std::is_integral_v<T>);
    using resolve_to = T;
};
using int1 = Indexed<int>;
using ll1 = Indexed<long long int>;

template <class, class = void>
struct is_indexed : std::false_type {};
template <class T>
struct is_indexed<Indexed<T>> : std::true_type {};
template <class T>
constexpr bool is_indexed_v = is_indexed<T>::value;

template <class T, class = void>
struct resolve_type {
    using type = T;
};
template <class T>
struct resolve_type<T, std::void_t<typename T::resolve_to>> {
    using type = typename T::resolve_to;
};
template <class T, std::size_t N>
struct resolve_type<std::array<T, N>> {
    using type = std::array<typename resolve_type<T>::type, N>;
};
template <class T, class U>
struct resolve_type<std::pair<T, U>> {
    using type = std::pair<typename resolve_type<T>::type, typename resolve_type<U>::type>;
};
template <class... Args>
struct resolve_type<std::tuple<Args...>> {
    using type = std::tuple<typename resolve_type<Args>::type...>;
};
template <class T>
using resolve_type_t = typename resolve_type<T>::type;
}  // namespace bys
