#pragma once
#include <cassert>
#include <iostream>
#include <numeric>

#include "../core/alias.hpp"
/**
 * @file fraction.hpp
 * @brief Fraction
 */
namespace bys {
//! @brief 有理数
struct Fraction {
    // numerator / denominator
    i64 numerator, denominator;
    Fraction() : numerator(0), denominator(1) {}
    Fraction(i64 num, i64 den) {
        assert(den != 0);
        if (num == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            if (den < 0) num *= -1;
            numerator = num;
            denominator = den;
            reduction();
        }
    }
    bool reduction() {
        i64 g = std::gcd(numerator, denominator);
        if (g == 1) return false;
        numerator /= g;
        denominator /= g;
        return true;
    }
    operator f128() const { return (f128)numerator / denominator; }
    Fraction operator+(const Fraction& rh) const {
        return Fraction(numerator * rh.denominator + rh.numerator * denominator, denominator * rh.denominator);
    }
    Fraction operator+(const i64 rh) const { return *this + Fraction(rh, 1); }
    Fraction operator+=(const Fraction& rh) {
        *this = *this + rh;
        return *this;
    }
    Fraction operator+=(const i64 rh) {
        *this = *this + rh;
        return *this;
    }
    Fraction operator-(const Fraction& rh) const {
        return Fraction(numerator * rh.denominator - rh.numerator * denominator, denominator * rh.denominator);
    }
    Fraction operator-(const i64 rh) const { return *this - Fraction(rh, 1); }
    Fraction operator-=(const Fraction& rh) {
        *this = *this - rh;
        return *this;
    }
    Fraction operator-=(const i64 rh) {
        *this = *this - rh;
        return *this;
    }
    Fraction operator*(const Fraction& rh) const {
        return Fraction(numerator * rh.numerator, denominator * rh.denominator);
    }
    Fraction operator*(const i64 rh) const { return Fraction(numerator * rh, denominator); }
    Fraction operator*=(const Fraction& rh) {
        *this = *this * rh;
        return *this;
    }
    Fraction operator*=(const i64 rh) {
        *this = *this * rh;
        return *this;
    }
    Fraction operator/(const Fraction& rh) const {
        return Fraction(numerator * rh.denominator, denominator * rh.numerator);
    }
    Fraction operator/(const i64 rh) const { return *this * Fraction(1, rh); }
    Fraction operator/=(const Fraction& rh) {
        *this = *this / rh;
        return *this;
    }
    Fraction operator/=(const i64 rh) {
        *this = *this / rh;
        return *this;
    }
    bool operator<(const Fraction& rh) const { return numerator * rh.denominator < rh.numerator * denominator; }
};
std::ostream& operator<<(std::ostream& os, const Fraction& f) { return os << (f128)f; }
}  // namespace bys
