#include <vector>
#include <cassert>
#include <iostream>

namespace Animals {
    enum Animals {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    const std::vector<int> legs{ 2, 4, 4, 4, 2, 0 };
}

int main() {
    assert(std::size(Animals::legs) == Animals::max_animals);

    std::cout << "An elephant has " << Animals::legs[Animals::elephant] << " legs\n";

    return 0;
}
