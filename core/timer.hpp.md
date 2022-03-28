---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Timer
    links: []
  bundledCode: "/**\n * @file timer.hpp\n * @author bayashi_cl\n * @brief Timer\n\
    \ */\n#include <chrono>\nnamespace bys {\nstruct Timer {\n    std::chrono::time_point<std::chrono::system_clock>\
    \ end;\n    Timer(int ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);\
    \ }\n    inline bool counting() const { return std::chrono::system_clock::now()\
    \ <= end; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n/**\n * @file timer.hpp\n * @author bayashi_cl\n * @brief Timer\n\
    \ */\n#include <chrono>\nnamespace bys {\nstruct Timer {\n    std::chrono::time_point<std::chrono::system_clock>\
    \ end;\n    Timer(int ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);\
    \ }\n    inline bool counting() const { return std::chrono::system_clock::now()\
    \ <= end; }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: core/timer.hpp
  requiredBy: []
  timestamp: '2022-03-28 23:40:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: core/timer.hpp
layout: document
redirect_from:
- /library/core/timer.hpp
- /library/core/timer.hpp.html
title: Timer
---
