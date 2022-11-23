#pragma once
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

#include "../core/alias.hpp"
/**
 * @file matrix.hpp
 * @brief Matrix
 * @todo geoとの連携
 */
namespace bys {
//! @brief 行列
template <class T> struct Matrix {
    std::vector<std::vector<T>> mat;
    Matrix(i32 i, i32 j) : mat(i, std::vector<T>(j)), r(i), c(j) {}
    Matrix(const std::vector<std::vector<T>>& v) : mat(v), r(v.size()), c(v[0].size()) {}

    std::vector<T>& operator[](i32 k) { return mat[k]; }
    i32 row() const { return r; }
    i32 col() const { return c; }
    std::pair<i32, i32> shape() const { return {r, c}; }

    Matrix operator+(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(r, c);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] + rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(r, c);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] - rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const T rh) const {
        Matrix<T> res(r, c);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] * rh;
            }
        }
        return res;
    }
    Matrix operator/(const T rh) const {
        Matrix<T> res(r, c);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] / rh;
            }
        }
        return res;
    }

    Matrix operator*(const Matrix<T>& rh) const {
        assert(col() == rh.row());
        i32 d = rh.col();
        Matrix<T> res(r, d);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < d; ++j) {
                for (i32 k = 0; k < c; ++k) {
                    res.mat[i][j] += mat[i][k] * rh.mat[k][j];
                }
            }
        }
        return res;
    }
    std::vector<T> operator*(const std::vector<T>& rh) const {
        i32 n = rh.size();
        assert(col() == n);
        std::vector<T> res(r);
        for (i32 i = 0; i < r; ++i) {
            res[i] = std::inner_product(mat[i].begin(), mat[i].end(), rh.begin(), (T)0);
        }
        return res;
    }

    Matrix rotate90() const {
        Matrix<T> res(c, r);
        for (i32 i = 0; i < r; ++i) {
            for (i32 j = 0; j < c; ++j) {
                res.mat[j][r - i - 1] = mat[i][j];
            }
        }
        return res;
    }

    auto pow(i64 p) const {
        assert(r == c);
        auto res = Matrix<T>::ident(r);
        auto base = *this;
        for (; p > 0; p >>= 1, base = base * base) {
            if (p & 1) res = res * base;
        }
        return res;
    }

    static Matrix<T> ident(i32 n) {
        Matrix res(n, n);
        for (i32 i = 0; i < n; ++i) res.mat[i][i] = T(1);
        return res;
    }
    static Matrix<double> rotate(double theta) {
        Matrix<double> res(2, 2);
        res[0][0] = std::cos(theta);
        res[0][1] = -std::sin(theta);
        res[1][0] = std::sin(theta);
        res[1][1] = std::cos(theta);
        return res;
    }

  private:
    i32 r, c;
};
}  // namespace bys
