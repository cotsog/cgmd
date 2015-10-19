#include "lipid.hpp"

Lipid::Lipid(const std::size_t num_beads) {
    _coordinate = std::vector<Vector3d>(num_beads);
    _velocity = std::vector<Vector3d>(num_beads);
}

Lipid::Lipid() {
    _coordinate = std::vector<Vector3d>();
    _velocity = std::vector<Vector3d>();
}

std::size_t Lipid::num_beads() const {
    return _coordinate.size();
}

Vector3d& Lipid::coordinate(std::size_t index) {
    return _coordinate.at(index);
}

const Vector3d& Lipid::coordinate(std::size_t index) const {
    return _coordinate.at(index);
}

Vector3d& Lipid::velocity(std::size_t index) {
    return _velocity.at(index);
}

const Vector3d& Lipid::velocity(std::size_t index) const {
    return _velocity.at(index);
}
