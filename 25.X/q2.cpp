#include <iostream>
#include <vector>

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

    int radius() const { return r_; }

    std::ostream& print(std::ostream& out) const override {
        return out << "Circle(" << o_ << ", radius " << r_;
    }
};

int getLargestRadius(const std::vector<Shape*>& shapes) {
    int max{};
    for (const auto* shape : shapes) {
        if (auto* circle{dynamic_cast<const Circle*>(shape)}) {
            max = std::max(max, circle->radius());
        }
    }
    return max;
}

int main() {
    std::vector<Shape*> v{new Circle{Point{1, 2}, 7},
                          new Triangle{Point{1, 2}, Point{3, 4}, Point{5, 6}},
                          new Circle{Point{7, 8}, 3}};

    // print each shape in vector v on its own line here
    for (const auto* shape : v) { std::cout << *shape << '\n'; }

    std::cout << "The largest radius is: " << getLargestRadius(v)
              << '\n'; // write this function

    // delete each element in the vector here
    for (const auto* shape : v) { delete shape; }

    return 0;

    return 0;
}
