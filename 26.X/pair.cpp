#include <iostream>

template <typename T>
class Pair1 {
public:
    Pair1(const T& first, const T& second) : first_{first}, second_{second} {}

    T& first() { return first_; }
    T& second() { return second_; }
    const T& first() const { return first_; }
    const T& second() const { return second_; }

private:
    T first_;
    T second_;
};

template <typename T, typename U>
class Pair {
public:
    Pair(const T& first, const U& second) : first_{first}, second_{second} {}

    T& first() { return first_; }
    U& second() { return second_; }
    const T& first() const { return first_; }
    const U& second() const { return second_; }

private:
    T first_;
    U second_;
};

template <typename T>
class StringValuePair : public Pair<std::string, T> {
public:
    StringValuePair(const std::string_view first, const T& second) :
        Pair<std::string, T>{static_cast<std::string>(first), second} {}
};

int main() {
    Pair1<int> p1{5, 8};
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2{2.3, 4.5};
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> p3{5, 6.7};
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4{2.3, 4};
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp{"Hello", 5};
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
