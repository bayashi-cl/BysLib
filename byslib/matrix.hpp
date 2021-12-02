#pragma once
#include <valarray>

#include "byslib/template/bys.hpp"
namespace bys {
using std::valarray;
template <class T>
struct Matrix {
    valarray<valarray<T>> mat;
    int row, col;
    Matrix(int row_, int col_) {
        row = row_;
        col = col_;
        mat = valarray<valarray<T>>(valarray<T>(col), row);
    }

    valarray<T>& operator[](int k) { return mat[k]; }
    void set(int i, int j, T v) { mat[i][j] = v; }
    pair<int, int> shape() const { return {row, col}; }

    Matrix transpose() const {
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res.mat[j][i] = mat[i][j];
            }
        }
    }
    Matrix rotate() const {
        Matrix<T> res(col, row);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res.mat[j][row - i - 1] = mat[i][j];
            }
        }
        return res;
    }

    Matrix operator+(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] + rh.mat[i];
        }
        return res;
    }
    Matrix operator+(const T rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] + rh;
        }
        return res;
    }
    Matrix operator+=(const Matrix<T>& rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] += rh.mat[i];
        }
        return *this;
    }
    Matrix operator+=(const T rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] += rh;
        }
        return *this;
    }
    Matrix operator-(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] - rh.mat[i];
        }
        return res;
    }
    Matrix operator-(const T rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] - rh;
        }
        return res;
    }
    Matrix operator-=(const Matrix<T>& rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] -= rh.mat[i];
        }
        return *this;
    }
    Matrix operator-=(const T rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] -= rh;
        }
        return *this;
    }

    Matrix operator*(const Matrix<T>& rh) const {
        auto rht = rh.transpose();
        assert(shape() == rht.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res.mat[i][j] = (mat[i] * rht.mat[j]).sum();
            }
        }
        return res;
    }
    Matrix operator*(const T rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] * rh;
        }
        return res;
    }
    // Matrix operator*=(const Matrix<T>& rh) {
    //     assert(shape() == rh.shape());
    //     for (int i = 0; i < row; ++i) {
    //         mat[i] += rh.mat[i];
    //     }
    //     return *this;
    // }
    Matrix operator*=(const T rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] *= rh;
        }
        return *this;
    }
    Matrix operator/(const T rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] / rh;
        }
        return res;
    }
    Matrix operator/=(const T rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] /= rh;
        }
        return *this;
    }
    Matrix operator%(const T rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(row, col);
        for (int i = 0; i < row; ++i) {
            res.mat[i] = mat[i] % rh;
        }
        return res;
    }
    Matrix operator%=(const T rh) {
        assert(shape() == rh.shape());
        for (int i = 0; i < row; ++i) {
            mat[i] %= rh;
        }
        return *this;
    }
};
template <class T>
Matrix<T> pow(const Matrix<T>& mat, int p) {
    auto [c, r] = mat.shape();
    Matrix<T> res(c, r);
    return res;
}
}  // namespace bys
