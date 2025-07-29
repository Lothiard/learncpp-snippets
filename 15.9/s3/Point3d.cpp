#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>

Point3d::Point3d(double x, double y, double z) :
    x_{x}, y_{y}, z_{z}
{}

void Point3d::moveByVector(const Vector3d& v) {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
}

void Point3d::print() const {
    std::cout << "Point(" << x_ << ", " << y_ << ", " << z_ << ")\n";
}
