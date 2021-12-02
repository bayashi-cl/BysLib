#pragma once
#include "byslib/template/bys.hpp"

namespace bys {
template <class T>
struct Matrix {
    vector<vector<T>> mat;
    Matrix(int i, int j) : mat(i, vector<T>(j)), r(i), c(j) {}

    vector<T>& operator[](int k) { return mat[k]; }
    int row() const { return r; }
    int col() const { return c; }
    pair<int, int> shape() const { return {r, c}; }

    Matrix operator+(const Matrix<T>& rh) {
        assert(shape() == rh.shape());
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
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] - rh.mat[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const T rh) {
        Matrix<T> res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[i][j] = mat[i][j] * rh;
            }
        }
        return res;
    }
    Matrix operator/(const T rh) {
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
        int k = rh.col();
        Matrix<T> res(r, k);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int k = 0; k < c; ++k) {
                    res.mat[i][j] += mat[i][k] * rh.mat[k][j];
                }
            }
        }
    }

    Matrix rotate() const {
        Matrix<T> res(c, r);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res.mat[j][r - i - 1] = mat[i][j];
            }
        }
        return res;
    }

    static Matrix<T> ident(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res.mat[i][i] = 1;
        return res;
    }
    // static Matrix<double> rotate(double theta) {}

   private:
    int r, c;
};
}  // namespace bys
