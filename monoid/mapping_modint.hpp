#pragma once
#include "mapping.hpp"
#include "monoid_modint.hpp"
namespace bys {
template <class T, class S>
struct Mapping<AddModint<T>, AffineModint<S>> {
    static void mapping(typename AddModint<T>::set_type& t, typename AffineModint<S>::set_type s, int w) {
        t = t * s.first + w * s.second;
    }
};
}  // namespace bys
