#include "board.h"
#include "tile.h"
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

int main() {
    Board board{};
    std::cout << board;

    while (true) {
        char input{UserInput::getCommandFromUser()};
        if (input == 'q') {
            std::cout << "\n\nBye!\n\n";
            break;
        } else {
            std::cout << "nice " << input << '\n';
        }
    }

    return 0;
}
