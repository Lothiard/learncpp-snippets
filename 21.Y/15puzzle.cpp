#include "board.h"
#include "direction.h"
#include "point.h"
#include "tile.h"
#include <cassert>
#include <iostream>
#include <limits>

namespace UserInput {
    Direction getCommandFromUser() {
        char input{};
        while (true) {
            std::cin >> input;
            switch (input) {
            case 'w': return Direction{Direction::Type::up};
            case 'a': return Direction{Direction::Type::left};
            case 's': return Direction{Direction::Type::down};
            case 'd': return Direction{Direction::Type::right};
            case 'q': return Direction{Direction::Type::maxDirections};
            default: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                break;
            }
            }
        }
    }
}

int main() {
    Board board{};
    std::cout << board;

    // while (true) {
    //     char input{UserInput::getCommandFromUser()};
    //     if (input == 'q') {
    //         std::cout << "\n\nBye!\n\n";
    //         break;
    //     } else {
    //         std::cout << "nice " << input << '\n';
    //     }
    // }

    std::cout << "Enter a command: ";
    while (true) {
        Direction input{UserInput::getCommandFromUser()};

        // Handle non-direction commands
        if (input.direction() == Direction::Type::maxDirections) {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        bool userMoved{board.moveTile(input)};
        if (userMoved) std::cout << board;
        else std::cout << "Unsopported direction was passed!";
    }
}
