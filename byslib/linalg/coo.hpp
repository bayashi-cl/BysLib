#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include "../core/int_alias.hpp"
#include "sparsefwd.hpp"

namespace bys {
template <class T> class COOMatrix {
  public:
    using value_type = T;
    const std::pair<i32, i32> shape;

  private:
    std::vector<std::tuple<i32, i32, T>> _data;
    std::vector<i32> _col_cnt;

  public:
    COOMatrix(i32 n, i32 m = -1) : shape{n, m}, _col_cnt(n) {}

    void set(i32 i, i32 j, const T& v) {
        assert(0 <= i and i < shape.first);
        ++_col_cnt[i];
        _data.emplace_back(i, j, v);
    }
    void push_back(i32 i, T&& v) { set(i, _col_cnt[i], std::forward<T>(v)); }
    template <class... Args> void emplace_back(i32 i, Args&&... args) {
        set(i, _col_cnt[i], {std::forward<Args>(args)...});
    }
    auto begin() const { return _data.begin(); }
    auto end() const { return _data.end(); }

    void sort() {
        std::sort(_data.begin(), _data.end(),
                  [](const std::tuple<i32, i32, T>& a, const std::tuple<i32, i32, T>& b) {
                      return std::get<2>(a) < std::get<2>(b);
                  });
    }
    std::size_t size() const { return shape.first; }
    std::ptrdiff_t ssize() const { return shape.first; }
    std::size_t nonzero() const { return _data.size(); }

    friend CSRMatrix<T>;
};
}  // namespace bys
