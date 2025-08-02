#include <limits>
#include <vector>
#include <iostream>

template <typename T>
void printArray(const std::vector<T>& arr) {
    std::cout << "With array ( ";
    for(std::size_t i{}; i < arr.size() - 1; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[arr.size() - 1] << " ):\n";
}

template <typename T>
std::pair<std::size_t, T> max(const std::vector<T>& arr) {
    T max{ arr[0] };
    std::size_t ind{};
    for(std::size_t i{ 1 }; i < arr.size(); ++i) {
        if(arr[i] > max) {
            max = arr[i];
            ind = i;
        }
    }

    return std::make_pair(ind, max);
}

template <typename T>
std::pair<std::size_t, T> min(const std::vector<T>& arr) {
    T min{ arr[0] };
    std::size_t ind{};
    for(std::size_t i{ 1 }; i < arr.size(); ++i) {
        if(arr[i] < min) {
            min = arr[i];
            ind = i;
        }
    }

    return std::make_pair(ind, min);
}

int main() {
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    printArray(v1);
    auto v1_min{ min(v1) };
    std::cout << "The min element has index " << v1_min.first << " and value "
              << v1_min.second << '\n';
    auto v1_max{ max(v1) };
    std::cout << "The max element has index " << v1_max.first << " and value "
              << v1_max.second << '\n';

    printArray(v2);
    auto v2_min{ min(v2) };
    std::cout << "The min element has index " << v2_min.first << " and value "
              << v2_min.second << '\n';
    auto v2_max{ max(v2) };
    std::cout << "The max element has index " << v2_max.first << " and value "
              << v2_max.second << '\n';

    std::vector<int> v3{};
    std::cout << "Enter numbers to add (use -1 to stop): ";
    while(true) {
        int input{};
        std::cin >> input;
        if(input == -1) break;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        v3.push_back(input);
    }

    if(!v3.size()) std::cout << "The array has no elements\n";
    else {
        auto v3_min{ min(v3) };
        std::cout << "The min element has index " << v3_min.first << " and value "
                  << v3_min.second << '\n';
        auto v3_max{ max(v3) };
        std::cout << "The max element has index " << v3_max.first << " and value "
                  << v3_max.second << '\n';
    }

    return 0;
}
