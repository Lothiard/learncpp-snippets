#include "tile.h"

Tile::Tile(int num) : num_{num} {};

bool Tile::isEmpty() const { return !num_; }

int Tile::getNum() const { return num_; }

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
    if (tile.getNum() > 9) {
        out << " " << tile.getNum() << " ";
    } else if (tile.getNum()) {
        out << "  " << tile.getNum() << " ";
    } else {
        out << "   ";
    }

    return out;
}
