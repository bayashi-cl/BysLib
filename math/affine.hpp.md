---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: STL Template
  - icon: ':warning:'
    path: math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Affine Transformation
    links: []
  bundledCode: "/**\n * @file stdlib.hpp\n * @brief STL Template\n */\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace\
    \ bys {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n/**\n * @file matrix.hpp\n * @brief Matrix\n * @todo geo\u3068\u306E\u9023\
    \u643A\n */\nnamespace bys {\n//! @brief \u884C\u5217\ntemplate <class T>\nstruct\
    \ Matrix {\n    vector<vector<T>> mat;\n    Matrix(int i, int j) : mat(i, vector<T>(j)),\
    \ r(i), c(j) {}\n    Matrix(const vector<vector<T>>& v) : mat(v), r(v.size()),\
    \ c(v[0].size()) {}\n\n    vector<T>& operator[](int k) { return mat[k]; }\n \
    \   int row() const { return r; }\n    int col() const { return c; }\n    pair<int,\
    \ int> shape() const { return {r, c}; }\n\n    Matrix operator+(const Matrix<T>&\
    \ rh) const {\n        assert(shape() == rh.shape());\n        Matrix<T> res(r,\
    \ c);\n        for (int i = 0; i < r; ++i) {\n            for (int j = 0; j <\
    \ c; ++j) {\n                res[i][j] = mat[i][j] + rh.mat[i][j];\n         \
    \   }\n        }\n        return res;\n    }\n    Matrix operator-(const Matrix<T>&\
    \ rh) const {\n        assert(shape() == rh.shape());\n        Matrix<T> res(r,\
    \ c);\n        for (int i = 0; i < r; ++i) {\n            for (int j = 0; j <\
    \ c; ++j) {\n                res[i][j] = mat[i][j] - rh.mat[i][j];\n         \
    \   }\n        }\n        return res;\n    }\n    Matrix operator*(const T rh)\
    \ const {\n        Matrix<T> res(r, c);\n        for (int i = 0; i < r; ++i) {\n\
    \            for (int j = 0; j < c; ++j) {\n                res[i][j] = mat[i][j]\
    \ * rh;\n            }\n        }\n        return res;\n    }\n    Matrix operator/(const\
    \ T rh) const {\n        Matrix<T> res(r, c);\n        for (int i = 0; i < r;\
    \ ++i) {\n            for (int j = 0; j < c; ++j) {\n                res[i][j]\
    \ = mat[i][j] / rh;\n            }\n        }\n        return res;\n    }\n\n\
    \    Matrix operator*(const Matrix<T>& rh) const {\n        assert(col() == rh.row());\n\
    \        int d = rh.col();\n        Matrix<T> res(r, d);\n        for (int i =\
    \ 0; i < r; ++i) {\n            for (int j = 0; j < d; ++j) {\n              \
    \  for (int k = 0; k < c; ++k) {\n                    res.mat[i][j] += mat[i][k]\
    \ * rh.mat[k][j];\n                }\n            }\n        }\n        return\
    \ res;\n    }\n    vector<T> operator*(const vector<T>& rh) const {\n        int\
    \ n = rh.size();\n        assert(col() == n);\n        vector<T> res(r);\n   \
    \     for (int i = 0; i < r; ++i) {\n            res[i] = std::inner_product(mat[i].begin(),\
    \ mat[i].end(), rh.begin(), (T)0);\n        }\n        return res;\n    }\n\n\
    \    Matrix rotate90() const {\n        Matrix<T> res(c, r);\n        for (int\
    \ i = 0; i < r; ++i) {\n            for (int j = 0; j < c; ++j) {\n          \
    \      res.mat[j][r - i - 1] = mat[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    auto pow(ll p) const {\n        assert(r == c);\n       \
    \ auto res = Matrix<T>::ident(r);\n        auto base = *this;\n        for (;\
    \ p > 0; p >>= 1, base = base * base) {\n            if (p & 1) res = res * base;\n\
    \        }\n        return res;\n    }\n\n    static Matrix<T> ident(int n) {\n\
    \        Matrix res(n, n);\n        for (int i = 0; i < n; ++i) res.mat[i][i]\
    \ = T(1);\n        return res;\n    }\n    static Matrix<double> rotate(double\
    \ theta) {\n        Matrix<double> res(2, 2);\n        res[0][0] = std::cos(theta);\n\
    \        res[0][1] = -std::sin(theta);\n        res[1][0] = std::sin(theta);\n\
    \        res[1][1] = std::cos(theta);\n        return res;\n    }\n\n   private:\n\
    \    int r, c;\n};\n}  // namespace bys\n/**\n * @file affine.hpp\n * @brief Affine\
    \ Transformation\n */\nnamespace bys::affine {\nMatrix<ll> ident() { return Matrix<ll>({{1,\
    \ 0, 0}, {0, 1, 0}, {0, 0, 1}}); }\nMatrix<ll> rot_cw() { return Matrix<ll>({{0,\
    \ -1, 0}, {1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll> rot_ccw() { return Matrix<ll>({{0,\
    \ 1, 0}, {-1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll> rev_xaxis() { return Matrix<ll>({{1,\
    \ 0, 0}, {0, -1, 0}, {0, 0, 1}}); }\nMatrix<ll> rev_yaxis() { return Matrix<ll>({{-1,\
    \ 0, 0}, {0, 1, 0}, {0, 0, 1}}); }\nMatrix<ll> move(ll x, ll y) { return Matrix<ll>({{1,\
    \ 0, x}, {0, 1, y}, {0, 0, 1}}); }\n\nMatrix<ll> grid_rot_cw(int, int w) { return\
    \ Matrix<ll>({{0, 1, 0}, {-1, 0, w - 1}, {0, 0, 1}}); }\nMatrix<ll> grid_rot_ccw(int\
    \ h, int) { return Matrix<ll>({{0, -1, h - 1}, {1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll>\
    \ grid_rev_row(int h, int) { return Matrix<ll>({{-1, 0, h - 1}, {0, 1, 0}, {0,\
    \ 0, 1}}); }\nMatrix<ll> grid_rev_col(int, int w) { return Matrix<ll>({{1, 0,\
    \ 0}, {0, -1, w - 1}, {0, 0, 1}}); }\n\npair<ll, ll> transform(const Matrix<ll>&\
    \ mat, ll x, ll y) {\n    vector<ll> v = {x, y, 1};\n    vector<ll> res = mat\
    \ * v;\n    return {res[0], res[1]};\n}\n}  // namespace bys::affine\n"
  code: "#pragma once\n#include \"matrix.hpp\"\n/**\n * @file affine.hpp\n * @brief\
    \ Affine Transformation\n */\nnamespace bys::affine {\nMatrix<ll> ident() { return\
    \ Matrix<ll>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }\nMatrix<ll> rot_cw() { return\
    \ Matrix<ll>({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll> rot_ccw() { return\
    \ Matrix<ll>({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll> rev_xaxis() {\
    \ return Matrix<ll>({{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}); }\nMatrix<ll> rev_yaxis()\
    \ { return Matrix<ll>({{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}); }\nMatrix<ll> move(ll\
    \ x, ll y) { return Matrix<ll>({{1, 0, x}, {0, 1, y}, {0, 0, 1}}); }\n\nMatrix<ll>\
    \ grid_rot_cw(int, int w) { return Matrix<ll>({{0, 1, 0}, {-1, 0, w - 1}, {0,\
    \ 0, 1}}); }\nMatrix<ll> grid_rot_ccw(int h, int) { return Matrix<ll>({{0, -1,\
    \ h - 1}, {1, 0, 0}, {0, 0, 1}}); }\nMatrix<ll> grid_rev_row(int h, int) { return\
    \ Matrix<ll>({{-1, 0, h - 1}, {0, 1, 0}, {0, 0, 1}}); }\nMatrix<ll> grid_rev_col(int,\
    \ int w) { return Matrix<ll>({{1, 0, 0}, {0, -1, w - 1}, {0, 0, 1}}); }\n\npair<ll,\
    \ ll> transform(const Matrix<ll>& mat, ll x, ll y) {\n    vector<ll> v = {x, y,\
    \ 1};\n    vector<ll> res = mat * v;\n    return {res[0], res[1]};\n}\n}  // namespace\
    \ bys::affine\n"
  dependsOn:
  - math/matrix.hpp
  - core/stdlib.hpp
  isVerificationFile: false
  path: math/affine.hpp
  requiredBy: []
  timestamp: '2022-04-04 23:07:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/affine.hpp
layout: document
redirect_from:
- /library/math/affine.hpp
- /library/math/affine.hpp.html
title: Affine Transformation
---