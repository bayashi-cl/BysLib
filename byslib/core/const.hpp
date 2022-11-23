#pragma once
#include <cstddef>
#include <limits>
#include <utility>

#include "alias.hpp"
#include "traits.hpp"

/**
 * @file const.hpp
 * @brief Const
 */
namespace bys {
constexpr i32 MOD = 998244353;
constexpr i32 MOD7 = 1000000007;

template <class T>
constexpr T get_inf();
namespace impl {
template <class Tp, std::size_t... I>
constexpr auto get_inf_tuple(std::index_sequence<I...>) {
    return Tp{get_inf<typename std::tuple_element_t<I, Tp>>()...};
}
}  // namespace impl
template <class T>
constexpr T get_inf() {
    if constexpr (std::is_integral_v<T>) {
        return std::numeric_limits<T>::max() / (T)2;
    } else if constexpr (std::is_floating_point_v<T>) {
        return std::numeric_limits<T>::infinity();
    } else if constexpr (is_tuple_like_v<T>) {
        return impl::get_inf_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());
    } else {
        static_assert([]() { return false; }, "Type Error");
    }
}
template <class T>
constexpr bool is_inf(T x) {
    return x == get_inf<T>();
}
constexpr auto INF = get_inf<i32>();
constexpr auto LINF = get_inf<i64>();
}  // namespace bys
