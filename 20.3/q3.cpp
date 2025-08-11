#include <iostream>

void binary(unsigned int n) {
    if (!n) return;
    binary(n / 2);
    std::cout << n % 2;
}

int main() {
    std::cout << "Enter a positive integer: ";
    unsigned int n{};
    std::cin >> n;
    std::cout << "Binary representation: ";
    binary(n);
    std::cout << '\n';

    return 0;
}
