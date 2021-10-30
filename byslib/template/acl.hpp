#pragma once
#include <atcoder/math>
#include <atcoder/modint>
#include <iostream>

namespace bys {
using atcoder::pow_mod, atcoder::inv_mod;
using mint = atcoder::modint998244353;
inline std::istream& operator>>(std::istream& is, mint& m) {
    long long int n;
    is >> n;
    m = n;
    return is;
}
inline std::ostream& operator<<(std::ostream& os, const mint& m) {
    return os << m.val();
}
}  // namespace bys
