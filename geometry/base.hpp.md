---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: "\u70B9/\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/area.test.cpp
    title: test/geometry/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/counter_clockwise.test.cpp
    title: test/geometry/counter_clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/cross_point.test.cpp
    title: test/geometry/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/distance.test.cpp
    title: test/geometry/distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/intersection.test.cpp
    title: test/geometry/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/is_convex.test.cpp
    title: test/geometry/is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/parallel_orthogonal.test.cpp
    title: test/geometry/parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/projection.test.cpp
    title: test/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/reflection.test.cpp
    title: test/geometry/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#ifndef LOCAL

    #define NDEBUG

    #endif


    #include <algorithm>

    #include <array>

    #include <cassert>

    #include <cmath>

    #include <complex>

    #include <functional>

    #include <iomanip>

    #include <iostream>

    #include <iterator>

    #include <limits>

    #include <map>

    #include <numeric>

    #include <queue>

    #include <set>

    #include <stack>

    #include <string>

    #include <type_traits>

    #include <unordered_map>

    #include <unordered_set>

    #include <vector>


    namespace bys {

    using std::array, std::vector, std::string, std::set, std::map, std::pair;

    using std::cin, std::cout, std::endl;

    using std::min, std::max, std::sort, std::reverse, std::abs, std::pow;


    // alias

    using ll = long long int;

    using ld = long double;

    using Pa = pair<int, int>;

    using Pall = pair<ll, ll>;

    using ibool = std::int8_t;

    template <class T>

    using uset = std::unordered_set<T>;

    template <class S, class T>

    using umap = std::unordered_map<S, T>;

    }  // namespace bys


    namespace bys::geo {

    const ld EPS = 1e-9;

    const ld PI = std::acos(-1.0);

    const ld TAU = PI * 2;

    int sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }

    bool isclose(ld a, ld b) { return sgn(a - b) == 0; }

    ld radian(ld degree) { return degree * (PI / 180.0); }

    ld degree(ld theta) { return theta * (180.0 / PI); }

    }  // namespace bys::geo

    '
  code: '#pragma once

    #include "../core/stdlib.hpp"


    namespace bys::geo {

    const ld EPS = 1e-9;

    const ld PI = std::acos(-1.0);

    const ld TAU = PI * 2;

    int sgn(ld a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }

    bool isclose(ld a, ld b) { return sgn(a - b) == 0; }

    ld radian(ld degree) { return degree * (PI / 180.0); }

    ld degree(ld theta) { return theta * (180.0 / PI); }

    }  // namespace bys::geo

    '
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: geometry/base.hpp
  requiredBy:
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/polygon.hpp
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/area.test.cpp
  - test/geometry/counter_clockwise.test.cpp
  - test/geometry/reflection.test.cpp
  - test/geometry/parallel_orthogonal.test.cpp
  - test/geometry/distance.test.cpp
  - test/geometry/is_convex.test.cpp
  - test/geometry/projection.test.cpp
  - test/geometry/intersection.test.cpp
  - test/geometry/cross_point.test.cpp
documentation_of: geometry/base.hpp
layout: document
redirect_from:
- /library/geometry/base.hpp
- /library/geometry/base.hpp.html
title: geometry/base.hpp
---
