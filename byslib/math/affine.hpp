#pragma once
#include "matrix.hpp"
/**
 * @file affine.hpp
 * @brief Affine Transformation
 */
namespace bys::affine {
Matrix<ll> ident() { return Matrix<ll>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<ll> rot_cw() { return Matrix<ll>({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}); }
Matrix<ll> rot_ccw() { return Matrix<ll>({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}); }
Matrix<ll> rev_xaxis() { return Matrix<ll>({{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}); }
Matrix<ll> rev_yaxis() { return Matrix<ll>({{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<ll> move(ll x, ll y) { return Matrix<ll>({{1, 0, x}, {0, 1, y}, {0, 0, 1}}); }

Matrix<ll> grid_rot_cw(int, int w) { return Matrix<ll>({{0, 1, 0}, {-1, 0, w - 1}, {0, 0, 1}}); }
Matrix<ll> grid_rot_ccw(int h, int) { return Matrix<ll>({{0, -1, h - 1}, {1, 0, 0}, {0, 0, 1}}); }
Matrix<ll> grid_rev_row(int h, int) { return Matrix<ll>({{-1, 0, h - 1}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<ll> grid_rev_col(int, int w) { return Matrix<ll>({{1, 0, 0}, {0, -1, w - 1}, {0, 0, 1}}); }

pair<ll, ll> transform(const Matrix<ll>& mat, ll x, ll y) {
    vector<ll> v = {x, y, 1};
    vector<ll> res = mat * v;
    return {res[0], res[1]};
}
}  // namespace bys::affine
