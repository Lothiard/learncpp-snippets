#include <algorithm>
#include <iostream>

int main() {
    std::cout << "How many names would you like to enter? ";
    std::size_t n{};
    std::cin >> n;

    auto* names{new std::string[n]{}};
    for (std::size_t i{}; i < n; ++i) {
        std::cout << "Enter name #" << (i + 1) << ": ";
        getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + n);

    std::cout << "\nHere is your sorted list:\n";
    for (std::size_t i{}; i < n; ++i) {
        std::cout << "Name #" << (i + 1) << ": " << names[i] << '\n';
    }

    delete[] names;

    return 0;
}
