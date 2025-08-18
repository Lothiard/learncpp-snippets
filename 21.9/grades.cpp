#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade {
    std::string name{};
    char grade{};
};

class GradeMap {
public:
    char& operator[](std::string_view name);

private:
    std::vector<StudentGrade> map_{};
};

char& GradeMap::operator[](std::string_view name) {
    auto found{
        std::find_if(map_.begin(), map_.end(), [name](const auto& student) {
            return name == student.name;
        })};
    if (found != map_.end()) { return found->grade; }
    return map_.emplace_back(std::string{name}).grade;
}

int main() {
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}
