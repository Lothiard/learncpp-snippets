#include "students.h"
#include <iostream>

int main() {
    printMaxStudents();
    std::cout << "max students called from main: " << constants::max_students << "\n";

    return 0;
}
