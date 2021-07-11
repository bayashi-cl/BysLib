#ifndef BYS_INTEGER
#define BYS_INTEGER 1

#include "bys.hpp"

namespace bys {

template <typename T>
vector<T> make_divisor(T n) {
    vector<T> lower, upper;
    int i = 1;

    while (i * i <= n) {
        if (n % i == 0) {
            lower.push_back(i);
            if (i != n / i) upper.push_back(n / i);
        }
        ++i;
    }
    std::reverse(std::begin(upper), std::end(upper));
    std::copy(std::begin(upper), std::end(upper), std::back_inserter(lower));

    return lower;
}

struct MultiComb {
    int _n;
    int mod;
    vector<int> fact, factinv, inv;

    MultiComb(int n, int mod = MOD) : _n(n), mod(mod) {
        fact = {1, 1};
        factinv = {1, 1};
        inv = {0, 1};
        for (int i = 1; i <= n; i++) {
            fact.push_back(fact.back() * i % mod);
            inv.push_back((-inv[mod % i] * (mod / i)) % mod);
            factinv.push_back((factinv.back() * inv.back()) % mod);
        }
    }

    int comb(int n, int r) {
        if ((r < 0) || (n < r)) return 0;
        chmin(r, n - r);
        return fact[n] * factinv[r] * factinv[n - r] % mod;
    }
};

template <typename T>
vector<T> prime_factorize(T n) {
    vector<T> res;
    while (n % 2 == 0) {
        res.push_back(2);
        n /= 2;
    }
    T f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            res.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

}  // namespace bys

#endif
