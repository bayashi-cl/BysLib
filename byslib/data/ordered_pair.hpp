#pragma once
#include <utility>
/**
 * @file ordered_pair.hpp
 * @brief Orderd Pair
 */
namespace bys {
//! @brief first <= secondになるpair
template <class T> struct OrderedPair : std::pair<T, T> {
    OrderedPair(T a, T b) {
        if (a > b) std::swap(a, b);
        this->first = a;
        this->second = b;
    }
};
}  // namespace bys
