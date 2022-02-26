---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"core/timer.hpp\"\n#include <chrono>\n\nnamespace bys {\n\
    struct Timer {\n    std::chrono::time_point<std::chrono::system_clock> end;\n\
    \    Timer(int ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);\
    \ }\n    inline bool counting() const { return std::chrono::system_clock::now()\
    \ <= end; }\n};\n}  // namespace bys\n"
  code: "#pragma once\n#include <chrono>\n\nnamespace bys {\nstruct Timer {\n    std::chrono::time_point<std::chrono::system_clock>\
    \ end;\n    Timer(int ms) { end = std::chrono::system_clock::now() + std::chrono::milliseconds(ms);\
    \ }\n    inline bool counting() const { return std::chrono::system_clock::now()\
    \ <= end; }\n};\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: core/timer.hpp
  requiredBy: []
  timestamp: '2021-12-30 14:46:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: core/timer.hpp
layout: document
redirect_from:
- /library/core/timer.hpp
- /library/core/timer.hpp.html
title: core/timer.hpp
---
