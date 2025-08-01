#include <iostream>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& val) {
    for(const auto& a : arr) {
        if(a == val) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<std::string_view> names{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string input{};
    std::cin >> input;

    bool isFound{ isValueInArray<std::string_view>(names, input) };

    if(!isFound) std::cout << input << " was not found.\n";
    else std::cout << input << " was found.\n";

    return 0;
}
