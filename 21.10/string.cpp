#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString {
public:
    MyString(std::string str) : str_{std::move(str)} {}

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    std::string_view operator()(std::size_t start, std::size_t length) const;

private:
    std::string str_{};
};

std::ostream& operator<<(std::ostream& out, const MyString& str) {
    out << str.str_;
    return out;
}

std::string_view MyString::operator()(std::size_t start,
                                      std::size_t length) const {
    assert(start + length <= str_.length());
    return std::string_view{str_}.substr(start, length);
}

int main() {
    MyString s{"Hello, world!"};
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
