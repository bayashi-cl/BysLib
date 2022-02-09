#pragma once
#include "../core/stdlib.hpp"

namespace bys {
//! @brief I番目の要素を比較
template <class T, std::size_t I>
struct ItemSorter {
    bool operator()(const T& lh, const T& rh) { return lh[I] < rh[I]; }
};
//! @brief Tuple系のI番目の要素を比較
template <class T, std::size_t I>
struct TupleSorter {
    bool operator()(const T& lh, const T& rh) { return std::get<I>(lh) < std::get<I>(rh); }
};
template <class T, class U>
struct SecondSorter {
    bool operator()(const std::pair<T, U>& lh, const std::pair<T, U>& rh) {
        return lh.second == rh.second ? lh.first < rh.first : lh.second < rh.second;
    }
};
#define SORTBY(method) [](const auto& a, const auto& b) { return a.method < b.method; }
}  // namespace bys
