#pragma once
#include "subrange.hpp"
/**
 * @file irange.hpp
 * @brief Python::range
 *
 * Python再現シリーズ range編
 * See: https://docs.python.org/ja/3/library/stdtypes.html#range
 */
namespace bys {
template <class T> class IntegerIncrementIterator {
  public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T;
    using pointer = T*;
    using iterator_category = std::bidirectional_iterator_tag;

    explicit IntegerIncrementIterator(T x) : value(x) {}

    reference operator*() noexcept { return value; }
    const reference operator*() const noexcept { return value; }

    auto operator++() noexcept {
        ++value;
        return *this;
    }
    auto operator++(int) noexcept {
        auto temp = *this;
        ++*this;
        return temp;
    }
    auto operator--() noexcept {
        --value;
        return *this;
    }
    auto operator--(int) {
        auto temp = *this;
        --*this;
        return temp;
    }

    bool operator!=(IntegerIncrementIterator const& other) const { return value != other.value; }
    bool operator==(IntegerIncrementIterator const& other) const { return value == other.value; }

  private:
    value_type value;
};

template <class T> class IntegerStepIterator {
  public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T;
    using pointer = T*;
    using iterator_category = std::bidirectional_iterator_tag;

    explicit IntegerStepIterator(T f, T x, T s) : start(f), value(x), step(s) {}

    reference operator*() noexcept { return start + value * step; }
    const reference operator*() const noexcept { return start + value * step; }

    auto operator++() {
        ++value;
        return *this;
    }
    auto operator++(int) {
        auto temp = *this;
        ++*this;
        return temp;
    }
    auto operator--() {
        --value;
        return *this;
    }
    auto operator--(int) {
        auto temp = *this;
        --*this;
        return temp;
    }

    bool operator!=(IntegerStepIterator const& other) const { return value != other.value; }
    bool operator==(IntegerStepIterator const& other) const { return value == other.value; }

  private:
    value_type start, value, step;
};

template <class T> SubRange<IntegerIncrementIterator<T>> irange(T stop) {
    static_assert(std::is_integral_v<T>, "T is not integer.");
    using iterator_t = IntegerIncrementIterator<T>;
    if (stop < static_cast<T>(0)) stop = static_cast<T>(0);
    return SubRange(iterator_t(static_cast<T>(0)), iterator_t(stop));
}
template <class T> SubRange<IntegerIncrementIterator<T>> irange(T start, T stop) {
    static_assert(std::is_integral_v<T>, "T is not integer.");
    using iterator_t = IntegerIncrementIterator<T>;
    if (stop < start) stop = start;
    return SubRange(iterator_t(start), iterator_t(stop));
}
template <class T> SubRange<IntegerStepIterator<T>> irange(T start, T stop, T step) {
    static_assert(std::is_integral_v<T>, "T is not integer.");
    using iterator_t = IntegerStepIterator<T>;
    assert(step != 0);
    auto w = step >= 0 ? stop - start : start - stop;
    auto s = step >= 0 ? step : -step;
    if (w < 0) w = 0;
    return SubRange(iterator_t(start, static_cast<T>(0), step),
                    iterator_t(start, (w + s - 1) / s, step));
}
}  // namespace bys
