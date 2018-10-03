#include <iostream>

namespace MyFraction {
  class Fraction {
  private:
    int numerator;
    int denominator;

    static int gcd(int a, int b);

    void normalize();

  public:
    Fraction();

    Fraction(int numerator, int denominator);

    int getNumerator() const;

    int getDenominator() const;

    Fraction operator++(int);

    Fraction operator--(int);

    Fraction& operator++();

    Fraction& operator--();

    Fraction& operator/=(const Fraction& other);

    Fraction& operator*=(const Fraction& other);

    Fraction& operator-=(const Fraction& other);

    Fraction& operator+=(const Fraction& other);

    friend Fraction operator-(const Fraction& fraction);

    friend Fraction operator+(const Fraction& fraction);

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);

    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator<(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator>(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator>=(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator<=(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator==(const Fraction& lhs, const Fraction& rhs);

    friend const bool operator!=(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
  };
}
