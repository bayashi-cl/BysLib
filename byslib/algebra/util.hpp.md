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
  bundledCode: "#include <cassert>\nnamespace bys {\ntemplate <class Monoid, class\
    \ T> typename Monoid::set_type pow_monoid(typename Monoid::set_type p, T q) {\n\
    \    assert(q >= 0);\n    auto res = Monoid::identity;\n    while (q > 0) {\n\
    \        if (q & 1) res = Monoid::operation(res, p);\n        p = Monoid::operation(p,\
    \ p);\n        q >>= 1;\n    }\n    return res;\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <cassert>\nnamespace bys {\ntemplate <class Monoid,\
    \ class T> typename Monoid::set_type pow_monoid(typename Monoid::set_type p, T\
    \ q) {\n    assert(q >= 0);\n    auto res = Monoid::identity;\n    while (q >\
    \ 0) {\n        if (q & 1) res = Monoid::operation(res, p);\n        p = Monoid::operation(p,\
    \ p);\n        q >>= 1;\n    }\n    return res;\n}\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/algebra/util.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/algebra/util.hpp
layout: document
redirect_from:
- /library/byslib/algebra/util.hpp
- /library/byslib/algebra/util.hpp.html
title: byslib/algebra/util.hpp
---
