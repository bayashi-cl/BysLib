---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/util.hpp
    title: graph/util.hpp
  - icon: ':heavy_check_mark:'
    path: graphv2/lca.hpp
    title: graphv2/lca.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graphv2/lca.test.cpp
    title: test/graphv2/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - graphv2/lca.hpp
  - graph/util.hpp
  timestamp: '2022-01-20 13:40:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graphv2/lca.test.cpp
documentation_of: utility/fixpoint.hpp
layout: document
redirect_from:
- /library/utility/fixpoint.hpp
- /library/utility/fixpoint.hpp.html
title: utility/fixpoint.hpp
---
