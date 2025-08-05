#include <iostream>

namespace ProgramData {
    constexpr int perfectSquares[]{0, 1, 4, 9};
}

constexpr void printPerfectSquare(const int input) {
    for (const int num : ProgramData::perfectSquares) {
        if (num == input) {
            std::cout << input << " is a perfect square.\n\n";
            return;
        }
    }

    std::cout << input << " is not a perfect square.\n\n";
}

int main() {
    int input{};
    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> input;

        if (input == -1) {
            std::cout << "Bye\n";
            break;
        }

        printPerfectSquare(input);
    }

    return 0;
}
