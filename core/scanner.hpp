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
                T res;
                std::apply([&](auto&... e) { (is >> ... >> e); }, res);
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

    template <class T, std::size_t N>
    std::array<T, N> read() {
        std::array<T, N> res;
        for (auto&& e : res) e = read<T>();
        return res;
    }

    template <class T>
    vector<T> readvec(int n) {
        vector<T> res(n);
        for (auto&& e : res) e = read<T>();
        return res;
    }
    template <class T>
    vector<vector<T>> readvec(int n, int m) {
        vector<vector<T>> res(n);
        for (auto&& e : res) e = readvec<T>(m);
        return res;
    }

   private:
    std::istream& is;
};
}  // namespace bys
