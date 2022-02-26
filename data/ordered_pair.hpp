#pragma once
#include "../core/stdlib.hpp"
namespace bys {
/**
 * @brief Orderd pair
 * @details first <= secondになるpair
 */
template <class T>
struct OrderedPair : std::pair<T, T> {
    OrderedPair(T a, T b) {
        if (a > b) std::swap(a, b);
        this->first = a;
        this->second = b;
    }
};
}  // namespace bys
