#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher {
public:
    Teacher(std::string_view name) : name_{name} {}

    const std::string_view getName() const { return name_; }

private:
    std::string name_{};
};

class Department {
public:
    Department() = default;
    void add(const Teacher& teacher) { teachers_.emplace_back(teacher); }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Department& department);

private:
    std::vector<std::reference_wrapper<const Teacher>> teachers_{};
};

std::ostream& operator<<(std::ostream& out, const Department& department) {
    out << "Department: ";
    for (const auto& teacher : department.teachers_) {
        out << teacher.get().getName() << ' ';
    }
    out << '\n';
    return out;
}

int main() {
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}
