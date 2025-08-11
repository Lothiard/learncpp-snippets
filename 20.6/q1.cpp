#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student {
    std::string name{};
    int points{};
};

std::array<Student, 8> students{{{"Albert", 3},
                                 {"Ben", 5},
                                 {"Christine", 2},
                                 {"Dan", 8}, // Dan has the most points (8).
                                 {"Enchilada", 4},
                                 {"Francis", 1},
                                 {"Greg", 3},
                                 {"Hagrid", 5}}};

int main() {
    auto best_student{std::max_element(
        students.begin(), students.end(),
        [](const auto& a, const auto& b) { return a.points < b.points; })};

    std::cout << best_student->name << " is the best student\n";

    return 0;
}
