#include <array>
#include <iostream>

struct Item {
    std::string_view name{};
    int gold{};
};

template <std::size_t N> void printItems(const std::array<Item, N>& items) {
    for (const auto item : items) {
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
    }
}

int main() {
    std::array<Item, 4> items{
        {{"sword", 5}, {"dagger", 3}, {"club", 2}, {"spear", 7}}
    };

    printItems(items);

    return 0;
}
