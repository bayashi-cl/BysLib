---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: core/stdlib.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#ifndef LOCAL\n#define NDEBUG\n#endif\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <vector>\n\nnamespace bys\
    \ {\nusing std::array, std::vector, std::string, std::set, std::map, std::pair;\n\
    using std::cin, std::cout, std::endl;\nusing std::min, std::max, std::sort, std::reverse,\
    \ std::abs, std::pow;\n\n// alias\nusing ll = long long int;\nusing ld = long\
    \ double;\nusing Pa = pair<int, int>;\nusing Pall = pair<ll, ll>;\nusing ibool\
    \ = std::int8_t;\ntemplate <class T>\nusing uset = std::unordered_set<T>;\ntemplate\
    \ <class S, class T>\nusing umap = std::unordered_map<S, T>;\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T>\nstd::string zfill(const T& n, const\
    \ int width, char fill = '0') {\n    std::stringstream ss;\n    ss << std::setw(width)\
    \ << std::setfill(fill) << n;\n    return ss.str();\n}\nstd::vector<std::string>\
    \ split(std::string s, char delim) {\n    std::vector<std::string> res;\n    s.push_back(delim);\n\
    \    auto n = s.length();\n    std::size_t crr_left = 0;\n    for (std::size_t\
    \ i = 0; i < n; ++i) {\n        if (s[i] == delim) {\n            res.emplace_back(s.substr(crr_left,\
    \ i - crr_left));\n        }\n        crr_left = i + 1;\n    }\n    return res;\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include \"../core/stdlib.hpp\"\n\nnamespace bys {\ntemplate\
    \ <class T>\nstd::string zfill(const T& n, const int width, char fill = '0') {\n\
    \    std::stringstream ss;\n    ss << std::setw(width) << std::setfill(fill) <<\
    \ n;\n    return ss.str();\n}\nstd::vector<std::string> split(std::string s, char\
    \ delim) {\n    std::vector<std::string> res;\n    s.push_back(delim);\n    auto\
    \ n = s.length();\n    std::size_t crr_left = 0;\n    for (std::size_t i = 0;\
    \ i < n; ++i) {\n        if (s[i] == delim) {\n            res.emplace_back(s.substr(crr_left,\
    \ i - crr_left));\n        }\n        crr_left = i + 1;\n    }\n    return res;\n\
    }\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: string/zfill.hpp
  requiredBy: []
  timestamp: '2022-03-16 21:14:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/zfill.hpp
layout: document
redirect_from:
- /library/string/zfill.hpp
- /library/string/zfill.hpp.html
title: string/zfill.hpp
---
