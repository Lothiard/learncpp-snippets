#include <vector>
#include <iostream>

namespace Constants {
    const int askNum{ 3 };
}

std::vector<int> askUser();
int sum(std::vector<int> input);
int product(std::vector<int> input);

int main() {
    std::vector<int> input{ askUser() };
    std::cout << "The sum is " << sum(input) << '\n';
    std::cout << "The sum is " << product(input) << '\n';

    return 0;
}

std::vector<int> askUser() {
    std::cout << "Enter " << Constants::askNum << " integers: ";

    int num{};
    std::vector<int> result{};
    for(int i{}; i < Constants::askNum; ++i) {
        std::cin >> num;
        result.push_back(num);
    }

    return result;
}

int sum(std::vector<int> input) {
    int sum{};
    for(const int num : input) {
        sum += num;
    }

    return sum;
}

int product(std::vector<int> input) {
    int product{ 1 };
    for(const int num : input) {
        product *= num;
    }

    return product;
}

