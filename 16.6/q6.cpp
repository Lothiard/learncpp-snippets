#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

namespace Constanst {
    const std::vector<int> divisors{ 3, 5, 7, 11, 13, 17, 19 };
    const std::vector<std::string_view> words{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
    const int number{ 150 };
}

void fizzbuzz() {
    assert(Constanst::divisors.size() == Constanst::words.size() && "Array sizes don't match\n");

    bool isDivisible{};
    for(int i{ 1 }; i <= Constanst::number; ++i) {
        isDivisible = false;
        for(std::size_t divisor{}; divisor < Constanst::divisors.size(); ++divisor) {
            if(i % static_cast<int>(Constanst::divisors[divisor]) == 0) {
                isDivisible = true;
                std::cout << Constanst::words[divisor];
            }
        }
        if(!isDivisible) std::cout << i;
        std::cout << '\n';
    }
}

int main() {
    fizzbuzz();

    return 0;
}
