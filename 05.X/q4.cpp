#include <iostream>
#include <string>
#include <string_view>

std::string askName(int number) {
    std::cout << "Enter the name of the person #" << number << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int askAge(std::string_view name) {
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2) {
    if(age1 > age2) std::cout << name1 << " (" << age1 << ") is older than " << name2 << " (" << age2 << ").\n";
    else std::cout << name2 << " (" << age2 << ") is older than " << name1 << " (" << age1 << ").\n";
}

int main() {
    std::string name1 { askName(1) };
    int age1{ askAge(name1) };
    std::string name2 { askName(2) };
    int age2{ askAge(name2) };

    printOlder(name1, age1, name2, age2);

    return 0;
}

