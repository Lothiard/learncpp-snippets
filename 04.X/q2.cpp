#include <iostream>

double getNumber() {
    std::cout << "Enter a double value: ";
    double input{};
    std::cin >> input;
    return input;
}

char getOperator() {
    std::cout << "Enter +, -, * or /: ";
    char input{};
    std::cin >> input;
    return input;
}

void print(double one, double two, char op) {
    double result{};
    if(op == '+') result = one + two;
    else if (op == '-') result = one - two;
    else if (op == '*') result = one * two;
    else if (op == '/') result = one / two;
    else return;
    std::cout << one << " " << op << " " << two << " is " << result << '\n';
}

int main() {
    double one{getNumber()};
    double two{getNumber()};
    char op{getOperator()};
    print(one, two, op);

    return 0;
}
