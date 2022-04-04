#pragma once
#include "../core/stdlib.hpp"
/**
 * @file matrix.hpp
 * @brief Matrix
 * @todo geoとの連携
 */
namespace bys {
//! @brief 行列
template <class T>
struct Matrix {
    vector<vector<T>> mat;
    Matrix(int i, int j) : mat(i, vector<T>(j)), r(i), c(j) {}
    Matrix(const vector<vector<T>>& v) : mat(v), r(v.size()), c(v[0].size()) {}

    vector<T>& operator[](int k) { return mat[k]; }
    int row() const { return r; }
    int col() const { return c; }
    pair<int, int> shape() const { return {r, c}; }

    Matrix operator+(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] + rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix<T>& rh) const {
        assert(shape() == rh.shape());
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] - rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const T rh) const {
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] * rh;
            }
        }
        return res;
    }
    Matrix operator/(const T rh) const {
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] / rh;
            }
        }
        return res;
    }

    Matrix operator*(const Matrix<T>& rh) const {
        assert(col() == rh.row());
        int d = rh.col();
        Matrix<T> res(r, d);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < d; ++j) {
                for (int k = 0; k < c; ++k) {
                    res.mat[i][j] += mat[i][k] * rh.mat[k][j];
                }
            }
        }
        return res;
    }
    vector<T> operator*(const vector<T>& rh) const {
        int n = rh.size();
        assert(col() == n);
        vector<T> res(r);
        for (int i = 0; i < r; ++i) {
            res[i] = std::inner_product(mat[i].begin(), mat[i].end(), rh.begin(), (T)0);
        }
        return res;
    }

    Matrix rotate90() const {
        Matrix<T> res(c, r);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res.mat[j][r - i - 1] = mat[i][j];
            }
        }
        return res;
    }

    auto pow(ll p) const {
        assert(r == c);
        auto res = Matrix<T>::ident(r);
        auto base = *this;
        for (; p > 0; p >>= 1, base = base * base) {
            if (p & 1) res = res * base;
        }
        return res;
    }

    static Matrix<T> ident(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res.mat[i][i] = T(1);
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
    int r, c;
};
}  // namespace bys
