#pragma once

namespace bys {
//! @brief pythonのrangeと同じ挙動
template <typename T>
struct Range {
    Range(T start, T stop, T step = 1) : it(start), stop(stop), step(step), dir(step >= 0 ? 1 : -1) {}
    Range(T stop) : it(0), stop(stop), step(1), dir(1) {}
    Range<T> begin() const { return *this; }
    T end() const { return stop; }
    bool operator!=(const T val) const { return (val - it) * dir > 0; }
    void operator++() { it += step; }
    const T& operator*() const { return it; }

   private:
    T it;
    const T stop, step;
    const int dir;

    friend Range reversed(const Range& r) {
        auto new_start = (r.stop - r.dir - r.it) / r.step * r.step + r.it;
        return {new_start, r.it - r.dir, -r.step};
    }
};
template <class T>
Range<T> irange(T stop) {
    return Range(stop);
}
template <class T>
Range<T> irange(T start, T stop, T step = 1) {
    return Range(start, stop, step);
}
}  // namespace bys
