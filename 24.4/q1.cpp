#include <iostream>
#include <string>
#include <string_view>

class Fruit {
public:
    Fruit(std::string_view name, std::string_view color) :
        name_{name},
        color_{color} {}

    const std::string_view name() const { return name_; }
    const std::string_view color() const { return color_; }

private:
    std::string name_{};
    std::string color_{};
};

class Apple : public Fruit {
public:
    Apple(std::string_view name, std::string_view color, double fiber) :
        Fruit{name, color},
        fiber_{fiber} {}

    double fiber() const { return fiber_; }

private:
    double fiber_{};
};

std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << "Apple(" << apple.name() << ", " << apple.color() << ", "
        << apple.fiber() << ')';
    return out;
}

class Banana : public Fruit {
public:
    Banana(std::string_view name, std::string_view color) :
        Fruit(name, color) {}
};

std::ostream& operator<<(std::ostream& out, const Banana& banana) {
    out << "Banana(" << banana.name() << ", " << banana.color() << ')';
    return out;
}

int main() {
    const Apple a{"Red delicious", "red", 4.2};
    std::cout << a << '\n';

    const Banana b{"Cavendish", "yellow"};
    std::cout << b << '\n';

    return 0;
}
