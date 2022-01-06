#pragma once

namespace bys {
template <class T>
struct Monoid {
    virtual T e() = 0;
    virtual T op(T& a, T& b) = 0;
};

template <class T>
struct Add : Monoid<T> {
    T e() { return 0; };
    T op(T a, T b) { return a + b; }
};
}  // namespace bys
