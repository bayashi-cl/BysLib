#pragma once
#include <iostream>
#include <atcoder/math>
#include <atcoder/modint>

namespace bys {
using atcoder::pow_mod, atcoder::inv_mod;
using mint = atcoder::modint998244353;
using mint7 = atcoder::modint1000000007;
template <int MOD>
inline std::istream& operator>>(std::istream& is, atcoder::static_modint<MOD>& m) {
    long long int n;
    is >> n;
    m = n;
    return is;
}
template <typename T, typename std::enable_if_t<atcoder::internal::is_modint<T>::value, std::nullptr_t> = nullptr>
std::ostream& operator<<(std::ostream& os, const T& m) {
    return os << m.val();
}
}  // namespace bys
