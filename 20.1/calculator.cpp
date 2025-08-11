#include <functional>
#include <iostream>

using ArithmeticFunction = std::function<int(int, int)>;

int getUserInt() {
    static int id{1};
    std::cout << "Enter integer #" << id++ << ": ";
    int num{};
    std::cin >> num;
    return num;
}

char getUserOperation() {
    std::string_view validOperations{"+-*/"};
    char operation{};

    do {
        std::cout << "\nEnter a mathematical operation (+, -, *, /): ";
        std::cin >> operation;
    } while (validOperations.find(operation) == std::string_view::npos);
    return operation;
}

int add(int num1, int num2) { return num1 + num2; }
int substract(int num1, int num2) { return num1 - num2; }
int multiply(int num1, int num2) { return num1 * num2; }
int divide(int num1, int num2) { return num1 / num2; }

ArithmeticFunction getArithmeticFunction(char operation) {
    switch (operation) {
    case '+': return &add;
    case '-': return &substract;
    case '*': return &multiply;
    case '/': return &divide;
    }
    return nullptr;
}

int main() {
    int num1{getUserInt()};
    int num2{getUserInt()};
    char operation{getUserOperation()};
    ArithmeticFunction func{getArithmeticFunction(operation)};
    if (func) {
        std::cout << num1 << ' ' << operation << ' ' << num2 << " = "
                  << func(num1, num2) << '\n';
    }

    return 0;
}
