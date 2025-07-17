#include <iostream>

template<int N>
int power(int x) {
    if(N == 0) return 1;

    int product{x};
    for(int i{1}; i < N; ++i) {
        product *= x;
    }

    return product;
}

int main() {
    int num = power<3>(2);
    std::cout << num << '\n';

    return 0;
}
