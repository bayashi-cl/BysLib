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
  bundledCode: "#line 2 \"acl/acl.hpp\"\n#include <iostream>\n#include <atcoder/math>\n\
    #include <atcoder/modint>\n\nnamespace bys {\nusing atcoder::pow_mod, atcoder::inv_mod;\n\
    using mint = atcoder::modint998244353;\nusing mint7 = atcoder::modint1000000007;\n\
    template <int MOD>\ninline std::istream& operator>>(std::istream& is, atcoder::static_modint<MOD>&\
    \ m) {\n    long long int n;\n    is >> n;\n    m = n;\n    return is;\n}\ntemplate\
    \ <typename T, typename std::enable_if_t<atcoder::internal::is_modint<T>::value,\
    \ std::nullptr_t> = nullptr>\nstd::ostream& operator<<(std::ostream& os, const\
    \ T& m) {\n    return os << m.val();\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <iostream>\n#include <atcoder/math>\n#include <atcoder/modint>\n\
    \nnamespace bys {\nusing atcoder::pow_mod, atcoder::inv_mod;\nusing mint = atcoder::modint998244353;\n\
    using mint7 = atcoder::modint1000000007;\ntemplate <int MOD>\ninline std::istream&\
    \ operator>>(std::istream& is, atcoder::static_modint<MOD>& m) {\n    long long\
    \ int n;\n    is >> n;\n    m = n;\n    return is;\n}\ntemplate <typename T, typename\
    \ std::enable_if_t<atcoder::internal::is_modint<T>::value, std::nullptr_t> = nullptr>\n\
    std::ostream& operator<<(std::ostream& os, const T& m) {\n    return os << m.val();\n\
    }\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: acl/acl.hpp
  requiredBy: []
  timestamp: '2022-01-20 13:40:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: acl/acl.hpp
layout: document
redirect_from:
- /library/acl/acl.hpp
- /library/acl/acl.hpp.html
title: acl/acl.hpp
---