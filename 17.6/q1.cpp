#include <array>
#include <iostream>

namespace Animal {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_type,
    };

    struct Data {
        std::string_view name{};
        int num_of_legs{};
        std::string_view sound{};
    };

    constexpr std::array types{chicken, dog, cat, elephant, duck, snake};
    constexpr std::array data{
        Data{ "chicken", 2, "cluck"},
        Data{     "dog", 4,  "woof"},
        Data{     "cat", 4,  "meow"},
        Data{"elephant", 4, "pawoo"},
        Data{    "duck", 2, "quack"},
        Data{   "snake", 0,  "hiss"},
    };

    static_assert(types.size() == max_type);
    static_assert(data.size() == max_type);
}

std::istream& operator>>(std::istream& in, Animal::Type& type) {
    std::string input{};
    std::getline(in >> std::ws, input);

    for (std::size_t i{}; i < Animal::max_type; ++i) {
        if (input == Animal::data[i].name) {
            type = static_cast<Animal::Type>(i);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}

void printAnimal(const Animal::Type& type) {
    const Animal::Data& animal{Animal::data[type]};
    std::cout << "A " << animal.name << " has " << animal.num_of_legs
              << " legs and says " << animal.sound << ".\n";
}

int main() {
    std::cout << "Enter an animal: ";
    Animal::Type input{};
    std::cin >> input;

    if (!std::cin) {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n";
        input = Animal::max_type;
    } else printAnimal(input);

    std::cout << "\nHere is the data for the rest of the animals:\n";

    for (const auto& animal : Animal::types) {
        if (animal != input) printAnimal(animal);
    }

    return 0;
}
