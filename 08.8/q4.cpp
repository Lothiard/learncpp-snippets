#include <iostream>

int main() {
    int outer{1};
    int xs{};
    while(outer <= 5) {
        xs = 5 - outer;
        while(xs > 0) {
            std::cout << "  ";
            --xs;
        }

        int num{outer};
        while(num > 0) {
            std::cout << num-- << " ";
        }
        std::cout << "\n";
        ++outer;
    }
    return 0;
}
