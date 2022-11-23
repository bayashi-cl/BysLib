#pragma once
#include "subrange.hpp"
namespace bys {
template <class T> class SubsetIterator {
    static_assert(std::is_integral_v<T>, "T is not integral.");

  public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using reference = T;
    using pointer = T*;
    using iterator_category = std::forward_iterator_tag;

    SubsetIterator(T s) : _t(s), _s(s) {}

    reference operator*() { return _t; }
    const reference operator*() const { return _t; }

    SubsetIterator& operator++() {
        if (_t == 0) {
            sentinel = true;
        } else {
            _t = (_t - 1) & _s;
        }
        return *this;
    }
    SubsetIterator operator++(int) {
        auto temp = *this;
        ++*this;
        return temp;
    }

    bool operator!=(const SubsetIterator& other) const { return not sentinel; }
    bool operator==(const SubsetIterator& other) const { return not(*this != other); }

  private:
    T _t;
    const T _s;
    bool sentinel = false;
};
template <class T> SubRange<SubsetIterator<T>> subset(T s) {
    return SubRange(SubsetIterator<T>(s), SubsetIterator<T>(s));
}
}  // namespace bys
