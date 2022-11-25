#pragma once
#include <cmath>

#include "../core/alias.hpp"
/**
 * @file base.hpp
 * @brief Base
 */
//! @brief 幾何
namespace bys::geo {
constexpr f128 EPS = 1e-9;
const f128 PI = std::acos(-1.0);
const f128 TAU = PI * 2;
i32 sgn(f128 a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(f128 a, f128 b) { return sgn(a - b) == 0; }
//! @brief 度数法 -> 弧度法
f128 radian(f128 degree) { return degree * (PI / 180.0); }
//! @brief 弧度法 -> 度数法
f128 degree(f128 theta) { return theta * (180.0 / PI); }
}  // namespace bys::geo
