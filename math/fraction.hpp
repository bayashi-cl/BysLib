#pragma once
#include "../core/stdlib.hpp"
/**
 * @file fraction.hpp
 * @brief Fraction
 */
namespace bys {
//! @brief 有理数
struct Fraction {
    // numerator / denominator
    ll numerator, denominator;
    Fraction() : numerator(0), denominator(1) {}
    Fraction(ll num, ll den) {
        assert(den != 0);
        if (num == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            if (den < 0) num *= -1;
            ll g = std::gcd(num, den);
            numerator = num;
            denominator = den;
            reduction();
        }
    }
    bool reduction() {
        ll g = std::gcd(numerator, denominator);
        if (g == 1) return false;
        numerator /= g;
        denominator /= g;
        return true;
    }
    operator ld() const { return (ld)numerator / denominator; }
    Fraction operator+(const Fraction& rh) const {
        return Fraction(numerator * rh.denominator + rh.numerator * denominator, denominator * rh.denominator);
    }
    Fraction operator+(const ll rh) const { return *this + Fraction(rh, 1); }
    Fraction operator+=(const Fraction& rh) {
        *this = *this + rh;
        return *this;
    }
    Fraction operator+=(const ll rh) {
        *this = *this + rh;
        return *this;
    }
    Fraction operator-(const Fraction& rh) const {
        return Fraction(numerator * rh.denominator - rh.numerator * denominator, denominator * rh.denominator);
    }
    Fraction operator-(const ll rh) const { return *this - Fraction(rh, 1); }
    Fraction operator-=(const Fraction& rh) {
        *this = *this - rh;
        return *this;
    }
    Fraction operator-=(const ll rh) {
        *this = *this - rh;
        return *this;
    }
    Fraction operator*(const Fraction& rh) const { return Fraction(numerator * rh.numerator, denominator * rh.denominator); }
    Fraction operator*(const ll rh) const { return Fraction(numerator * rh, denominator); }
    Fraction operator*=(const Fraction& rh) {
        *this = *this * rh;
        return *this;
    }
    Fraction operator*=(const ll rh) {
        *this = *this * rh;
        return *this;
    }
    Fraction operator/(const Fraction& rh) const { return Fraction(numerator * rh.denominator, denominator * rh.numerator); }
    Fraction operator/(const ll rh) const { return *this * Fraction(1, rh); }
    Fraction operator/=(const Fraction& rh) {
        *this = *this / rh;
        return *this;
    }
    Fraction operator/=(const ll rh) {
        *this = *this / rh;
        return *this;
    }
    bool operator<(const Fraction& rh) const { return numerator * rh.denominator < rh.numerator * denominator; }
};
std::ostream& operator<<(std::ostream& os, const Fraction& f) { return os << (ld)f; }
}  // namespace bys
