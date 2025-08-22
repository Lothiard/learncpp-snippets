#include "point.h"

bool operator==(Point left, Point right) {
    return left.x == right.x && left.y == right.y;
}

bool operator!=(Point left, Point right) { return !(left == right); }

Point Point::getAdjacentPoint(Direction direction) const {
    switch (direction.direction()) {
    case Direction::up: return Point{x, y - 1};
    case Direction::down: return Point{x, y + 1};
    case Direction::left: return Point{x - 1, y};
    case Direction::right: return Point{x + 1, y};
    default: break;
    }

    assert(0 && "Unsupported direction was passed!");
    return *this;
}
