#include "board.h"
#include <cassert>

Board::Board() {
    int value{1};
    for (std::size_t i{}; i < size_ * size_ - 1; ++i) {
        tiles_[i / 4][i % 4] = Tile{value++};
    }
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i{}; i < consoleLines; ++i) { out << '\n'; }

    for (std::size_t i{}; i < board.size_; ++i) {
        for (std::size_t j{}; j < board.size_; ++j) {
            out << board.tiles_[i][j];
        }
        out << '\n';
    }

    return out;
}

Point Board::getEmptyTilePos() const {
    for (int i{}; i < size_; ++i) {
        for (int j{}; j < size_; ++j) {
            if (tiles_[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)]
                    .isEmpty()) {
                return Point{j, i};
            }
        }
    }
    assert(0 && "There is no empty tile on the board!");
    return Point{-1, -1};
}

void Board::swapTiles(Point point1, Point point2) {
    std::swap(tiles_[static_cast<std::size_t>(point1.y)]
                    [static_cast<std::size_t>(point1.x)],
              tiles_[static_cast<std::size_t>(point2.y)]
                    [static_cast<std::size_t>(point2.x)]);
}

bool Board::moveTile(Direction direction) {
    Point empty{getEmptyTilePos()};
    Point adjacent{empty.getAdjacentPoint(-direction)};

    if (!isValidTilePos(empty)) { return false; }
    swapTiles(empty, adjacent);
    return true;
}
