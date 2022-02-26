---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "core/stdlib.hpp"

    #ifndef LOCAL

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

    #line 3 "string/ascii.hpp"

    namespace bys {

    const string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";

    const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    }  // namespace bys

    '
  code: '#pragma once

    #include "../core/stdlib.hpp"

    namespace bys {

    const string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";

    const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    }  // namespace bys

    '
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: string/ascii.hpp
  requiredBy: []
  timestamp: '2022-02-09 20:16:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/ascii.hpp
layout: document
redirect_from:
- /library/string/ascii.hpp
- /library/string/ascii.hpp.html
title: string/ascii.hpp
---
