---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: byslib/core/int_alias.hpp
    title: byslib/core/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#include <limits>\n#include <memory>\n#include <type_traits>\n#include\
    \ <cstdint>\nnamespace bys {\nusing i8 = std::int8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    using u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\nusing u128 = __uint128_t;\nusing f32 = float;\nusing\
    \ f64 = double;\nusing f128 = long double;\n\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n\n#define DEFINE_NUM_LITERAL(name, type) \\\n    constexpr\
    \ auto operator\"\" name(unsigned long long x) { return static_cast<type>(x);\
    \ }\n\nDEFINE_NUM_LITERAL(_i8, std::int8_t);\nDEFINE_NUM_LITERAL(_i16, std::int16_t);\n\
    DEFINE_NUM_LITERAL(_i32, std::int32_t);\nDEFINE_NUM_LITERAL(_i64, std::int64_t);\n\
    DEFINE_NUM_LITERAL(_i128, __int128_t);\nDEFINE_NUM_LITERAL(_u8, std::uint8_t);\n\
    DEFINE_NUM_LITERAL(_u16, std::uint16_t);\nDEFINE_NUM_LITERAL(_u32, std::uint32_t);\n\
    DEFINE_NUM_LITERAL(_u64, std::uint64_t);\nDEFINE_NUM_LITERAL(_u128, __uint128_t);\n\
    DEFINE_NUM_LITERAL(_z, std::size_t);\n#undef DEFINE_NUM_LITERAL\n}  // namespace\
    \ bys\n\nnamespace bys {\ntemplate <class T> class BinaryTrie {\n    static_assert(std::is_integral_v<T>,\
    \ \"T is not integral\");\n    static constexpr i32 B = std::numeric_limits<T>::digits;\n\
    \n    struct Node;\n    using Ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        Ptr left, right;\n        i32 count = 0;\n    };\n\n    Ptr root;\n\
    \n    Ptr add(Ptr now, T val, i32 b) {\n        if (not now) now = std::make_shared<Node>();\n\
    \        now->count += 1;\n        if (b >= 0) {\n            if ((val >> b) &\
    \ (T)1) {\n                now->left = add(now->left, val, b - 1);\n         \
    \   } else {\n                now->right = add(now->right, val, b - 1);\n    \
    \        }\n        }\n        return now;\n    }\n\n    Ptr sub(Ptr now, T val,\
    \ i32 b) {\n        if (not now) return nullptr;\n        now->count -= 1;\n \
    \       if (now->count == 0) return nullptr;\n        if (b >= 0) {\n        \
    \    if ((val >> b) & (T)1) {\n                now->left = sub(now->left, val,\
    \ b - 1);\n            } else {\n                now->right = sub(now->right,\
    \ val, b - 1);\n            }\n        }\n        return now;\n    }\n\n  public:\n\
    \    BinaryTrie() {}\n    void insert(T x) { root = add(root, x, B - 1); }\n \
    \   auto erase(T x) { root = sub(root, x, B - 1); }\n\n    // auto bisect_left();\n\
    \    // auto bisect_right();\n\n    bool contain(T val) const {\n        if (not\
    \ root) return false;\n\n        Ptr now = root;\n        for (i32 i = B - 1;\
    \ i >= 0; --i) {\n            now = (val >> i) & (T)1 ? now->left : now->right;\n\
    \            if (not now) return false;\n        }\n        return true;\n   \
    \ }\n    i32 count(T val) const {\n        if (not root) return 0;\n\n       \
    \ Ptr now = root;\n        for (i32 i = B - 1; i >= 0; --i) {\n            now\
    \ = (val >> i) & (T)1 ? now->left : now->right;\n            if (not now) return\
    \ 0;\n        }\n        return now->count;\n    }\n    std::size_t size() const\
    \ noexcept { return root ? root->count : 0; }\n    std::ptrdiff_t ssize() const\
    \ noexcept { return root ? root->count : 0; }\n    // auto operator[]();\n};\n\
    }  // namespace bys\n"
  code: "#pragma once\n#include <limits>\n#include <memory>\n#include <type_traits>\n\
    #include \"../core/int_alias.hpp\"\n\nnamespace bys {\ntemplate <class T> class\
    \ BinaryTrie {\n    static_assert(std::is_integral_v<T>, \"T is not integral\"\
    );\n    static constexpr i32 B = std::numeric_limits<T>::digits;\n\n    struct\
    \ Node;\n    using Ptr = std::shared_ptr<Node>;\n\n    struct Node {\n       \
    \ Ptr left, right;\n        i32 count = 0;\n    };\n\n    Ptr root;\n\n    Ptr\
    \ add(Ptr now, T val, i32 b) {\n        if (not now) now = std::make_shared<Node>();\n\
    \        now->count += 1;\n        if (b >= 0) {\n            if ((val >> b) &\
    \ (T)1) {\n                now->left = add(now->left, val, b - 1);\n         \
    \   } else {\n                now->right = add(now->right, val, b - 1);\n    \
    \        }\n        }\n        return now;\n    }\n\n    Ptr sub(Ptr now, T val,\
    \ i32 b) {\n        if (not now) return nullptr;\n        now->count -= 1;\n \
    \       if (now->count == 0) return nullptr;\n        if (b >= 0) {\n        \
    \    if ((val >> b) & (T)1) {\n                now->left = sub(now->left, val,\
    \ b - 1);\n            } else {\n                now->right = sub(now->right,\
    \ val, b - 1);\n            }\n        }\n        return now;\n    }\n\n  public:\n\
    \    BinaryTrie() {}\n    void insert(T x) { root = add(root, x, B - 1); }\n \
    \   auto erase(T x) { root = sub(root, x, B - 1); }\n\n    // auto bisect_left();\n\
    \    // auto bisect_right();\n\n    bool contain(T val) const {\n        if (not\
    \ root) return false;\n\n        Ptr now = root;\n        for (i32 i = B - 1;\
    \ i >= 0; --i) {\n            now = (val >> i) & (T)1 ? now->left : now->right;\n\
    \            if (not now) return false;\n        }\n        return true;\n   \
    \ }\n    i32 count(T val) const {\n        if (not root) return 0;\n\n       \
    \ Ptr now = root;\n        for (i32 i = B - 1; i >= 0; --i) {\n            now\
    \ = (val >> i) & (T)1 ? now->left : now->right;\n            if (not now) return\
    \ 0;\n        }\n        return now->count;\n    }\n    std::size_t size() const\
    \ noexcept { return root ? root->count : 0; }\n    std::ptrdiff_t ssize() const\
    \ noexcept { return root ? root->count : 0; }\n    // auto operator[]();\n};\n\
    }  // namespace bys\n"
  dependsOn:
  - byslib/core/int_alias.hpp
  isVerificationFile: false
  path: byslib/ds/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-11-28 10:41:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: byslib/ds/binary_trie.hpp
layout: document
redirect_from:
- /library/byslib/ds/binary_trie.hpp
- /library/byslib/ds/binary_trie.hpp.html
title: byslib/ds/binary_trie.hpp
---
