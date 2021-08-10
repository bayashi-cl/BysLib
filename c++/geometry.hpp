#pragma once
#include <complex>

#include "bys.hpp"

namespace bys {
namespace geo {
const double EPS = 1e-9;
const double PI = std::acos(-1.0);
int sgn(const double a) { return (a < -EPS ? -1 : (a > EPS ? +1 : 0)); }

using Point = std::complex<double>;
double len(Point a) { return std::abs(a); }
double dot(Point a, Point b) { return (a * std::conj(b)).real(); }
double det(Point a, Point b) { return (a * std::conj(b)).imag(); }
Point rot(Point a, double theta);
using Segment = pair<Point, Point>;
double len(Segment s) { return std::abs(s.second - s.first); }
bool cross(Segment a, Segment b) {
    double d1 = det(a.second - a.first, b.first - a.first);
    double d2 = det(a.second - a.first, b.second - a.first);
    double d3 = det(b.second - b.first, a.first - b.first);
    double d4 = det(b.second - b.first, a.second - b.first);
    return (sgn(d1) * sgn(d2) == -1 && sgn(d3) * sgn(d4) == -1);
}
}  // namespace geo
}  // namespace bys
