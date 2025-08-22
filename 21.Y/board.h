#ifndef BOARD_H
#define BOARD_H

#include "point.h"
#include "tile.h"
#include <array>

constexpr int consoleLines{25};

class Board {
public:
    Board();

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    static bool isValidTilePos(Point point) {
        return (point.x >= 0 && point.x < size_) &&
               (point.y >= 0 && point.y < size_);
    }

    Point getEmptyTilePos() const;
    void swapTiles(Point point1, Point point2);
    bool moveTile(Direction direction);

private:
    static constexpr int size_{4};
    std::array<std::array<Tile, size_>, size_> tiles_{};
};

#endif
