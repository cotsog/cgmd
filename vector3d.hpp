#ifndef __MY_POINT_HPP
#define __MY_POINT_HPP

#include <vector>

struct Vector3d {
    const double x;
    const double y;
    const double z;
    Vector3d(const double& X, const double& Y, const double& Z)
        : x(X), y(Y), z(Z) {}
    Vector3d() : x(0), y(0), z(0) {}
};

using vector_list = std::vector<Vector3d>;

const Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs) {
    return Vector3d(lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z);
}

const Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs) {
    return Vector3d(lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z);
}

const Vector3d operator*(const Vector3d& lhs, const double& k) {
    return Vector3d(lhs.x*k, lhs.y*k, lhs.z*k);
}

double dot(const Vector3d& lhs, const Vector3d& rhs) {
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

const Vector3d cross(const Vector3d& lhs, const Vector3d& rhs) {
    return Vector3d(
            lhs.y*rhs.z-lhs.z*rhs.y,
            lhs.z*rhs.x-lhs.x*rhs.z,
            lhs.x*rhs.y-lhs.y*rhs.x);
}

#endif /* __MY_POINT_HPP */
