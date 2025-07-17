#include <iostream>

struct Fraction {
    int nominator{};
    int denominator{1};
};

Fraction readInput() {
    std::cout << "Enter the nominator: ";
    int nominator{};
    std::cin >> nominator;

    std::cout << "Enter the denominator: ";
    int denominator{};
    std::cin >> denominator;

    return {nominator, denominator};
}

Fraction multiply(const Fraction& f1, const Fraction& f2) {
    return {f1.nominator * f2.nominator, f1.denominator * f2.denominator};
}

std::ostream& operator<<(std::ostream& out, Fraction f) {
    out << f.nominator << "/" << f.denominator;
    return out;
}

int main() {
    Fraction f1{readInput()};
    Fraction f2{readInput()};

    std::cout << "The product of these fractions are: " << multiply(f1, f2) << "\n";

    return 0;
}
