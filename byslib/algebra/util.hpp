#pragma once
#include <cassert>
namespace bys {
template <class Monoid, class T>
typename Monoid::set_type pow_monoid(typename Monoid::set_type p, T q) {
    assert(q >= 0);
    auto res = Monoid::identity;
    while (q > 0) {
        if (q & 1) res = Monoid::operation(res, p);
        p = Monoid::operation(p, p);
        q >>= 1;
    }
    return res;
}
}  // namespace bys
