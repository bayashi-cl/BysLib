#pragma once
#include "../core/stdlib.hpp"

namespace bys {
//! @brief I番目の要素を比較
template <class T, std::size_t I>
struct ItemSorter {
    bool operator()(const T& lh, const T& rh) { return lh[I] < rh[I]; }
};
template <class T, class U>
struct SecondSorter {
    bool operator()(const pair<T, U>& lh, const pair<T, U>& rh) {
        return lh.second == rh.second ? lh.first < rh.first : lh.second < rh.second;
    }
};
}  // namespace bys
