#ifndef POINT_H
#define POINT_H

#include "direction.h"
#include <cassert>

struct Point {
    int x{};
    int y{};

    friend bool operator==(Point left, Point right);
    friend bool operator!=(Point left, Point right);

    Point getAdjacentPoint(Direction direction) const;
};

#endif
