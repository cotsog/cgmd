#include "cgspace.hpp"

CGSpace::CGSpace() {}

CGSpace::CGSpace(const std::size_t& size) {
    reset(size);
}

void CGSpace::reset(const std::size_t& size) {
    _coordinates = vector_list(size);
    _velocities = vector_list(size);
}

Vector3d& CGSpace::coordinate(std::size_t index) {
    return _coordinates.at(index);
}

const Vector3d& CGSpace::coordinate(std::size_t index) const {
    return _coordinates.at(index);
}

Vector3d& CGSpace::velocity(std::size_t index) {
    return _velocities.at(index);
}

const Vector3d& CGSpace::velocity(std::size_t index) const {
    return _velocities.at(index);
}

std::size_t CGSpace::num_beads() const {
    return _coordinates.size();
}

double& CGSpace::t() {
    return _t;
}

const double& CGSpace::t() const {
    return _t;
}
