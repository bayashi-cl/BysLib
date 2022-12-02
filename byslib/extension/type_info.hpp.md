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
  bundledCode: "#include <cxxabi.h>\n\n#include <string>\n#include <typeinfo>\n\n\
    namespace bys {\ntemplate <class T> std::string get_typename(T const& v) {\n \
    \   int status;\n    return abi::__cxa_demangle(typeid(v).name(), 0, 0, &status);\n\
    }\n}  // namespace bys\n"
  code: "#pragma once\n#include <cxxabi.h>\n\n#include <string>\n#include <typeinfo>\n\
    \nnamespace bys {\ntemplate <class T> std::string get_typename(T const& v) {\n\
    \    int status;\n    return abi::__cxa_demangle(typeid(v).name(), 0, 0, &status);\n\
    }\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/type_info.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/type_info.hpp
layout: document
redirect_from:
- /library/byslib/extension/type_info.hpp
- /library/byslib/extension/type_info.hpp.html
title: byslib/extension/type_info.hpp
---
