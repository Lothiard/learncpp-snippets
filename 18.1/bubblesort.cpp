#include <iostream>

void dookie_bubblesort() {
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    const int length{static_cast<int>(std::size(array))};

    int comparisons{};
    int swaps{};

    for (int i{}; i < length - 1; ++i) {
        for (int j{1}; j < length; ++j) {
            if (array[j] < array[j - 1]) {
                std::swap(array[j], array[j - 1]);
                ++swaps;
            }
            ++comparisons;
        }
    }

    std::cout << "dookie sort\n\tcomparisons: " << comparisons
              << "\n\tswaps: " << swaps << "\n\n";

    for (const int num : array) { std::cout << num << ' '; }
    std::cout << '\n';
}

void chad_bubblesort() {
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    const int length{static_cast<int>(std::size(array))};

    int comparisons{};
    int swaps{};

    for (int i{}; i < length - 1; ++i) {
        bool done{true};
        for (int j{1}; j < length - i; ++j) {
            if (array[j] < array[j - 1]) {
                std::swap(array[j], array[j - 1]);
                ++swaps;
                done = false;
            }
            ++comparisons;
        }

        if (done) {
            std::cout << "Early termination on iteration " << i + 1 << '\n';
            break;
        }
    }

    std::cout << "chad sort\n\tcomparisons: " << comparisons
              << "\n\tswaps: " << swaps << "\n\n";

    for (const int num : array) { std::cout << num << ' '; }
    std::cout << '\n';
}

int main() {
    dookie_bubblesort();
    chad_bubblesort();

    return 0;
}
