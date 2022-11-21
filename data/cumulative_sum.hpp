#pragma once
#include "../algebra/monoid.hpp"
#include "../core/stdlib.hpp"
/**
 * @file cumulative_sum.hpp
 * @brief Cumulative Sum
 *
 * 累積和
 */
namespace bys {
template <class Alg>
struct CumulativeSum {
    using T = typename Alg::set_type;
    std::vector<T> data;
    CumulativeSum(const vector<T>& value) {
        data.reserve(value.size() + 1);
        data.emplace_back(Alg::identity);
        std::partial_sum(value.begin(), value.end(), std::back_inserter(data), Alg::operation);
    }
    T prefix_fold(int right) { return data[right]; }
    T fold(int left, int right) { return left < right ? Alg::operation(Alg::inverse(data[left]), data[right]) : Alg::identity; }
};

template <class T>
struct CumulativeSum<Add<T>> {
    std::vector<T> data;
    CumulativeSum(const vector<T>& value) {
        data.reserve(value.size() + 1);
        data.emplace_back(0);
        std::partial_sum(value.begin(), value.end(), std::back_inserter(data));
    }
    T prefix_fold(int right) { return data[right]; }
    T fold(int left, int right) { return left < right ? data[right] - data[left] : T(0); }
};

template <class T>
CumulativeSum<Add<T>> cumsum(const std::vector<T>& val) {
    return CumulativeSum<Add<T>>(val);
}
}  // namespace bys
