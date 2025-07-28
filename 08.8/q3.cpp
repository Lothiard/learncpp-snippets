#include <iostream>

int main() {
    int inner{5}, outer{5};
    while(outer > 0) {
        while(inner > 0) {
            std::cout << inner-- << " ";
        }
        std::cout << "\n";
        inner = --outer;
    }

    return 0;
}
