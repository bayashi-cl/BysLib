#pragma once
#include "stdlib.hpp"
#include "types.hpp"

namespace bys {
struct Scanner {
    Scanner(std::istream& is_) : is(is_){};

    template <class... Ts>
    void scan(Ts&... args) {
        (is >> ... >> args);
    }

    template <class T, class... Us>
    decltype(auto) read() {
        if constexpr (sizeof...(Us) == 0) {
            if constexpr (has_rshift_from_istream<T>::value) {
                T res;
                is >> res;
                return res;
            } else if constexpr (has_tuple_interface<T>::value) {
                auto res = read_tuple<T>(std::make_index_sequence<std::tuple_size_v<T>>());
                return res;
            } else if constexpr (std::is_same_v<T, Int1>) {
                int res;
                is >> res;
                --res;
                return res;
            } else if constexpr (has_iterator<T>::value) {
                //! TODO: 一行読んでsplit
                static_assert([] { return false; }(), "NotImplementedError");
            } else {
                static_assert([] { return false; }(), "TypeError");
            }
        } else {
            return std::tuple{read<T>(), read<Us>()...};
        }
    }

    template <class T, std::size_t N, typename R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>
    std::array<R, N> read() {
        std::array<R, N> res;
        for (auto&& e : res) e = read<T>();
        return res;
    }

    template <class T, typename R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>
    vector<R> readvec(int n) {
        vector<R> res(n);
        for (auto&& e : res) e = read<T>();
        return res;
    }
    template <class T, typename R = std::conditional_t<std::is_same_v<T, Int1>, int, T>>
    vector<vector<R>> readvec(int n, int m) {
        vector<vector<R>> res(n);
        for (auto&& e : res) e = readvec<T>(m);
        return res;
    }

    template <class Lambda = std::function<int(std::string)>,
              typename T = std::invoke_result_t<std::decay_t<Lambda>, std::string>>
    std::vector<T> readln(
        Lambda f = [](string x) { return std::stoi(x); }, char sep = ' ') {
        std::ws(is);
        std::string elem;
        std::getline(is, elem);
        std::stringstream ss{elem};
        std::vector<T> res;
        while (std::getline(ss, elem, sep)) res.emplace_back(f(elem));
        return res;
    }

   private:
    std::istream& is;
    template <class Tp, std::size_t... I>
    inline decltype(auto) read_tuple(std::index_sequence<I...>) {
        return Tp{read<typename std::tuple_element_t<I, Tp>>()...};
    }
};
}  // namespace bys
