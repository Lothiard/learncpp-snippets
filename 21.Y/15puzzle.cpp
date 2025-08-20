#include "board.h"
#include "direction.h"
#include "tile.h"
#include <cassert>
#include <iostream>
#include <limits>

namespace UserInput {
    char getCommandFromUser() {
        char input{};

        while (true) {
            std::cin >> input;
            switch (input) {
            case 'w': return 'w';
            case 'a': return 'a';
            case 's': return 's';
            case 'd': return 'd';
            case 'q': return 'q';
            default: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                break;
            }
            }
        }
    }
}

struct Point {
    int x{};
    int y{};

    friend bool operator==(Point left, Point right) {
        return left.x == right.x && left.y == right.y;
    }

    friend bool operator!=(Point left, Point right) { return !(left == right); }

    Point getAdjacentPoint(Direction direction) const {
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
};

int main() {
    // Board board{};
    // std::cout << board;
    //
    // while (true) {
    //     char input{UserInput::getCommandFromUser()};
    //     if (input == 'q') {
    //         std::cout << "\n\nBye!\n\n";
    //         break;
    //     } else {
    //         std::cout << "nice " << input << '\n';
    //     }
    // }

    std::cout << std::boolalpha;
    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{1, 0})
              << '\n';
    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{1, 2})
              << '\n';
    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{0, 1})
              << '\n';
    std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1})
              << '\n';
    std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
    std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
    std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';

    return 0;
}
