#ifndef POTION_H
#define POTION_H

#include "Random.h"
#include "player.h"
#include <iostream>

class Potion {
public:
    enum Size {
        small,
        normal,
        great,
        maxSize,
    };

    enum Type {
        health,
        strength,
        poision,
        maxType,
    };

    struct Effect {
        int healthDelta{};
        int strengthDelta{};
    };

    Potion(Size size, Type type) : size_{size}, type_{type} {}

    Size size() const { return size_; }
    Type type() const { return type_; }

    static constexpr Effect potionData[maxType][maxSize]{
        {{2, 0}, {3, 0}, {5, 0}},
        {{0, 1}, {0, 1}, {0, 2}},
        {{-1, 0}, {-1, 0}, {-1, -1}}};

    void drink(Player& player) {
        const Effect& effect{potionData[type_][size_]};
        if (effect.healthDelta > 0) {
            player.addHealth(effect.healthDelta);
            std::cout << "Health increased by " << effect.healthDelta << '\n';
        } else if (effect.healthDelta < 0) {
            player.reduceHealth(effect.healthDelta);
            std::cout << "Health decreased by " << std::abs(effect.healthDelta)
                      << '\n';
        }

        if (effect.strengthDelta) {
            player.addDamage(effect.strengthDelta);
            std::cout << "Damage increased by " << effect.strengthDelta << '\n';
        }
    }

    static Potion getRandomPotion() {
        return Potion{static_cast<Size>(Random::get(0, maxSize - 1)),
                      static_cast<Type>(Random::get(0, maxType - 1))};
    }

private:
    Size size_{};
    Type type_{};
};

#endif
