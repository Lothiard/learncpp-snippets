#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2 {
public:
    explicit FixedPoint2(std::int16_t decimal = 0, std::int8_t fractional = 0);
    FixedPoint2(double num);

    explicit operator double() const;

    friend bool operator==(const FixedPoint2& left, const FixedPoint2& right);
    friend std::ostream& operator<<(std::ostream& out,
                                    const FixedPoint2& point);
    FixedPoint2 operator-() const;

    friend bool testDecimal(const FixedPoint2& fp);

private:
    std::int16_t decimal_{};
    std::int8_t fractional_{};
};

FixedPoint2::FixedPoint2(std::int16_t decimal, std::int8_t fractional) :
    decimal_{decimal},
    fractional_{fractional} {

    if (decimal_ < 0 || fractional_ < 0) {
        if (decimal_ > 0) { decimal_ = -decimal_; }
        if (fractional_ > 0) { fractional_ = -fractional_; }
    }

    decimal_ += fractional_ / 100;
    fractional_ %= 100;
};

FixedPoint2::FixedPoint2(double num) :
    FixedPoint2(static_cast<std::int16_t>(std::trunc(num)),
                static_cast<std::int8_t>(std::round(num * 100) -
                                         std::trunc(num) * 100)) {}

std::ostream& operator<<(std::ostream& out, FixedPoint2& point) {
    out << static_cast<double>(point);
    return out;
}

FixedPoint2::operator double() const { return decimal_ + fractional_ / 100.; }

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2& fp) {
    if (fp.decimal_ >= 0) {
        return fp.fractional_ >= 0 && fp.fractional_ < 100;
    } else {
        return fp.fractional_ <= 0 && fp.fractional_ > -100;
    }
}

bool operator==(const FixedPoint2& left, const FixedPoint2& right) {
    return (left.decimal_ == right.decimal_ &&
            left.fractional_ == right.fractional_);
}

std::istream& operator>>(std::istream& in, FixedPoint2& right) {
    double input{};
    in >> input;
    right = FixedPoint2{input};

    return in;
}

FixedPoint2 FixedPoint2::operator-() const {
    return FixedPoint2{-static_cast<double>(*this)};
}

FixedPoint2 operator+(const FixedPoint2& left, const FixedPoint2& right) {
    return FixedPoint2{static_cast<double>(left) + static_cast<double>(right)};
}

int main() {
    FixedPoint2 a{34, 56};
    std::cout << a << '\n';
    std::cout << static_cast<double>(a) << '\n';
    assert(static_cast<double>(a) == 34.56);

    FixedPoint2 b{-2, 8};
    assert(static_cast<double>(b) == -2.08);

    FixedPoint2 c{2, -8};
    assert(static_cast<double>(c) == -2.08);

    FixedPoint2 d{-2, -8};
    assert(static_cast<double>(d) == -2.08);

    FixedPoint2 e{0, -5};
    assert(static_cast<double>(e) == -0.05);

    FixedPoint2 f{0, 10};
    assert(static_cast<double>(f) == 0.1);

    FixedPoint2 g{1, 104};
    std::cout << g << '\n';
    std::cout << static_cast<double>(g) << '\n';
    assert(static_cast<double>(g) == 2.04);
    assert(testDecimal(g));

    FixedPoint2 h{1, -104};
    assert(static_cast<double>(h) == -2.04);
    assert(testDecimal(h));

    FixedPoint2 i{-1, 104};
    assert(static_cast<double>(i) == -2.04);
    assert(testDecimal(i));

    FixedPoint2 j{-1, -104};
    assert(static_cast<double>(j) == -2.04);
    assert(testDecimal(j));

    FixedPoint2 k{0.01};
    assert(static_cast<double>(k) == 0.01);

    FixedPoint2 l{-0.01};
    assert(static_cast<double>(l) == -0.01);

    FixedPoint2 m{1.9}; // make sure we handle single digit decimal
    assert(static_cast<double>(m) == 1.9);

    FixedPoint2 n{5.01}; // stored as 5.0099999... so we'll need to round this
    assert(static_cast<double>(n) == 5.01);

    FixedPoint2 o{-5.01}; // stored as -5.0099999... so we'll need to round this
    assert(static_cast<double>(o) == -5.01);

    // Handle case where the argument's decimal rounds to 100 (need to increase
    // base by 1)
    FixedPoint2 p{106.9978}; // should be stored with base 107 and decimal 0
    assert(static_cast<double>(p) == 107.0);

    // Handle case where the argument's decimal rounds to -100 (need to decrease
    // base by 1)
    FixedPoint2 q{-106.9978}; // should be stored with base -107 and decimal 0
    assert(static_cast<double>(q) == -107.0);

    assert(FixedPoint2{0.75} == FixedPoint2{0.75});    // Test equality true
    assert(!(FixedPoint2{0.75} == FixedPoint2{0.76})); // Test equality false

    // Test additional cases -- h/t to reader Sharjeel Safdar for these test
    // cases
    assert(FixedPoint2{0.75} + FixedPoint2{1.23} ==
           FixedPoint2{1.98}); // both positive, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{1.50} ==
           FixedPoint2{2.25}); // both positive, with decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} ==
           FixedPoint2{-1.98}); // both negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} ==
           FixedPoint2{-2.25}); // both negative, with decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.23} ==
           FixedPoint2{-0.48}); // second negative, no decimal overflow
    assert(FixedPoint2{0.75} + FixedPoint2{-1.50} ==
           FixedPoint2{-0.75}); // second negative, possible decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.23} ==
           FixedPoint2{0.48}); // first negative, no decimal overflow
    assert(FixedPoint2{-0.75} + FixedPoint2{1.50} ==
           FixedPoint2{0.75}); // first negative, possible decimal overflow

    FixedPoint2 r{-0.48};
    assert(static_cast<double>(r) == -0.48);
    assert(static_cast<double>(-r) == 0.48);

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> r;
    std::cout << "You entered: " << r << '\n';
    assert(static_cast<double>(r) == 5.68);

    return 0;
}
