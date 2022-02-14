#pragma once
namespace bys {
template <class T>
struct Add {
    using value_type = T;
    static constexpr T op(T a, T b) { return a + b; }
    static constexpr T id{0};
};
template <class T>
struct Min {
    using value_type = T;
    static constexpr T op(T a, T b) { return std::min(a, b); }
    static constexpr T id{std::numeric_limits<T>::max()};
};
template <class T>
struct Max {
    using value_type = T;
    static constexpr T op(T a, T b) { return std::max(a, b); }
    static constexpr T id{std::numeric_limits<T>::min()};
};
}  // namespace bys
