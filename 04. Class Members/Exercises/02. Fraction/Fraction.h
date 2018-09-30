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

    Fraction& operator++();

    const Fraction operator++(int);

    Fraction& operator--();

    const Fraction operator--(int);

    Fraction& operator+(const Fraction& other);

    Fraction& operator-(const Fraction& other);

    Fraction& operator*(const Fraction& other);

    Fraction& operator/(const Fraction& other);

    Fraction& operator/=(const Fraction& other);

    Fraction& operator*=(const Fraction& other);

    Fraction& operator-=(const Fraction& other);

    Fraction& operator+=(const Fraction& other);

    bool operator<(const Fraction& other) const;

    bool operator>(const Fraction& other) const;

    bool operator>=(const Fraction& other) const;

    bool operator<=(const Fraction& other) const;

    bool operator==(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
  };
}
