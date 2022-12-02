---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: n-dimentional vector
    links: []
  bundledCode: "#include <vector>\n\nnamespace bys {\nnamespace impl {\ntemplate <typename\
    \ T, std::size_t N> struct NdVector { using type = std::vector<typename NdVector<T,\
    \ N - 1>::type>; };\ntemplate <typename T> struct NdVector<T, 1> { using type\
    \ = std::vector<T>; };\n\ntemplate <typename T, std::size_t N> auto ndvector(std::vector<size_t>&\
    \ shape, T const& fill_value) {\n    if constexpr (N == 1) {\n        return std::vector(shape[0],\
    \ fill_value);\n    } else {\n        std::size_t size = shape.back();\n     \
    \   shape.pop_back();\n        return std::vector(size, ndvector<T, N - 1>(shape,\
    \ fill_value));\n    }\n}\n}  // namespace impl\n\ntemplate <class T, std::size_t\
    \ N> using NdVector = typename impl::NdVector<T, N>::type;\n\n/**\n * @brief n-dimentional\
    \ vector\n *\n * @example auto v = ndvector({2, 3}, 4); // {{4, 4, 4}, {4, 4,\
    \ 4}}\n */\ntemplate <class S, class T, std::size_t N> auto ndvector(S const (&shape)[N],\
    \ T const& fill_value = T()) {\n    static_assert(N > 0);\n    std::vector<std::size_t>\
    \ shape_vec(std::crbegin(shape), std::crend(shape));\n    return impl::ndvector<T,\
    \ N>(shape_vec, fill_value);\n}\n}  // namespace bys\n"
  code: "#pragma once\n#include <vector>\n\nnamespace bys {\nnamespace impl {\ntemplate\
    \ <typename T, std::size_t N> struct NdVector { using type = std::vector<typename\
    \ NdVector<T, N - 1>::type>; };\ntemplate <typename T> struct NdVector<T, 1> {\
    \ using type = std::vector<T>; };\n\ntemplate <typename T, std::size_t N> auto\
    \ ndvector(std::vector<size_t>& shape, T const& fill_value) {\n    if constexpr\
    \ (N == 1) {\n        return std::vector(shape[0], fill_value);\n    } else {\n\
    \        std::size_t size = shape.back();\n        shape.pop_back();\n       \
    \ return std::vector(size, ndvector<T, N - 1>(shape, fill_value));\n    }\n}\n\
    }  // namespace impl\n\ntemplate <class T, std::size_t N> using NdVector = typename\
    \ impl::NdVector<T, N>::type;\n\n/**\n * @brief n-dimentional vector\n *\n * @example\
    \ auto v = ndvector({2, 3}, 4); // {{4, 4, 4}, {4, 4, 4}}\n */\ntemplate <class\
    \ S, class T, std::size_t N> auto ndvector(S const (&shape)[N], T const& fill_value\
    \ = T()) {\n    static_assert(N > 0);\n    std::vector<std::size_t> shape_vec(std::crbegin(shape),\
    \ std::crend(shape));\n    return impl::ndvector<T, N>(shape_vec, fill_value);\n\
    }\n}  // namespace bys\n"
  dependsOn: []
  isVerificationFile: false
  path: byslib/extension/ndvector.hpp
  requiredBy: []
  timestamp: '2022-11-30 18:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/extension/ndvector.hpp
layout: document
redirect_from:
- /library/byslib/extension/ndvector.hpp
- /library/byslib/extension/ndvector.hpp.html
title: n-dimentional vector
---
