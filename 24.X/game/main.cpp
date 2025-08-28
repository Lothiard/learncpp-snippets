#include "creature.h"
#include "monster.h"
#include "player.h"
#include <iostream>

std::string askUsername() {
    std::cout << "Enter your name: ";
    std::string name{};
    std::cin >> name;
    std::cout << "Welcome, " << name << ".\n";
    return name;
}

int main() {
    std::string_view name{askUsername()};
    Player player{name};

    std::cout << "You have " << player.health() << " health and are carrying "
              << player.gold() << " gold\n";

    for (int i{}; i < 10; ++i) {
        Monster m{Monster::getRandomMonster()};
        std::cout << "A " << m.name() << " (" << m.symbol()
                  << ") was created.\n";
    }

    return 0;
}
