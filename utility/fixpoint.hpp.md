---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/util.hpp
    title: graph/util.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/fixpoint.hpp\"\n#include <utility>\nnamespace bys\
    \ {\ntemplate <typename F>\nstruct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)}\
    \ {}\n    template <typename... Args>\n    decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\ntemplate <typename F>\ninline FixPoint<std::decay_t<F>> fix(F&& f)\
    \ {\n    return std::forward<std::decay_t<F>>(f);\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <utility>\nnamespace bys {\ntemplate <typename F>\n\
    struct FixPoint : F {\n    FixPoint(F&& f) : F{std::forward<F>(f)} {}\n    template\
    \ <typename... Args>\n    decltype(auto) operator()(Args&&... args) const {\n\
    \        return F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\
    template <typename F>\ninline FixPoint<std::decay_t<F>> fix(F&& f) {\n    return\
    \ std::forward<std::decay_t<F>>(f);\n}\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/fixpoint.hpp
  requiredBy:
  - graph/util.hpp
  timestamp: '2022-01-20 13:40:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/fixpoint.hpp
layout: document
redirect_from:
- /library/utility/fixpoint.hpp
- /library/utility/fixpoint.hpp.html
title: utility/fixpoint.hpp
---
