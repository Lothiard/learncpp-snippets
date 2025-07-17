#include <iostream>

int calculate(int num1, int num2, char op);

int main() {
    std::cout << "Enter an integer: ";
    int num1{};
    std::cin >> num1;

    std::cout << "Enter another integer: ";
    int num2{};
    std::cin >> num2;

    std::cout << "Enter an operator: ";
    char op{};
    std::cin >> op;

    std::cout << "The result is: " << calculate(num1, num2, op) << "\n";

    return 0;
}

int calculate(int num1, int num2, char rem) {
    int result{};
    switch(rem) {
    case '+': {
        result = num1 + num2;
        break;
    }
    case '-': {
        result = num1 - num2;
        break;
    }
    case '*': {
        result = num1 * num2;
        break;
    }
    case '/': {
        result = num1 / num2;
        break;
    }
    default: {
        std::cout << "Invalid operator!\n";
        return 0;
    }
    }
    return result;
}
