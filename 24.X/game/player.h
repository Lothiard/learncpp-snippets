#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player : public Creature {
public:
    Player(std::string_view name) : Creature(name, 10, 1, 0, '@') {}

    int level() const { return level_; }

    void levelUp() {
        ++damage_;
        ++level_;
    }
    bool hasWon() const { return level_ == 20; }

private:
    int level_{1};
};

#endif
