#include <iostream>

void fizzbuzz(int value);

int main() {
    fizzbuzz(150);

    return 0;
}

void fizzbuzz(int value) {
    for(int i{1}; i <= value; ++i) {
        if(i % 3 == 0) std::cout << "fizz";
        if(i % 5 == 0) std::cout << "buzz";
        if(i % 7 == 0) std::cout << "pop";
        if(i % 3 && i % 5 && i % 7) std::cout << i;

        std::cout << "\n";
    }
}

