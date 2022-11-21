#pragma once
#include "../core/stdlib.hpp"
/**
 * @file base.hpp
 * @brief Base
 */
//! @brief 幾何
namespace bys::geo {
constexpr ld EPS = 1e-9;
const ld PI = std::acos(-1.0);
const ld TAU = PI * 2;
int sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(ld a, ld b) { return sgn(a - b) == 0; }
//! @brief 度数法 -> 弧度法
ld radian(ld degree) { return degree * (PI / 180.0); }
//! @brief 弧度法 -> 度数法
ld degree(ld theta) { return theta * (180.0 / PI); }
}  // namespace bys::geo
