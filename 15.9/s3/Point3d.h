#ifndef POINT3D
#define POINT3D

class Vector3d;

class Point3d {
public:
    Point3d(double x, double y, double z);

    void print() const;
    void moveByVector(const Vector3d& v);

private:
    double x_{};
    double y_{};
    double z_{};
};

#endif
