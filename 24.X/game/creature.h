#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
public:
    Creature(std::string_view name, int health, int damage, int gold,
             char symbol) :
        name_{name},
        health_{health},
        damage_{damage},
        gold_{gold},
        symbol_{symbol} {}

    const std::string& name() const { return name_; }
    int health() const { return health_; }
    int damage() const { return damage_; }
    int gold() const { return gold_; }
    char symbol() const { return symbol_; }

    void reduceHealth(int damage) { health_ -= damage; }
    void addHealth(int amount) { health_ += amount; }
    void addDamage(int amount) { damage_ += amount; }
    bool isDead() const { return health_ <= 0; }
    void addGold(int gold) { gold_ += gold; }

protected:
    std::string name_{};
    int health_{};
    int damage_{};
    int gold_{};
    char symbol_{};
};

#endif
