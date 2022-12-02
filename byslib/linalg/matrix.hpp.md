---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: byslib/linalg/affine.hpp
    title: Affine Transformation
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Matrix
    links: []
  bundledCode: "#include <cassert>\n#include <cmath>\n#include <numeric>\n#include\
    \ <vector>\n\n#include <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing\
    \ i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\n\
    using i128 = __int128_t;\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = __uint128_t;\n\
    using f32 = float;\nusing f64 = double;\nusing f128 = long double;\n\nusing isize\
    \ = std::ptrdiff_t;\nusing usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name,\
    \ type) \\\n    constexpr auto operator\"\" name(unsigned long long x) { return\
    \ static_cast<type>(x); }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16,\
    \ std::int16_t);\nDEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64,\
    \ std::int64_t);\nDEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8,\
    \ std::uint8_t);\nDEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32,\
    \ std::uint32_t);\nDEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128,\
    \ __uint128_t);\nDEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n\
    }  // namespace bys\n/**\n * @file matrix.hpp\n * @brief Matrix\n * @todo geo\u3068\
    \u306E\u9023\u643A\n */\nnamespace bys {\n//! @brief \u884C\u5217\ntemplate <class\
    \ T> struct Matrix {\n    std::vector<std::vector<T>> mat;\n    Matrix(i32 i,\
    \ i32 j) : mat(i, std::vector<T>(j)), r(i), c(j) {}\n    Matrix(const std::vector<std::vector<T>>&\
    \ v) : mat(v), r(v.size()), c(v[0].size()) {}\n\n    std::vector<T>& operator[](i32\
    \ k) { return mat[k]; }\n    i32 row() const { return r; }\n    i32 col() const\
    \ { return c; }\n    std::pair<i32, i32> shape() const { return {r, c}; }\n\n\
    \    Matrix operator+(const Matrix<T>& rh) const {\n        assert(shape() ==\
    \ rh.shape());\n        Matrix<T> res(r, c);\n        for (i32 i = 0; i < r; ++i)\
    \ {\n            for (i32 j = 0; j < c; ++j) {\n                res[i][j] = mat[i][j]\
    \ + rh.mat[i][j];\n            }\n        }\n        return res;\n    }\n    Matrix\
    \ operator-(const Matrix<T>& rh) const {\n        assert(shape() == rh.shape());\n\
    \        Matrix<T> res(r, c);\n        for (i32 i = 0; i < r; ++i) {\n       \
    \     for (i32 j = 0; j < c; ++j) {\n                res[i][j] = mat[i][j] - rh.mat[i][j];\n\
    \            }\n        }\n        return res;\n    }\n    Matrix operator*(const\
    \ T rh) const {\n        Matrix<T> res(r, c);\n        for (i32 i = 0; i < r;\
    \ ++i) {\n            for (i32 j = 0; j < c; ++j) {\n                res[i][j]\
    \ = mat[i][j] * rh;\n            }\n        }\n        return res;\n    }\n  \
    \  Matrix operator/(const T rh) const {\n        Matrix<T> res(r, c);\n      \
    \  for (i32 i = 0; i < r; ++i) {\n            for (i32 j = 0; j < c; ++j) {\n\
    \                res[i][j] = mat[i][j] / rh;\n            }\n        }\n     \
    \   return res;\n    }\n\n    Matrix operator*(const Matrix<T>& rh) const {\n\
    \        assert(col() == rh.row());\n        i32 d = rh.col();\n        Matrix<T>\
    \ res(r, d);\n        for (i32 i = 0; i < r; ++i) {\n            for (i32 j =\
    \ 0; j < d; ++j) {\n                for (i32 k = 0; k < c; ++k) {\n          \
    \          res.mat[i][j] += mat[i][k] * rh.mat[k][j];\n                }\n   \
    \         }\n        }\n        return res;\n    }\n    std::vector<T> operator*(const\
    \ std::vector<T>& rh) const {\n        i32 n = rh.size();\n        assert(col()\
    \ == n);\n        std::vector<T> res(r);\n        for (i32 i = 0; i < r; ++i)\
    \ {\n            res[i] = std::inner_product(mat[i].begin(), mat[i].end(), rh.begin(),\
    \ (T)0);\n        }\n        return res;\n    }\n\n    Matrix rotate90() const\
    \ {\n        Matrix<T> res(c, r);\n        for (i32 i = 0; i < r; ++i) {\n   \
    \         for (i32 j = 0; j < c; ++j) {\n                res.mat[j][r - i - 1]\
    \ = mat[i][j];\n            }\n        }\n        return res;\n    }\n\n    auto\
    \ pow(i64 p) const {\n        assert(r == c);\n        auto res = Matrix<T>::ident(r);\n\
    \        auto base = *this;\n        for (; p > 0; p >>= 1, base = base * base)\
    \ {\n            if (p & 1) res = res * base;\n        }\n        return res;\n\
    \    }\n\n    static Matrix<T> ident(i32 n) {\n        Matrix res(n, n);\n   \
    \     for (i32 i = 0; i < n; ++i) res.mat[i][i] = T(1);\n        return res;\n\
    \    }\n    static Matrix<double> rotate(double theta) {\n        Matrix<double>\
    \ res(2, 2);\n        res[0][0] = std::cos(theta);\n        res[0][1] = -std::sin(theta);\n\
    \        res[1][0] = std::sin(theta);\n        res[1][1] = std::cos(theta);\n\
    \        return res;\n    }\n\n  private:\n    i32 r, c;\n};\n}  // namespace\
    \ bys\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <numeric>\n\
    #include <vector>\n\n#include \"../core/int_alias.hpp\"\n/**\n * @file matrix.hpp\n\
    \ * @brief Matrix\n * @todo geo\u3068\u306E\u9023\u643A\n */\nnamespace bys {\n\
    //! @brief \u884C\u5217\ntemplate <class T> struct Matrix {\n    std::vector<std::vector<T>>\
    \ mat;\n    Matrix(i32 i, i32 j) : mat(i, std::vector<T>(j)), r(i), c(j) {}\n\
    \    Matrix(const std::vector<std::vector<T>>& v) : mat(v), r(v.size()), c(v[0].size())\
    \ {}\n\n    std::vector<T>& operator[](i32 k) { return mat[k]; }\n    i32 row()\
    \ const { return r; }\n    i32 col() const { return c; }\n    std::pair<i32, i32>\
    \ shape() const { return {r, c}; }\n\n    Matrix operator+(const Matrix<T>& rh)\
    \ const {\n        assert(shape() == rh.shape());\n        Matrix<T> res(r, c);\n\
    \        for (i32 i = 0; i < r; ++i) {\n            for (i32 j = 0; j < c; ++j)\
    \ {\n                res[i][j] = mat[i][j] + rh.mat[i][j];\n            }\n  \
    \      }\n        return res;\n    }\n    Matrix operator-(const Matrix<T>& rh)\
    \ const {\n        assert(shape() == rh.shape());\n        Matrix<T> res(r, c);\n\
    \        for (i32 i = 0; i < r; ++i) {\n            for (i32 j = 0; j < c; ++j)\
    \ {\n                res[i][j] = mat[i][j] - rh.mat[i][j];\n            }\n  \
    \      }\n        return res;\n    }\n    Matrix operator*(const T rh) const {\n\
    \        Matrix<T> res(r, c);\n        for (i32 i = 0; i < r; ++i) {\n       \
    \     for (i32 j = 0; j < c; ++j) {\n                res[i][j] = mat[i][j] * rh;\n\
    \            }\n        }\n        return res;\n    }\n    Matrix operator/(const\
    \ T rh) const {\n        Matrix<T> res(r, c);\n        for (i32 i = 0; i < r;\
    \ ++i) {\n            for (i32 j = 0; j < c; ++j) {\n                res[i][j]\
    \ = mat[i][j] / rh;\n            }\n        }\n        return res;\n    }\n\n\
    \    Matrix operator*(const Matrix<T>& rh) const {\n        assert(col() == rh.row());\n\
    \        i32 d = rh.col();\n        Matrix<T> res(r, d);\n        for (i32 i =\
    \ 0; i < r; ++i) {\n            for (i32 j = 0; j < d; ++j) {\n              \
    \  for (i32 k = 0; k < c; ++k) {\n                    res.mat[i][j] += mat[i][k]\
    \ * rh.mat[k][j];\n                }\n            }\n        }\n        return\
    \ res;\n    }\n    std::vector<T> operator*(const std::vector<T>& rh) const {\n\
    \        i32 n = rh.size();\n        assert(col() == n);\n        std::vector<T>\
    \ res(r);\n        for (i32 i = 0; i < r; ++i) {\n            res[i] = std::inner_product(mat[i].begin(),\
    \ mat[i].end(), rh.begin(), (T)0);\n        }\n        return res;\n    }\n\n\
    \    Matrix rotate90() const {\n        Matrix<T> res(c, r);\n        for (i32\
    \ i = 0; i < r; ++i) {\n            for (i32 j = 0; j < c; ++j) {\n          \
    \      res.mat[j][r - i - 1] = mat[i][j];\n            }\n        }\n        return\
    \ res;\n    }\n\n    auto pow(i64 p) const {\n        assert(r == c);\n      \
    \  auto res = Matrix<T>::ident(r);\n        auto base = *this;\n        for (;\
    \ p > 0; p >>= 1, base = base * base) {\n            if (p & 1) res = res * base;\n\
    \        }\n        return res;\n    }\n\n    static Matrix<T> ident(i32 n) {\n\
    \        Matrix res(n, n);\n        for (i32 i = 0; i < n; ++i) res.mat[i][i]\
    \ = T(1);\n        return res;\n    }\n    static Matrix<double> rotate(double\
    \ theta) {\n        Matrix<double> res(2, 2);\n        res[0][0] = std::cos(theta);\n\
    \        res[0][1] = -std::sin(theta);\n        res[1][0] = std::sin(theta);\n\
    \        res[1][1] = std::cos(theta);\n        return res;\n    }\n\n  private:\n\
    \    i32 r, c;\n};\n}  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/linalg/matrix.hpp
  requiredBy:
  - byslib/linalg/affine.hpp
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/linalg/matrix.hpp
layout: document
redirect_from:
- /library/byslib/linalg/matrix.hpp
- /library/byslib/linalg/matrix.hpp.html
title: Matrix
---
