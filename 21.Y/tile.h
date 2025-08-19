#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile {
public:
    Tile() = default;
    explicit Tile(int value);
    bool isEmpty() const;
    int getNum() const;

    friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

private:
    int num_{};
};

#endif
