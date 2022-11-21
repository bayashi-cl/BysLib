#pragma once
#include "modint.hpp"
namespace bys {
template <unsigned int Modulo>
struct ModFraction {
    using modint = ModInt<Modulo>;
    modint num, den;

    ModFraction() : num(0), den(1) {}
    template <class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
    ModFraction(T integer) : num(integer), den(1) {}
    template <class T, std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
    ModFraction(T numerator, T denominator) {
        assert(denominator != 0);

        auto g = std::gcd(numerator, denominator);
        num = numerator / g;
        den = denominator / g;
    }

    ModFraction(modint numerator, modint denominator) : num(numerator), den(denominator) {}

    ModFraction& operator+=(const ModFraction& other) {
        num = num * other.den + other.num * den;
        den = den * other.den;
        return *this;
    }
    ModFraction& operator-=(const ModFraction& other) {
        num = num * other.den - other.num * den;
        den = den * other.den;
        return *this;
    }
    ModFraction& operator*=(const ModFraction& other) {
        num *= other.num;
        den *= other.den;
        return *this;
    }

    modint val() const { return num / den; }

    friend ModFraction operator+(const ModFraction& lhs, const ModFraction& rhs) { return ModFraction(lhs) += rhs; }
    friend ModFraction operator-(const ModFraction& lhs, const ModFraction& rhs) { return ModFraction(lhs) -= rhs; }
    friend ModFraction operator*(const ModFraction& lhs, const ModFraction& rhs) { return ModFraction(lhs) *= rhs; }
    friend std::ostream& operator<<(std::ostream& os, const ModFraction& m) noexcept { return os << m.val(); }
};
using Mfrac = ModFraction<MOD>;
using Mfrac7 = ModFraction<MOD7>;
}  // namespace bys
