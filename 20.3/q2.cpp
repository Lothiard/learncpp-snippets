#include <iostream>

int digits(int n) {
    if (n < 10) return n;
    return digits(n / 10) + n % 10;
}

int main() {
    std::cout << digits(93427) << '\n';

    return 0;
}
