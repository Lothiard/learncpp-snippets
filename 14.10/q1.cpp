#include <iostream>

class Ball {
public:
    Ball(std::string_view color, double radius) :
        color_{ color },
        radius_{ radius }
    {}

    const std::string& getColor() const { return color_; }
    double getRadius() const { return radius_; }

private:
    std::string color_{};
    double radius_{};
};

void print(const Ball& ball) {
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main()
{
    Ball blue { "blue", 10.0 };
    print(blue);

    Ball red { "red", 12.0 };
    print(red);

    return 0;
}
