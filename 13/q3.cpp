#include <iostream>

template<typename T>
struct Triad {
    T first{};
    T second{};
    T third{};
};

// for the C++17 homies
template<typename T>
Triad(T, T, T) -> Triad<T>;

template<typename T>
void print(T triad) {
    std::cout << "[" << triad.first << ", " << triad.second << ", " << triad.third << "]";
}

int main() {
    Triad t1{ 1, 2, 3 };
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };
    print(t2);

    return 0;
}
