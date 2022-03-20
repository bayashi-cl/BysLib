#pragma once
#include "../acl/acl.hpp"
#include "mapping.hpp"
namespace bys {
template <class T>
struct AddModint : Magma<T> {
    using typename Magma<T>::set_type;
    static constexpr set_type operation(set_type a, set_type b) { return a + b; }
    static inline const set_type identity = {0};
    static constexpr bool commutative{true};
};
template <class T>
struct AffineModint : Magma<T> {
    using set_type = std::pair<T, T>;
    static constexpr set_type operation(set_type a, set_type b) { return {a.first * b.first, a.second * b.first + b.second}; }
    static inline const set_type identity = {1, 0};
};
}  // namespace bys
