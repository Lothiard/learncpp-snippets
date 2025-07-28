#include <iostream>

int input() {
    int input{};
    std::cout << "Enter an integer: ";
    std::cin >> input;
    return input;
}

int largerInput() {
    int input{};
    std::cout << "Enter a larger integer: ";
    std::cin >> input;
    return input;
}

int main() {
    int smaller{input()}, larger{largerInput()};

    if(smaller > larger) {
        std::cout << "Swapping the values\n";
        int temp{smaller};
        smaller = larger;
        larger = temp;
    } // temp dies here

    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';

    return 0;
}
