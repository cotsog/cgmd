#include "cgspace.hpp"

CGSpace::CGSpace() {}

void CGSpace::add_molecule(const Molecule& molecule) {
    const std::size_t origin(num_beads());

    for (std::size_t i(0); i < molecule.num_beads(); ++i) {
        _coordinates.push_back(molecule.coordinate(i));
        _velocities.push_back(Vector3d(0,0,0));
        _types.push_back(molecule.type(i));
    }

    std::set<Molecule::bond_pair> bonds(molecule.list_bonds());
    for (auto itr(bonds.begin()); itr != bonds.end(); ++itr) {
        add_bond((*itr).first, (*itr).second);
    }
}

bool CGSpace::add_bond(std::size_t i, std::size_t j) {
    if (i == j)
        return false;
    if (i >= num_beads() || j >= num_beads())
        return false;

    std::size_t small, large;
    if (i < j) {
        small = i;
        large = j;
    } else {
        small = j;
        large = i;
    }
    _bonds.insert(bond_pair(small, large));
    return true;
}

Vector3d& CGSpace::coordinate(std::size_t index) {
    return _coordinates.at(index);
}

Vector3d& CGSpace::velocity(std::size_t index) {
    return _velocities.at(index);
}

std::string CGSpace::type(std::size_t index) const {
    return _types.at(index);
}

std::size_t CGSpace::num_beads() const {
    return _coordinates.size();
}

std::set<CGSpace::bond_pair> CGSpace::list_bonds() const {
    return _bonds;
}
