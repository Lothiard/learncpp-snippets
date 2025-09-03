#include <iostream>
#include <stdexcept>

class Fraction {
public:
    Fraction() = default;
    Fraction(int numerator = 0, int denominator = 1) :
        numerator_{numerator},
        denominator_{denominator} {

        if (!denominator_) { throw std::runtime_error("Invalid denominator"); }
    }

    static Fraction getUserInput() {
        std::cout << "Enter the numerator: ";
        int numerator{};
        std::cin >> numerator;

        std::cout << "Enter the denominator: ";
        int denominator{};
        std::cin >> denominator;

        return Fraction{numerator, denominator};
    }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Fraction& fraction);

private:
    int numerator_{};
    int denominator_{1};
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    return out << fraction.numerator_ << '/' << fraction.denominator_;
}

int main() {
    try {
        Fraction legal{Fraction::getUserInput()};
        std::cout << legal << '\n';

        Fraction illegal{Fraction::getUserInput()};
        std::cout << illegal << '\n';
    } catch (const std::exception& exception) {
        std::cerr << exception.what() << '\n';
    }

    return 0;
}
