#pragma once
#include <array>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include "../core/int_alias.hpp"
#include "../core/traits.hpp"
/**
 * @file scanner.hpp
 * @brief Input
 */
namespace bys {
class Scanner {
    std::istream& _is;
    template <class T, std::size_t... I> auto read_tuple(std::index_sequence<I...>) {
        return resolve_type_t<T>{read<typename std::tuple_element_t<I, T>>()...};
    }

  public:
    Scanner() = delete;
    Scanner(std::istream& is) : _is(is) { _is.tie(nullptr); }

    template <class T> auto read() {
        if constexpr (has_rshift_from_istream_v<T>) {
            T res;
            _is >> res;
            return res;
        } else if constexpr (is_tuple_like_v<T>) {
            return read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());
        } else if constexpr (is_indexed_v<T>) {
            typename T::resolve_to n;
            _is >> n;
            return --n;
        } else {
            static_assert([] { return false; }(), "TypeError");
        }
    }
    template <class... Ts, std::enable_if_t<(sizeof...(Ts) >= 2), std::nullptr_t> = nullptr>
    auto read() {
        return std::tuple{read<Ts>()...};
    }
    template <class T, std::size_t N> auto read() {
        std::array<resolve_type_t<T>, N> res;
        for (auto&& e : res) e = read<T>();
        return res;
    }
    template <class T> auto readvec(i32 n) {
        std::vector<resolve_type_t<T>> res(n);
        for (auto&& e : res) e = read<T>();
        return res;
    }
    template <class T> auto readvec(i32 n, i32 m) {
        std::vector<std::vector<resolve_type_t<T>>> res(n);
        for (auto&& e : res) e = readvec<T>(m);
        return res;
    }
};
}  // namespace bys
