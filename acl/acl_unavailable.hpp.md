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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.12/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir], 'release': True}).decode()\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.12/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 189, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.12/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 404, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.12/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 263, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/math:\
    \ line -1: no such header\n"
  code: "#pragma once\n#define IGNORE\n#include <iostream>\n#include \"atcoder/math\"\
    \n#include \"atcoder/modint\"\n\nnamespace bys {\nusing atcoder::pow_mod, atcoder::inv_mod;\n\
    using mint = atcoder::modint998244353;\nusing mint7 = atcoder::modint1000000007;\n\
    template <int MOD>\ninline std::istream& operator>>(std::istream& is, atcoder::static_modint<MOD>&\
    \ m) {\n    long long int n;\n    is >> n;\n    m = n;\n    return is;\n}\ntemplate\
    \ <int MOD>\ninline std::ostream& operator<<(std::ostream& os, const atcoder::static_modint<MOD>&\
    \ m) {\n    return os << m.val();\n}\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: acl/acl_unavailable.hpp
  requiredBy: []
  timestamp: '2022-01-07 02:52:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: acl/acl_unavailable.hpp
layout: document
redirect_from:
- /library/acl/acl_unavailable.hpp
- /library/acl/acl_unavailable.hpp.html
title: acl/acl_unavailable.hpp
---
