#pragma once
#include "byslib/template/bys.hpp"

namespace bys::geo {
const ld EPS = 1e-9;
const ld PI = std::acos(-1.0);
int sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }
bool isclose(ld a, ld b) { return sgn(a - b) == 0; }
ld radian(ld degree) { return degree * (PI / 180.0); }
ld degree(ld theta) { return theta * (180.0 / PI); }
}  // namespace bys::geo
