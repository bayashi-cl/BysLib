#pragma once
#include "../core/stdlib.hpp"
#include "bit.hpp"

namespace bys {
constexpr ll int_pow(int a, int b) {
    ll res = 1;
    for (int i = 0; i < b; ++i) res *= a;
    return res;
}
ll ceildiv(ll x, ll y) { return x > 0 ? (x + y - 1) / y : x / y; }
ll floordiv(ll x, ll y) { return x > 0 ? x / y : (x - y + 1) / y; }
pair<ll, ll> divmod(ll x, ll y) {
    ll q = floordiv(x, y);
    return {q, x - q * y};
}

ll isqrt_aux(ll c, ll n) {
    if (c == 0) return 1;
    ll k = (c - 1) / 2;
    ll a = isqrt_aux(c / 2, n >> (2 * k + 2));
    return (a << k) + (n >> (k + 2)) / a;
}
ll isqrt(ll n) {
    assert(n >= 0);
    if (n == 0) return 0;
    ll a = isqrt_aux((bit_length(n) - 1) / 2, n);
    return n < a * a ? a - 1 : a;
}
}  // namespace bys
