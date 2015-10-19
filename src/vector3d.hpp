#ifndef __MY_POINT_HPP
#define __MY_POINT_HPP

#include <vector>

struct Vector3d {
    double x;
    double y;
    double z;
    Vector3d(const double& X, const double& Y, const double& Z)
        : x(X), y(Y), z(Z) {}
    Vector3d() : x(0), y(0), z(0) {}
};

bool operator==(const Vector3d& lhs, const Vector3d& rhs);

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs);
Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs);
Vector3d operator*(const Vector3d& lhs, const double& rhs);

double dot(const Vector3d& lhs, const Vector3d& rhs);
Vector3d cross(const Vector3d& lhs, const Vector3d& rhs);

#endif /* __MY_POINT_HPP */
