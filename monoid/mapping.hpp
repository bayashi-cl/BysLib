#pragma once
#include "monoid.hpp"
namespace bys {
template <class T, class ActMonoid>
struct MappingToSet {};
template <class T, class S>
struct MappingToSet<T, Add<S>> {
    static constexpr void mapping(T& t, typename Add<S>::set_type u) { t += u; }
};
template <class T, class S>
struct MappingToSet<T, Update<S>> {
    static constexpr void mapping(T& t, typename Update<S>::set_type u) {
        if (u.has_value()) t = u.value();
    }
};
template <class Monoid, class ActMonoid>
struct Mapping {};
}  // namespace bys
