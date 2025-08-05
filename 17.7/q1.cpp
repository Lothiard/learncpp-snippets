#include <array>

int main() {
    constexpr std::array<int, 3> a{};
    constexpr int b[3]{};
}
