---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: core/stdlib.hpp
    title: STL Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Alphabet
    links: []
  bundledCode: "/**\n * @file ascii.hpp\n * @author bayashi_cl\n * @brief Alphabet\n\
    \ */\n/**\n * @file stdlib.hpp\n * @author bayashi_cl\n * @brief STL Template\n\
    \ */\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace bys {\nusing std::array, std::vector, std::string,\
    \ std::set, std::map, std::pair;\nusing std::cin, std::cout, std::endl;\nusing\
    \ std::min, std::max, std::sort, std::reverse, std::abs, std::pow;\n\n// alias\n\
    using ll = long long int;\nusing ld = long double;\nusing Pa = pair<int, int>;\n\
    using Pall = pair<ll, ll>;\nusing ibool = std::int8_t;\ntemplate <class T>\nusing\
    \ uset = std::unordered_set<T>;\ntemplate <class S, class T>\nusing umap = std::unordered_map<S,\
    \ T>;\n}  // namespace bys\nnamespace bys {\nconst string LOWERCASE = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst string UPPERCASE = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file ascii.hpp\n * @author bayashi_cl\n * @brief Alphabet\n\
    \ */\n#include \"../core/stdlib.hpp\"\nnamespace bys {\nconst string LOWERCASE\
    \ = \"abcdefghijklmnopqrstuvwxyz\";\nconst string UPPERCASE = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ;\n}  // namespace bys\n"
  dependsOn:
  - core/stdlib.hpp
  isVerificationFile: false
  path: string/ascii.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/ascii.hpp
layout: document
redirect_from:
- /library/string/ascii.hpp
- /library/string/ascii.hpp.html
title: Alphabet
---
