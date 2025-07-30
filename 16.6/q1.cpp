#include <ios>
#include <iostream>
#include <vector>
#include <limits>

template <typename T>
T askNumber(T min, T max) {
    T input{};
    do {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> input;

        if(!std::cin) std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(input < min || input > max);

    return input;
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for(std::size_t i{}; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
std::size_t search(T number, std::vector<T>& arr) {
    std::size_t i{};
    for(;i < arr.size(); ++i) {
        if(number == arr[i]) break;
    }
    return i;
}

template <typename T>
void printResult(T number, std::vector<T>& arr, std::size_t index) {
    std::cout << "The number " << number;
    if(index == arr.size()) std::cout << " was not found\n";
    else std::cout << " has index " << index << '\n';
}

int main() {
    auto input{ askNumber(0.0, 10.0) };
    // std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

    // printArray(arr);
    printArray(arr);

    std::size_t index{ search(input, arr) };
    // printResult(input, arr, index);
    printResult(input, arr, index);

    return 0;
}
