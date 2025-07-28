#include <iostream>
#include <cmath>

class Point2d {
public:
    Point2d(double x = 0.0, double y = 0.0) : x_{ x }, y_{ y } {}

    void print() const {
        std::cout << "Point2d(" << x_ << ", " << y_ << ")\n";
    }

    double distanceTo(const Point2d& p) const {
        return std::sqrt((x_ - p.x_) * (x_ - p.x_) + (y_ - p.y_) * (y_ - p.y_));
    }

private:
    double x_{};
    double y_{};

};


int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
