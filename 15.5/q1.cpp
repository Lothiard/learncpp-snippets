#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad {
public:
    Triad (const T& first, const U& second, const V& third) :
        first_{ first },
        second_{ second },
        third_{ third }
    {}

    const T& first() const { return first_; }
    const U& second() const { return second_; }
    const V& third() const { return third_; }

    void print() const;

private:
    T first_{};
    U second_{};
    V third_{};
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const {
    std::cout << '[' << first() << ", " << second() << ", "
              << third() << ']';
}

int main() {
    Triad<int, int, int> t1{ 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{ 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}
