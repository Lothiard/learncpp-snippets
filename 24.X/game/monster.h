#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

class Monster : public Creature {
public:
    enum Type {
        dragon,
        orc,
        slime,
        maxType,
    };

    Monster(Type type) : Creature(monsterData[type]) {}

private:
    Type type_{};

    static inline Creature monsterData[maxType] = {
        Creature{"dragon", 20, 4, 100, 'D'}, Creature{"orc", 4, 2, 25, 'o'},
        Creature{"slime", 1, 1, 10, 's'}};
};

#endif
