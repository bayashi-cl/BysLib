#pragma once
#include "../core/alias.hpp"
#include "matrix.hpp"
/**
 * @file affine.hpp
 * @brief Affine Transformation
 */
namespace bys::affine {
Matrix<i64> ident() { return Matrix<i64>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<i64> rot_cw() { return Matrix<i64>({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}); }
Matrix<i64> rot_ccw() { return Matrix<i64>({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}); }
Matrix<i64> rev_xaxis() { return Matrix<i64>({{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}); }
Matrix<i64> rev_yaxis() { return Matrix<i64>({{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<i64> move(i64 x, i64 y) { return Matrix<i64>({{1, 0, x}, {0, 1, y}, {0, 0, 1}}); }

Matrix<i64> grid_rot_cw(i32, i32 w) { return Matrix<i64>({{0, 1, 0}, {-1, 0, w - 1}, {0, 0, 1}}); }
Matrix<i64> grid_rot_ccw(i32 h, i32) { return Matrix<i64>({{0, -1, h - 1}, {1, 0, 0}, {0, 0, 1}}); }
Matrix<i64> grid_rev_row(i32 h, i32) { return Matrix<i64>({{-1, 0, h - 1}, {0, 1, 0}, {0, 0, 1}}); }
Matrix<i64> grid_rev_col(i32, i32 w) { return Matrix<i64>({{1, 0, 0}, {0, -1, w - 1}, {0, 0, 1}}); }

std::pair<i64, i64> transform(const Matrix<i64>& mat, i64 x, i64 y) {
    std::vector<i64> v = {x, y, 1};
    std::vector<i64> res = mat * v;
    return {res[0], res[1]};
}
}  // namespace bys::affine
