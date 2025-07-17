#include "data.h"
#include <iostream>

int main() {
    printVersion();
    std::cout << "current version from main: " << data::version << "\n";

    return 0;
}
