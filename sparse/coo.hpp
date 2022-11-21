#pragma once
#include <utility>
#include <vector>

#include "sparsefwd.hpp"

namespace bys {
template <class T>
class COOMatrix {
   public:
    using value_type = T;
    const std::pair<int, int> shape;

   private:
    std::vector<std::tuple<int, int, T>> _data;
    std::vector<int> _col_cnt;

   public:
    COOMatrix(int n, int m = -1) : shape{n, m}, _col_cnt(n) {}

    void set(int i, int j, const T& v) {
        assert(0 <= i and i < shape.first);
        ++_col_cnt[i];
        _data.emplace_back(i, j, v);
    }
    void push_back(int i, T&& v) { set(i, _col_cnt[i], std::forward<T>(v)); }
    template <class... Args>
    void emplace_back(int i, Args&&... args) {
        set(i, _col_cnt[i], {std::forward<Args>(args)...});
    }
    auto begin() const { return _data.begin(); }
    auto end() const { return _data.end(); }

    void sort() {
        std::sort(_data.begin(), _data.end(), [](const std::tuple<int, int, T>& a, const std::tuple<int, int, T>& b) {
            return std::get<2>(a) < std::get<2>(b);
        });
    }
    std::size_t size() const { return shape.first; }
    std::size_t nonzero() const { return _data.size(); }

    friend CSRMatrix<T>;
};
}  // namespace bys
