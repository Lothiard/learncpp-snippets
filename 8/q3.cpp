#include "Random.h"
#include "hilo.h"
#include <iostream>

int main() {
    try_again:
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

    int guessNum{1};
    int guess{};
    bool isGuessed{};

    std::uniform_int_distribution range{Constants::lowerBound, Constants::upperBound};
    int hiddenNumber{range(Random::mt)};

    while(!isGuessed && guessNum <= Constants::maxTries) {
        std::cout << "Guess #" << guessNum << ": ";
        std::cin >> guess;

        if(calculateResult(guess, hiddenNumber)) {
            std::cout << "Correct! You win!\n";

            // spaghetti but was fun and i do not want to refactor
            end:
            std::cout << "Would you like to play again (y/n)? ";
            char answer{};
            bool isCorrect{};

            do {
                std::cin >> answer;
                if(answer == 'y' || answer == 'n') isCorrect = true;
                else std::cout << "Invalid answer! (y/n) ";
            } while(!isCorrect);

            if(answer == 'y') goto try_again;
            else {
                std::cout << "Thank you for playing\n";
                std::exit(0);
            }

        } else {
            ++guessNum;
        }
    }
    goto end;
    return 0;
}

bool calculateResult(int guess, int hiddenNumber) {
    if(guess < hiddenNumber) {
        std::cout << "Your guess is too low\n";
        return false;
    }
    if(guess > hiddenNumber) {
        std::cout << "Your guess is too high\n";
        return false;
    }
    return true;
}

