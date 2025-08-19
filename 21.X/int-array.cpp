#include <cassert>
#include <iostream>

class IntArray {
public:
    explicit IntArray(int size = 0);
    IntArray(const IntArray& other);
    ~IntArray();

    int& operator[](const int index);
    IntArray& operator=(const IntArray& other);
    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);

private:
    int* data_{};
    int size_{};
};

IntArray::IntArray(int size) : size_{size} {
    assert(size > 0 && "IntArray size should be a positive integer!");

    data_ = new int[static_cast<std::size_t>(size_)]{};
}

IntArray::IntArray(const IntArray& other) : size_{other.size_} {
    data_ = new int[static_cast<std::size_t>(size_)]{};
    for (int i{}; i < size_; ++i) { data_[i] = other.data_[i]; }
}

IntArray::~IntArray() { delete[] data_; }

int& IntArray::operator[](const int index) {
    assert(index >= 0);
    assert(index < size_);
    return data_[index];
}

IntArray& IntArray::operator=(const IntArray& other) {
    if (this == &other) { return *this; }

    delete[] data_;
    size_ = other.size_;

    data_ = new int[static_cast<std::size_t>(size_)]{};
    for (int i{}; i < size_; ++i) { data_[i] = other.data_[i]; }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const IntArray& arr) {
    for (int i{}; i < arr.size_; ++i) { out << arr.data_[i] << ' '; }
    return out;
}

IntArray fillArray() {
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main() {
    IntArray a{fillArray()};

    std::cout << a << '\n';

    auto& ref{a}; // we're using this reference to avoid compiler
                  // self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
