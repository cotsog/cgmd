#ifndef __MY_VECTOR3D_HPP
#define __MY_VECTOR3D_HPP

#include <vector>

struct Vector3d {
    double x;
    double y;
    double z;
    Vector3d(const double& X, const double& Y, const double& Z)
        : x(X), y(Y), z(Z) {}
    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(const Vector3d &vec)
        : x(vec.x), y(vec.y), z(vec.z) {}
};

bool operator==(const Vector3d& lhs, const Vector3d& rhs);

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs);
Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs);
Vector3d operator*(const Vector3d& lhs, const double& rhs);
Vector3d operator/(const Vector3d& lhs, const double& rhs);

double dot(const Vector3d& lhs, const Vector3d& rhs);
Vector3d cross(const Vector3d& lhs, const Vector3d& rhs);
double norm(const Vector3d& vec);

#endif /* __MY_VECTOR3D_HPP */
