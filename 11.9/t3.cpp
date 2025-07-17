#include <iostream>

template<int N>
void printSquares() {
    for (int i = 0; i <= N; ++i)
        std::cout << i * i << ' ';
    std::cout << '\n';
}

int main() {
    constexpr int limit = 5;
    printSquares<limit>(); // Error!
    printSquares<3>();     // Should work
    return 0;
}
