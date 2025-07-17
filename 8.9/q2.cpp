#include <iostream>

int sumTo(int value);

int main() {
    std::cout << sumTo(5);

    return 0;
}

int sumTo(int value) {
    int result{};
    for(int i{1}; i <= value; ++i) result += i;
    return result;
}

