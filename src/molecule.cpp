#include "molecule.hpp"

Molecule::Molecule() {
    _coordinates = std::vector<Vector3d>();
    _types = std::vector<std::string>();
}

Molecule::Molecule(std::size_t num_beads) {
    _coordinates = std::vector<Vector3d>(num_beads, Vector3d());
    _types = std::vector<std::string>(num_beads, "");
}

std::size_t Molecule::num_beads() const {
    return _coordinates.size();
}

Vector3d& Molecule::coordinate(std::size_t index) {
    return _coordinates.at(index);
}

std::string& Molecule::type(std::size_t index) {
    return _types.at(index);
}
