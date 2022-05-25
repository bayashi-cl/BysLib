#pragma once
#include "monoid.hpp"
/**
 * @file mapping.hpp
 * @brief Mapping
 *
 * 遅延セグ木 作用素
 */
namespace bys {
template <class T, class ActMonoid>
struct MappingToSet {
    static constexpr void mapping(T&, typename ActMonoid::set_type) {
        static_assert([] { return false; }(), "mapping function does not defined.");
    }
};
template <class T, class S>
struct MappingToSet<T, Add<S>> {
    static constexpr void mapping(T& t, typename Add<S>::set_type u) { t += u; }
};
template <class T, class S>
struct MappingToSet<T, Min<S>> {
    static constexpr void mapping(T& t, typename Min<S>::set_type u) {
        if (t > u) t = u;
    }
};
template <class T, class S>
struct MappingToSet<T, Update<S>> {
    static constexpr void mapping(T& t, typename Update<S>::set_type u) {
        if (u.has_value()) t = u.value();
    }
};
template <class Monoid, class ActMonoid>
struct Mapping {
    static constexpr void mapping(typename Monoid::set_type&, typename ActMonoid::set_type, int) {
        static_assert([] { return false; }(), "mapping function does not defined.");
    }
};
template <class T, class S>
struct Mapping<Min<T>, Update<S>> {
    static constexpr void mapping(typename Min<T>::set_type& t, typename Update<S>::set_type s, int) {
        if (s.has_value()) t = s.value();
    }
};
template <class T, class S>
struct Mapping<Add<T>, Add<S>> {
    static constexpr void mapping(typename Add<T>::set_type& t, typename Add<S>::set_type s, int w) { t += s * w; }
};
template <class T, class S>
struct Mapping<Min<T>, Add<S>> {
    static constexpr void mapping(typename Min<T>::set_type& t, typename Add<S>::set_type s, int) { t += s; }
};
template <class T, class S>
struct Mapping<Add<T>, Update<S>> {
    static constexpr void mapping(typename Add<T>::set_type& t, typename Update<S>::set_type s, int w) {
        if (s.has_value()) t = s.value() * w;
    }
};
template <class T, class S>
struct Mapping<Add<T>, Affine<S>> {
    static constexpr void mapping(typename Add<T>::set_type& t, typename Affine<S>::set_type s, int w) {
        t = t * s.first + w * s.second;
    }
};
template <class T, class S>
struct Mapping<Max<T>, Update<S>> {
    static constexpr void mapping(typename Max<T>::set_type& t, typename Update<S>::set_type s, int) {
        if (s.has_value()) t = s.value();
    }
};
}  // namespace bys
