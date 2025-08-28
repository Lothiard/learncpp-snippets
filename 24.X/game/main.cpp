#include "creature.h"
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

    Creature o{"orc", 4, 2, 10, 'o'};
    o.addGold(5);
    o.reduceHealth(1);
    std::cout << "The " << o.name() << " has " << o.health()
              << " health and is carrying " << o.gold() << " gold.\n";

    return 0;
}
