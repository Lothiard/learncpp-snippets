#include <cstring>
#include <iostream>

void printString(const char str[]) {
    while (*str != '\0') {
        std::cout << *str;
        ++str;
    }

    std::cout << '\n';
}

void printStringBackwards(const char str[]) {
    const char* begin{str};
    const char* end{str + strlen(str)};

    while (begin < end) { std::cout << *(--end); }

    std::cout << '\n';
}

int main() {
    const char str[]{"Hello, world!"};

    printString(str);
    printStringBackwards(str);
}
