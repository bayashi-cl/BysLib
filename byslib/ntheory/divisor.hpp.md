---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Divisor
    links: []
  bundledCode: "#include <algorithm>\n#include <iterator>\n#include <vector>\n/**\n\
    \ * @file divisor.hpp\n * @brief Divisor\n */\nnamespace bys {\n/**\n * @brief\
    \ \u7D04\u6570\u5217\u6319\n *\n * O(\u221An)\n */\ntemplate <typename T> std::vector<T>\
    \ make_divisor(T n) {\n    std::vector<T> lower, upper;\n    for (T i = 1; i *\
    \ i <= n; ++i) {\n        if (n % i == 0) {\n            lower.emplace_back(i);\n\
    \            if (T j = n / i; i != j) upper.emplace_back(j);\n        }\n    }\n\
    \    std::copy(upper.rbegin(), upper.rend(), std::back_inserter(lower));\n   \
    \ return lower;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\
    /**\n * @file divisor.hpp\n * @brief Divisor\n */\nnamespace bys {\n/**\n * @brief\
    \ \u7D04\u6570\u5217\u6319\n *\n * O(\u221An)\n */\ntemplate <typename T> std::vector<T>\
    \ make_divisor(T n) {\n    std::vector<T> lower, upper;\n    for (T i = 1; i *\
    \ i <= n; ++i) {\n        if (n % i == 0) {\n            lower.emplace_back(i);\n\
    \            if (T j = n / i; i != j) upper.emplace_back(j);\n        }\n    }\n\
    \    std::copy(upper.rbegin(), upper.rend(), std::back_inserter(lower));\n   \
    \ return lower;\n}\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/ntheory/divisor.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ntheory/divisor.hpp
layout: document
redirect_from:
- /library/byslib/ntheory/divisor.hpp
- /library/byslib/ntheory/divisor.hpp.html
title: Divisor
---
