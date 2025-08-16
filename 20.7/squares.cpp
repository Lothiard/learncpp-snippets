#include "Random.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace settings {
    constexpr int mult_min{2};
    constexpr int mult_max{6};
}

std::vector<int> generateNumbers(int start, int amount, int multiplier) {
    std::vector<int> numbers(static_cast<std::size_t>(amount));
    for (int i{}; i < amount; ++i) {
        numbers[static_cast<std::size_t>(i)] =
            (start + i) * (start + i) * multiplier;
    }
    return numbers;
}

std::vector<int> setup() {
    std::cout << "Start where? ";
    int start{};
    std::cin >> start;

    std::cout << "How many? ";
    int amount{};
    std::cin >> amount;

    int multiplier{Random::get(settings::mult_min, settings::mult_max)};

    std::cout
        << "I generated " << amount
        << " square numbers. Do you know each number after multiplying it by "
        << multiplier << "?\n";

    return generateNumbers(start, amount, multiplier);
}

int getUserGuess() {
    std::cout << "> ";
    int guess{};
    std::cin >> guess;
    return guess;
}

bool findAndRemove(std::vector<int>& numbers, int guess) {
    auto found{std::find(numbers.begin(), numbers.end(), guess)};

    if (found == numbers.end()) { return false; }

    numbers.erase(found);
    return true;
}

int findClosest(const std::vector<int>& numbers, int guess) {
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) {
        return std::abs(a - guess) < std::abs(b - guess);
    });
}

void printFail(const std::vector<int>& numbers, int guess) {
    int closest{findClosest(numbers, guess)};

    std::cout << guess << " is wrong! Try " << closest << " next time.\n";
}

void printSuccess(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cout << "Nice! You found all numbers, good job!\n";
        return;
    }
    std::cout << "Nice! " << numbers.size() << " number(s) left.\n";
}

int main() {
    std::vector<int> numbers{setup()};

    while (true) {
        int guess{getUserGuess()};

        if (!findAndRemove(numbers, guess)) {
            printFail(numbers, guess);
            break;
        }

        printSuccess(numbers);
        if (numbers.empty()) { break; }
    }

    return 0;
}
