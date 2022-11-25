#pragma once
#include <random>
#include <string>
#include <vector>

#include "../core/alias.hpp"
namespace bys {
/**
 * @brief ローリングハッシュ
 *
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 *
 */
class RollingHash {
    static constexpr u64 mod = (1UL << 61) - 1;
    static inline const u64 base = []() {
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        return engine();
    }();
    static inline std::vector<u64> base_pow = {1};

    std::vector<u64> _hash;

  public:
    RollingHash(std::string const& s) : _hash(s.length() + 1) {
        extend_base(s.length());
        for (std::size_t i = 0, n = s.length(); i < n; ++i) {
            _hash[i + 1] = modmul(_hash[i], base) + s[i] + 1;
            if (_hash[i + 1] >= mod) _hash[i + 1] -= mod;
        }
    }

    u64 hash(i32 l, i32 r) const {
        u64 res = mod + _hash[r] - modmul(_hash[l], base_pow[r - l]);
        return res < mod ? res : res - mod;
    }

  private:
    void extend_base(std::size_t n) {
        while (base_pow.size() < n) {
            base_pow.push_back(modmul(base_pow.back(), base));
        }
    }

    u64 modmul(i128 a, i128 b) const {
        i128 t = a * b;
        t = (t >> 61) + (t & mod);
        if (t >= mod) return t - mod;
        return t;
    }
};
}  // namespace bys
