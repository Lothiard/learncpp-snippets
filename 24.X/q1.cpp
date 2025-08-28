#include <iostream>

class Fruit {
public:
    Fruit(std::string_view name, std::string_view color) :
        name_{name},
        color_{color} {}

    const std::string_view getName() const { return name_; }
    const std::string_view getColor() const { return color_; }

private:
    std::string name_{};
    std::string color_{};
};

class Apple : public Fruit {
public:
    Apple(std::string_view color = "red") : Fruit{"apple", color} {}

protected:
    Apple(std::string_view name, std::string_view color) : Fruit{name, color} {}
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple{"granny smith apple", "green"} {}
};

class Banana : public Fruit {
public:
    Banana() : Fruit{"banana", "yellow"} {}
};

int main() {
    Apple a{"red"};
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
