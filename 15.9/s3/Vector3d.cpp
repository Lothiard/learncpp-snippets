#include "Vector3d.h"
#include <iostream>

Vector3d::Vector3d(double x, double y, double z) :
    x_{x}, y_{y}, z_{z}
{}

void Vector3d::print() const {
    std::cout << "Vector(" << x_ << ", " << y_ << ", " << z_ << ")\n";
}
