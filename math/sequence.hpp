#pragma once
#include "../core/stdlib.hpp"
namespace bys {
template <class T>
struct Arithmetic {
    T a0, d;
    Arithmetic(T a0, T d) : a0(a0), d(d) {}
    T an(T n) { return a0 + d * n; }

    //! @brief Σ[0, n)
    T sn(T n) { return (a0 + an(n - 1)) * n / 2; }
    //! @brief Σ[l, r)
    T sn(T l, T r) { return sn(r) - sn(l); }
};
}  // namespace bys
