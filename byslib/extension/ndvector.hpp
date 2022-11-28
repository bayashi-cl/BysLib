#pragma once
#include <vector>

namespace bys {
namespace impl {
template <typename T, std::size_t N> struct NdVector {
    using type = std::vector<typename NdVector<T, N - 1>::type>;
};
template <typename T> struct NdVector<T, 1> { using type = std::vector<T>; };

template <typename T, std::size_t N>
auto ndvector(std::vector<size_t>& shape, T const& fill_value) {
    if constexpr (N == 1) {
        return std::vector(shape[0], fill_value);
    } else {
        std::size_t size = shape.back();
        shape.pop_back();
        return std::vector(size, ndvector<T, N - 1>(shape, fill_value));
    }
}
}  // namespace impl

template <class T, std::size_t N> using NdVector = typename impl::NdVector<T, N>::type;

/**
 * @brief n-dimentional vector
 *
 * @example auto v = ndvector({2, 3}, 4); // {{4, 4, 4}, {4, 4, 4}}
 */
template <class S, class T, std::size_t N>
auto ndvector(S const (&shape)[N], T const& fill_value = T()) {
    static_assert(N > 0);
    std::vector<std::size_t> shape_vec(std::crbegin(shape), std::crend(shape));
    return impl::ndvector<T, N>(shape_vec, fill_value);
}
}  // namespace bys
