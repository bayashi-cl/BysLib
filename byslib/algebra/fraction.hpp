#pragma once
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>

#include "../core/int_alias.hpp"
/**
 * @file fraction.hpp
 * @brief Fraction
 */
namespace bys {
//! @brief 有理数
class Fraction {
    i64 numerator, denominator;

    bool reduction() {
        i64 g = std::gcd(numerator, denominator);
        if (g == 1) return false;
        numerator /= g;
        denominator /= g;
        return true;
    }

  public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(i64 integer) : numerator(integer), denominator(1) {}
    Fraction(i64 num, i64 den) : numerator(num), denominator(den) {
        assert(denominator != 0);
        if (numerator == 0) {
            denominator = 1;
        } else if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        reduction();
    }

    Fraction inv() const { return Fraction(denominator, numerator); }
    operator f128() const { return (f128)numerator / denominator; }
    std::pair<i64, i64> as_integer_ratio() { return {numerator, denominator}; }

    Fraction& operator+=(Fraction const& rhs) {
        numerator = numerator * rhs.denominator + rhs.numerator * denominator;
        denominator *= rhs.denominator;
        reduction();
    }
    Fraction& operator-=(Fraction const& rhs) {
        numerator = numerator * rhs.denominator - rhs.numerator * denominator;
        denominator *= rhs.denominator;
        reduction();
    }
    Fraction& operator*=(Fraction const& rhs) {
        numerator *= rhs.numerator;
        denominator *= rhs.denominator;
        reduction();
    }
    Fraction& operator/=(Fraction const& rhs) { *this *= rhs.inv(); }

    template <class T> friend Fraction operator+(Fraction const& rhs, Fraction const& lhs) {
        return Fraction(rhs) += lhs;
    }
    template <class T> friend Fraction operator-(Fraction const& rhs, Fraction const& lhs) {
        return Fraction(rhs) -= lhs;
    }
    template <class T> friend Fraction operator*(Fraction const& rhs, Fraction const& lhs) {
        return Fraction(rhs) *= lhs;
    }
    template <class T> friend Fraction operator/(Fraction const& rhs, Fraction const& lhs) {
        return Fraction(rhs) /= lhs;
    }

    Fraction operator+() const { return *this; }
    Fraction operator-() const { return Fraction(-numerator, denominator); }

    Fraction& operator++() { numerator += denominator; }
    Fraction& operator--() { numerator -= denominator; }

    Fraction operator++(int) {
        auto temp = *this;
        ++*this;
        return temp;
    }
    Fraction operator--(int) {
        auto temp = *this;
        --*this;
        return temp;
    }

    bool operator<(Fraction const& rhs) const {
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }
};
}  // namespace bys
