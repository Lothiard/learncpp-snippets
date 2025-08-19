#include "board.h"

Board::Board() {
    int value{1};
    for (std::size_t i{}; i < size * size - 1; ++i) {
        tiles[i / 4][i % 4] = Tile{value++};
    }
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i{}; i < consoleLines; ++i) { out << '\n'; }

    for (std::size_t i{}; i < board.size; ++i) {
        for (std::size_t j{}; j < board.size; ++j) { out << board.tiles[j][i]; }
        out << '\n';
    }

    return out;
}
