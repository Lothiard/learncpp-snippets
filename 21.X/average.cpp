#include <cstdint>
#include <iostream>

class Average {
public:
    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
    Average& operator+=(std::int32_t value);

private:
    std::int32_t sum_{};
    int count_{};
};

std::ostream& operator<<(std::ostream& out, const Average& avg) {
    if (!avg.count_) {
        out << 0;
    } else {
        out << static_cast<double>(avg.sum_) / avg.count_;
    }
    return out;
}

Average& Average::operator+=(std::int32_t value) {
    this->sum_ += value;
    ++this->count_;
    return *this;
}

int main() {
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{avg};
    std::cout << copy << '\n';

    return 0;
}
