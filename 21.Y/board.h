#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <array>

constexpr int consoleLines{25};

class Board {
public:
    Board();

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

private:
    static constexpr std::size_t size{4};
    std::array<std::array<Tile, size>, size> tiles{};
};

#endif
