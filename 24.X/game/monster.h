#ifndef MONSTER_H
#define MONSTER_H

#include "Random.h"
#include "creature.h"

class Monster : public Creature {
public:
    enum Type {
        dragon,
        orc,
        slime,
        maxType,
    };

    Monster(Type);

    static Monster getRandomMonster() {
        return Monster{static_cast<Type>(Random::get(0, maxType - 1))};
    }
};

#endif
