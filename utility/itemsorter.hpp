#pragma once
#include "../core/stdlib.hpp"
/**
 * @file itemsorter.hpp
 * @brief ItemSorter
 *
 * sort関数の第三引数に渡すことで"vectorの2番目の要素でソート"、"pairのsecond
 * を基準としてソート"等の操作ができる。
 */
namespace bys {
//! @brief IterableのI番目の要素を比較
template <std::size_t I>
struct ItemSorter {
    template <class T>
    constexpr bool operator()(const T& lh, const T& rh) const {
        return lh[I] < rh[I];
    }
};

//! @brief Tuple-likeのI番目の要素を比較
template <std::size_t I>
struct TupleSorter {
    template <class T>
    bool operator()(const T& lh, const T& rh) {
        return std::get<I>(lh) < std::get<I>(rh);
    }
};

//! @brief std::pairをsecond -> firstの順で比較
struct SecondSorter {
    template <class T, class U>
    bool operator()(const std::pair<T, U>& lh, const std::pair<T, U>& rh) {
        return lh.second == rh.second ? lh.first < rh.first : lh.second < rh.second;
    }
};

/**
 * @def SORTBY(member)
 * classをメンバで比較
 */
#define SORTBY(member) [](const auto& a, const auto& b) { return a.member < b.member; }
}  // namespace bys
