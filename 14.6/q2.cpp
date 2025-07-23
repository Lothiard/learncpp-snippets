#include <iostream>

class Point3d {
private:
    int x_{};
    int y_{};
    int z_{};

public:
    void setValues(int x, int y, int z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    void print() const {
        std::cout << "<" << x_ << ", " << y_ << ", " << z_ << ">";
    }

    bool isEqual(const Point3d& point) const {
        return (x_ == point.x_) && (y_ == point.y_) && (z_ == point.z_);
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
