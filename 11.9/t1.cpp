#include <iostream>

template<typename T, std::size_t N>
void printArray(const T (&arr)[N]) {
    for(std::size_t i{}; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    int iArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char cArr[5] = {'a', 'b', 'c', 'd', 'e'};

    printArray(iArr);
    printArray(cArr);

    return 0;
}
