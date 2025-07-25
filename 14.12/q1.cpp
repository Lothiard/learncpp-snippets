#include <iostream>

class Ball {
public:
    Ball(double radius) : Ball{ "black", radius } {}
    Ball(std::string_view color = "black", double radius = 10.0) :
        color_{ color },
        radius_{ radius }
    {
        std::cout << "Ball(" << color_ << ", " << radius_ << ")\n";
    }

private:
    std::string color_{ "black" };
    double radius_{ 10.0 };
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
