#include <iostream>

class Fraction {
public:
    explicit Fraction(int n = 0, int d = 1) : numerator{ n }, denominator{ d } {}

    void getFraction() {
        std::cout << "Enter a value for numerator: ";
        std::cin >> numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> denominator;
        std::cout << '\n';
    }

    Fraction multiply(const Fraction& f) const {
        return Fraction{ numerator * f.numerator, denominator * f.denominator };
    }

    void printFraction() const {
        std::cout << numerator << '/' << denominator << '\n';
    }

private:
    int numerator{ 0 };
    int denominator{ 1 };
};

int main() {
    Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}
