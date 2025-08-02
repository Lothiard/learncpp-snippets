#include <vector>
#include <cassert>
#include <iostream>

namespace Items {
    enum Type {
        health_potion,
        torch,
        arrow,
        max_items,
    };
}

constexpr std::string_view printItem(const int item, const std::size_t index) {
    switch (index) {
        case 0: return (item > 1 ? "health potions" : "health potion");
        case 1: return (item > 1 ? "torches" : "torch");
        case 2: return (item > 1 ? "arrows" : "arrow");
    }
    return "???";
}

constexpr void printInventory(const std::vector<int>& inventory) {
    int totalItems{};
    for(std::size_t i{}; i < Items::max_items; ++i) {
        std::cout << "You have " << inventory[i] << " " << printItem(inventory[i], i) << '\n';
        totalItems += inventory[i];
    }
    std::cout << "You have " << totalItems << " total "
              << (totalItems > 1 ? "items" : "item") << "\n";
}


int main() {
    std::vector<int> inventory{ 1, 5, 10 };
    assert(Items::max_items == std::size(inventory));

    printInventory(inventory);

    return 0;
}
