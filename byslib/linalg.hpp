#pragma once
#include "byslib/template/bys.hpp"

namespace bys {
template <class T>
struct Matrix {
    vector<vector<T>> mat;
    Matrix(int i, int j) : mat(i, vector<T>(j)) {}

    vector<T>& operator[](int k) { return mat[k]; }
    int row() const { return mat.size(); }
    int col() const { return mat[0].size(); }
    pair<int, int> shape() const { return {row(), col()}; }

    Matrix operator+(const Matrix<T>& rh) {
        assert(shape() == rh.shape());
        auto [r, c] = shape();
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] + rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix<T>& rh) {
        assert(shape() == rh.shape());
        auto [r, c] = shape();
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] - rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const T rh) {
        auto [r, c] = shape();
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] * rh;
            }
        }
        return res;
    }
    Matrix operator/(const T rh) {
        auto [r, c] = shape();
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] / rh;
            }
        }
        return res;
    }

    Matrix operator*(const Matrix<T>& rh) {
        assert(col() == rh.row());
        auto [r, m] = shape();
        int c = rh.col();
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < m; ++k) {
                    res.mat[i][j] += mat[i][k] * rh.mat[k][j];
                }
            }
        }
    }

    template <class T>
    static Matrix<T> ident(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) mat[i][i] = 1;
        return res;
    }
    static Matrix<double> rotate(double theta) {}
};
}  // namespace bys
