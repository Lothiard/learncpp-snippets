#include "monster.h"

static inline Creature monsterData[Monster::maxType] = {
    Creature{"dragon", 20, 4, 100, 'D'}, Creature{"orc", 4, 2, 25, 'o'},
    Creature{"slime", 1, 1, 10, 's'}};

Monster::Monster(Type type) : Creature(monsterData[type]) {}
