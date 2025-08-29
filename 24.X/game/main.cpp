#include "Random.h"
#include "creature.h"
#include "monster.h"
#include "player.h"
#include <iostream>
#include <limits>

std::string askUsername() {
    std::cout << "Enter your name: ";
    std::string name{};
    std::cin >> name;
    std::cout << "Welcome, " << name << ".\n";
    return name;
}

char getChoice() {
    std::cout << "(R)un or (F)ight\n";
    std::string validChoices{"rRfF"};
    char input{};
    while (true) {
        std::cin >> input;

        if (validChoices.find(input) != std::string::npos) { break; }

        if (!std::cin) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }

    return input;
}

void takeDamage(Player& player, const Monster& monster) {
    player.reduceHealth(monster.damage());
    std::cout << monster.name() << " hit you for " << monster.damage()
              << " damage!\n";
}

void dealDamage(const Player& player, Monster& monster) {
    monster.reduceHealth(player.damage());
    std::cout << "You hit " << monster.name() << " for " << player.damage()
              << " damage!\n";
}

bool fight(Player& player, Monster& monster) {
    dealDamage(player, monster);
    if (monster.isDead()) {
        std::cout << "You killed " << monster.name() << '\n';
        player.levelUp();
        return true;
    }
    takeDamage(player, monster);
    return false;
}

bool run(Player& player, const Monster& monster) {
    bool success{static_cast<bool>(Random::get(0, 1))};
    if (success) {
        std::cout << "You successfully fled.\n";
        return true;
    } else {
        std::cout << "You failed to flee\n";
        takeDamage(player, monster);
        return false;
    }
}

void encounter(Player& player, Monster& monster) {
    std::cout << "You have encountered a " << monster.name() << " ("
              << monster.symbol() << ")\n";

    while (true) {
        char choice{getChoice()};

        switch (choice) {
        case 'f':
        case 'F': {
            if (fight(player, monster)) { return; }
            break;
        }
        case 'r':
        case 'R': {
            if (run(player, monster)) { return; }
            break;
        }
        }

        if (player.isDead()) { return; }
    }
}

void play(Player& player) {
    while (true) {
        Monster monster{Monster::getRandomMonster()};
        encounter(player, monster);

        if (player.hasWon()) {
            std::cout << "You won!\n";
            break;
        }
        if (player.isDead()) {
            std::cout << "You died!\n";
            break;
        }
    }
}

int main() {
    std::string_view name{askUsername()};
    Player player{name};

    play(player);

    return 0;
}
