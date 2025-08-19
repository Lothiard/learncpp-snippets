#include "direction.h"
#include "random.h"
#include <cassert>
#include <iostream>

Direction::Direction(Type direction) : direction_{direction} {};

Direction::Type Direction::direction() const { return direction_; }

Direction Direction::operator-() const {
    switch (direction()) {
    case up: return Direction{down};
    case down: return Direction{up};
    case left: return Direction{right};
    case right: return Direction{left};
    default: break;
    }

    assert(0 && "Unsopported direction!");
    return Direction{up};
}

std::ostream& operator<<(std::ostream& out, Direction& direction) {
    switch (direction.direction()) {
    case Direction::up: out << "up";
    case Direction::down: return out << "down";
    case Direction::left: return out << "left";
    case Direction::right: return out << "right";
    default: break;
    }

    return out;
}

static Direction getRandomDirection() {
    Direction::Type random{static_cast<Direction::Type>(
        Random::get(0, Direction::Type::maxDirections - 1))};
    return Direction{random};
}
