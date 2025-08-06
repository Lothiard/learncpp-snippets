#include "Random.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>

namespace Settings {
    constexpr int bust{21};
    constexpr int dealer_stop{17};
}

struct Card {
    enum Rank {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,

        max_rank,
    };

    enum Suit {
        clubs,
        diamonds,
        hearts,
        spades,

        max_suit,
    };

    static constexpr std::array all_ranks{
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king
    };

    static constexpr std::array all_suits{clubs, diamonds, hearts, spades};

    Rank rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        static constexpr std::array ranks{
            'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
        };
        static constexpr std::array suits{'C', 'D', 'H', 'S'};

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    constexpr int value() const {
        static constexpr int rank_values[] = {
            11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
        };
        return rank_values[rank];
    }
};

class Deck {
public:
    Deck() {
        std::size_t index{};
        for (auto suit : Card::all_suits) {
            for (auto rank : Card::all_ranks) {
                cards_[index++] = Card{rank, suit};
            }
        }
    }

    Card dealCard() {
        assert(next_ < 52 && "Deck::dealCard ran out of cards\n");
        return cards_[next_++];
    }

    void shuffle() { std::shuffle(cards_.begin(), cards_.end(), Random::mt); }

private:
    std::array<Card, 52> cards_{};
    std::size_t next_{};
};

struct Player {
    int score{};
};

enum class Result {
    won,
    lost,
    tied,

    max_result,
};

char askInput() {
    char input{};
    while (true) {
        std::cin >> input;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "(h) to hit, (s) to stand: ";
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "(h) to hit, (s) to stand: ";
            continue;
        }

        if (input == 'h' || input == 's') { return input; }
    }
}

void handleAce(const Card& new_card, Player& player) {
    if (new_card.rank == Card::ace) {
        if (Settings::bust - player.score >= 11) {
            player.score += 11;
        } else {
            ++player.score;
        }
    } else {
        player.score += new_card.value();
    }
}

bool playersTurn(Player& player, Deck& deck) {
    while (true) {
        std::cout << "(h) to hit, (s) to stand: ";
        char choice{askInput()};

        if (choice == 's') { return true; }

        Card new_card{deck.dealCard()};
        handleAce(new_card, player);

        std::cout << "You were dealt " << new_card
                  << ". You now have: " << player.score << '\n';

        if (player.score > Settings::bust) {
            std::cout << "You went bust!\n";
            return false;
        }
    }
}

bool dealersTurn(Player& dealer, Deck& deck) {
    while (dealer.score <= Settings::dealer_stop) {
        Card new_card{deck.dealCard()};
        handleAce(new_card, dealer);

        std::cout << "The dealer flips a " << new_card << ". They now have "
                  << dealer.score << '\n';
    }

    if (dealer.score > Settings::bust) {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return false;
}

Result playBlackJack() {
    Player dealer{};
    Player player{};

    Deck deck{};
    deck.shuffle();

    Card dealer_first{deck.dealCard()};
    Card player_first{deck.dealCard()};

    dealer.score += dealer_first.value();
    player.score += player_first.value();

    std::cout << "The dealer is showing: " << dealer_first << " ("
              << dealer.score << ")\n";
    std::cout << "You have: " << player_first << " (" << player.score << ")\n";

    if (!playersTurn(player, deck)) { return Result::lost; }
    if (dealersTurn(dealer, deck)) { return Result::won; }

    if (player.score > dealer.score) return Result::won;
    if (player.score < dealer.score) return Result::lost;
    return Result::tied;
}

int main() {
    switch (playBlackJack()) {
    case Result::won: std::cout << "You win!\n"; break;
    case Result::lost: std::cout << "You lose!\n"; break;
    case Result::tied: std::cout << "It's a tie!\n"; break;
    default: std::cerr << "Unexpected result.\n"; return 1;
    }
    return 0;
}
