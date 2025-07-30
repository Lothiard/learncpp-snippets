#include <iostream>
#include <vector>

int main() {
    std::vector<char> hello{ 'h', 'e', 'l', 'l', 'o' };

    std::cout << "The array has " << std::size(hello) << " elements.\n";
    std::cout << hello[1] << hello.at(1) << '\n';

    return 0;
}
