#include <iostream>
#include <numeric>

class Fraction {
public:
    explicit Fraction(int numerator, int denominator) :
        numerator_{numerator},
        denominator_{denominator} {
        reduce();
    }

    void print() const {
        std::cout << numerator_ << '/' << denominator_ << '\n';
    }

    void reduce() {
        int gcd{std::gcd(numerator_, denominator_)};
        if (gcd) {
            numerator_ /= gcd;
            denominator_ /= gcd;
        }
    }

    friend Fraction operator*(const Fraction&, const int);
    friend Fraction operator*(const int, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);

private:
    int numerator_{};
    int denominator_{};
};

Fraction operator*(const Fraction& frac, const int mult) {
    return Fraction{frac.numerator_ * mult, frac.denominator_};
}

Fraction operator*(const int mult, const Fraction& frac) {
    return Fraction{frac.numerator_ * mult, frac.denominator_};
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2) {
    return Fraction{frac1.numerator_ * frac2.numerator_,
                    frac1.denominator_ * frac2.denominator_};
}

int main() {
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 2};
    f4.print();

    Fraction f5{2 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
