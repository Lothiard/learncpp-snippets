#ifndef VECTOR3D
#define VECTOR3D

#include "Point3d.h"

class Vector3d {
public:
    Vector3d(double x, double y, double z);

    void print() const;
    friend void Point3d::moveByVector(const Vector3d& v);

private:
    double x_{};
    double y_{};
    double z_{};
};

#endif
