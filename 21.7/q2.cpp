#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(const std::string& make, const std::string& model) :
        make_{make},
        model_{model} {}

    friend auto operator<=>(const Car& l, const Car& r) = default;
    friend std::ostream& operator<<(std::ostream& out, const Car& car);

private:
    std::string make_{};
    std::string model_{};
};

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << '(' << car.make_ << ", " << car.model_ << ')';
    return out;
}

int main() {
    std::vector<Car> cars{{"Toyota", "Corolla"},
                          {"Honda", "Accord"},
                          {"Toyota", "Camry"},
                          {"Honda", "Civic"}};

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}
