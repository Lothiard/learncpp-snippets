#include <iostream>

// write your add function template here
template<typename T>
T add(T x, T y) {
    return x + y;
}

// write your mult function template here
template<typename T>
T mult(T x, int y) {
    return x * y;
}

// write your sub function template here
// template<typename T, typename U>
auto sub(auto x, auto y) {
    return x - y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
