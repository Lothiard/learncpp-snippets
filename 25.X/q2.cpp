#include <iostream>

class Shape {
public:
    virtual std::ostream& print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Shape& shape) {
        return shape.print(out);
    }
    virtual ~Shape() = default;
};

class Point {
private:
    int x_{};
    int y_{};

public:
    Point(int x, int y) : x_{x}, y_{y} {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        return out << "Point(" << p.x_ << ", " << p.y_ << ')';
    }
};

class Triangle : public Shape {
private:
    Point a_;
    Point b_;
    Point c_;

public:
    Triangle(const Point& a, const Point& b, const Point& c) :
        a_{a},
        b_{b},
        c_{c} {}

    std::ostream& print(std::ostream& out) const override {
        return out << "Triangle(" << a_ << ", " << b_ << ", " << c_ << ")";
    }
};

class Circle : public Shape {
private:
    Point o_;
    int r_{};

public:
    Circle(const Point& o, int r) : o_{o}, r_{r} {}

    std::ostream& print(std::ostream& out) const override {
        return out << "Circle(" << o_ << ", radius " << r_;
    }
};

int main() {
    Circle c{Point{1, 2}, 7};
    std::cout << c << '\n';

    Triangle t{Point{1, 2}, Point{3, 4}, Point{5, 6}};
    std::cout << t << '\n';

    return 0;
}
