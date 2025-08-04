#include <array>
#include <iostream>

int main() {
    [[maybe_unused]] std::array<double, 365> temperatures{};

    constexpr std::array hello{'h', 'e', 'l', 'l', 'o'};
    std::cout << hello[1] << '\n';

    return 0;
}
