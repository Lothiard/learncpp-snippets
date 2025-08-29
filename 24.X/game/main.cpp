#include "Random.h"
#include "monster.h"
#include "player.h"
#include "potion.h"
#include <array>
#include <cassert>
#include <iostream>
#include <limits>

static constexpr std::array<std::string_view, Potion::maxType> potionSizeString{
    "small", "normal", "great"};

static constexpr std::array<std::string_view, Potion::maxSize> potionTypeString{
    "health", "strength", "poision"};

std::string askUsername() {
    std::cout << "Enter your name: ";
    std::string name{};
    std::cin >> name;
    std::cout << "Welcome, " << name << ".\n";
    return name;
}

enum Context {
    runOrFight,
    drinkOrLeave,
    maxContext,
};

char getChoice(Context context) {
    std::string validChoices{};

    switch (context) {
    case runOrFight: {
        std::cout << "(R)un or (F)ight: ";
        validChoices = "rRfF";
        break;
    }
    case drinkOrLeave: {
        std::cout << "(D)rink or (L)eave: ";
        validChoices = "dDlL";
        break;
    }
    case maxContext: assert(false && "fatal error");
    }

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

void drop(Player& player) {
    Potion potion{Potion::getRandomPotion()};
    std::cout << "You found a potion of unknown effect!\n";
    char input{getChoice(drinkOrLeave)};

    switch (input) {
    case 'd':
    case 'D': {
        std::cout << "It was a " << potionSizeString[potion.size()]
                  << " potion of " << potionTypeString[potion.type()] << '\n';

        potion.drink(player);
        break;
    }
    case 'l':
    case 'L': {
        std::cout << "You decide to leave the potion and continue onwards\n";
        break;
    }
    }
}

bool fight(Player& player, Monster& monster) {
    dealDamage(player, monster);
    if (monster.isDead()) {
        std::cout << "You killed " << monster.name() << '\n';

        player.levelUp();
        std::cout << "You are now level " << player.level() << '\n';

        player.addGold(monster.gold());
        std::cout << "You found " << monster.gold() << " gold\n";

        if (Random::get(1, 10) < 3) { // 30%
            drop(player);
        }

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

    while (true) { // TODO: remove loop if redundant
        char choice{getChoice(runOrFight)};

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
    std::cout << "Reach level 20 to win!\n";
    while (true) {
        Monster monster{Monster::getRandomMonster()};
        encounter(player, monster);

        if (player.hasWon()) {
            std::cout << "You won!\n";
            std::cout << "You take home " << player.gold()
                      << " gold and all the aura\n";
            break;
        }
        if (player.isDead()) {
            std::cout << "You died!\n";
            std::cout << "You lost all your aura on level " << player.level()
                      << " with " << player.gold() << " gold\n";
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
