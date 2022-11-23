#pragma once
#include <numeric>
#include <utility>
#include <vector>

#include "../utility/subrange.hpp"
#include "coo.hpp"

namespace bys {
template <class T> class CSRMatrix {
  public:
    using value_type = T;
    const std::pair<int, int> shape;

  private:
    std::vector<int> _indptr, _indices;
    std::vector<T> _data;

  public:
    CSRMatrix(const COOMatrix<T>& coo)
        : shape(coo.shape),
          _indptr(coo._col_cnt),
          _indices(coo._data.size()),
          _data(coo._data.size()) {
        _indptr.push_back(0);

        std::partial_sum(_indptr.begin(), _indptr.end(), _indptr.begin());
        for (auto&& [i, j, v] : coo._data) {
            int index = --_indptr[i];
            _indices[index] = j;
            _data[index] = v;
        }
    }
    CSRMatrix(std::pair<int, int> shape, const std::vector<std::vector<std::pair<int, T>>>& data)
        : shape(shape), _indptr(shape.first + 1) {
        for (int i = 0; i < shape.first; ++i) {
            for (auto&& [index, elem] : data[i]) {
                _indices.push_back(index);
                _data.push_back(elem);
            }
            _indptr[i + 1] += _indptr[i] + data[i].size();
        }
    }
    auto operator[](std::size_t i) const {
        return SubRange(_data.cbegin() + _indptr[i], _data.cbegin() + _indptr[i + 1]);
    }
    std::size_t size() const { return shape.first; }
};
}  // namespace bys
