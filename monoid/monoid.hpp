#pragma once
#include <optional>
#include <utility>
namespace bys {
template <class T>
struct Magma {
    using set_type = T;
    static constexpr set_type operation(set_type a, set_type b);
    static constexpr bool commutative{false};
};
template <class T>
struct Add : Magma<T> {
    using typename Magma<T>::set_type;
    static constexpr set_type operation(set_type a, set_type b) { return a + b; }
    static constexpr set_type identity{0};
    static constexpr bool commutative{true};
};
template <class T>
struct Min : Magma<T> {
    using typename Magma<T>::set_type;
    static constexpr set_type operation(set_type a, set_type b) { return std::min(a, b); }
    static constexpr set_type identity{std::numeric_limits<set_type>::max()};
};
template <class T>
struct Max : Magma<T> {
    using typename Magma<T>::set_type;
    static constexpr set_type operation(set_type a, set_type b) { return std::max(a, b); }
    static constexpr set_type identity{std::numeric_limits<set_type>::min()};
};
template <class T>
struct Update : Magma<T> {
    using set_type = std::optional<T>;
    static constexpr set_type operation(set_type a, set_type b) { return b.has_value() ? b : a; }
    static constexpr set_type identity{std::nullopt};
};
template <class T>
struct Affine : Magma<T> {
    using set_type = std::pair<T, T>;
    static constexpr set_type operation(set_type a, set_type b) { return {a.first * b.first, a.second * b.first + b.second}; }
    static constexpr set_type identity{1, 0};
};
}  // namespace bys
