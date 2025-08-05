#include "Random.h"
#include <array>
#include <iostream>
#include <string_view>

namespace Constants {
    constexpr int min_gold{80};
    constexpr int max_gold{120};
}

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_type,
    };

    using namespace std::literals::string_view_literals;
    constexpr std::array costs{20, 30, 12, 50};
    constexpr std::array
        names{"Healing"sv, "Mana"sv, "Speed"sv, "Invisibility"sv};

    static_assert(costs.size() == max_type);
    static_assert(names.size() == max_type);
}

class Player {
public:
    explicit Player(std::string_view name) :
        name_{name},
        inventory_{},
        gold_{Random::get(Constants::min_gold, Constants::max_gold)} {
        std::cout << "Hello, " << name_ << " you have " << gold_
                  << " gold.\n\n";
    };

    constexpr std::array<int, Potion::max_type> inventory() const {
        return inventory_;
    }

    constexpr int gold() const { return gold_; }

    constexpr bool buy(Potion::Type type) {
        if (gold_ < Potion::costs[type]) { return false; }

        gold_ -= Potion::costs[type];
        ++inventory_[type];
        return true;
    }

private:
    std::string name_{};
    std::array<int, Potion::max_type> inventory_{};
    int gold_{};
};

constexpr std::string intro() {
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

Potion::Type select_potion() {
    std::cout
        << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    char answer{};

    while (true) {
        std::cin >> answer;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n') {
            std::cout << "I didn't understand what you said. Try again: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (answer == 'q') { return Potion::max_type; }

        int val{answer - '0'};
        if (val >= 0 || val < Potion::max_type) {
            return static_cast<Potion::Type>(val);
        }

        std::cout << "I didn't understand what you said. Try again: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

constexpr void shop(Player& player) {
    while (true) {
        std::cout << "Here is our selection for today:\n";
        for (std::size_t i{}; i < Potion::max_type; ++i) {
            std::cout << i << ") Potion of " << Potion::names[i] << " costs "
                      << Potion::costs[i] << '\n';
        }

        std::cout << '\n';

        Potion::Type answer{select_potion()};
        if (answer == Potion::max_type) return;

        bool success{player.buy(answer)};
        if (!success) {
            std::cout << "You can not afford that.\n\n";
        } else {
            std::cout << "You purchased a Potion of " << Potion::names[answer]
                      << ". You have " << player.gold() << " gold left.\n\n";
        }
    }
}

constexpr void outro(const Player& player) {
    std::cout << "\nYour inventory contains:\n";
    for (std::size_t i{}; i < Potion::max_type; ++i) {
        if (player.inventory()[i] > 0) {
            std::cout << player.inventory()[i] << "x potion of "
                      << Potion::names[i] << '\n';
        }
    }
    std::cout << "You escaped with " << player.gold() << " gold remaining.\n\n";
    std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
}

int main() {
    Player player{intro()};

    shop(player);

    outro(player);

    return 0;
}
