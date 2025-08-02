#include "Random.h"
#include <cctype>
#include <ios>
#include <iostream>
#include <limits>
#include <bitset>

namespace Settings {
    constexpr int allowedWrongGuesses{ 6 };
}

namespace WordList {
    std::vector<std::string_view> words{
        "mystery", "broccoli", "account", "almost", "spaghetti", "opinion",
        "beautiful", "distance", "luggage"
    };

    std::string_view getRandomWord() {
        return words[(Random::get<std::size_t>(0, words.size() - 1))];
    }
}

class Session {
public:
    std::string_view getWord() const { return word_; }
    int getWrongGuessesLeft() const { return wrongGuessesLeft_; }

    void setLetterGuessed(char c) { lettersGuessed_[toIndex(c)] = true; }

    void removeGuess() { --wrongGuessesLeft_; }
    bool isLetterGuessed(char c) const { return lettersGuessed_[toIndex(c)]; }
    bool isLetterInWord(char c) const { return (word_.find(c) != std::string::npos); }
    bool won() const {
        for(const char c : word_) if(!isLetterGuessed(c)) return false;
        return true;
    }

private:
    const std::string_view word_{ WordList::getRandomWord() };
    int wrongGuessesLeft_{ Settings::allowedWrongGuesses };
    std::bitset<26> lettersGuessed_{};

    std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }
};

void printIntro() {
    std::cout << "Welcome to C++man (A variant of Hangman)\n";
    std::cout << "To win: guess the word.\tTo lose: run out of pluses.\n";
}

void printState(const Session& session) {
    std::cout << "\nThe word: ";
    for(const char c : session.getWord()) {
        if(session.isLetterGuessed(c)) std::cout << c;
        else std::cout << "_";
    }

    std::cout << "\tWrong guesses: ";
    for(int i{}; i < session.getWrongGuessesLeft(); ++i) std::cout << '+';
    for(char c{ 'a' }; c < 'z'; ++c) {
        if(session.isLetterGuessed(c) && !session.isLetterInWord(c)) {
            std::cout << c;
        }
    }

    std::cout << '\n';
}

char askGuess(const Session& session) {
    while(true) {
        std::cout << "Enter you next letter: ";
        char input{};
        std::cin >> input;

        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a valid input.\tTry again.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(!std::isalpha(input)) {
            std::cout << "That wasn't a valid input.\tTry again.\n";
            continue;
        }

        if(session.isLetterGuessed(input)) {
            std::cout << "You already guessed that.\tTry again.\n";
            continue;
        }

        return input;
    }
}

void handleGuess(Session& session, const char input) {
    session.setLetterGuessed(input);

    if(session.isLetterInWord(input)) {
        std::cout << "Yes, '" << input << "' is in the word!\n";
        return;
    } else {
        std::cout << "No, '" << input << "' is not in the word!\n";
        session.removeGuess();
    }
}

int main() {
    printIntro();
    Session session{};

    while(session.getWrongGuessesLeft() && !session.won()) {
        printState(session);
        char input{ askGuess(session) };
        handleGuess(session, input);
    }

    printState(session);

    if(!session.getWrongGuessesLeft()) {
        std::cout << "You lost!\tThe word was: " << session.getWord() << '\n';
    } else {
        std::cout << "You win!\n";
    }

    return 0;
}
