#ifndef __MOLECULE_HPP
#define __MOLECULE_HPP

#include "vector3d.hpp"
#include "bead_type.hpp"
#include <vector>
#include <set>

struct Molecule {

    using bond_pair = std::pair<std::size_t, std::size_t>;

    Molecule();
    Molecule(std::size_t num_beads);

    std::size_t num_beads() const;
    Vector3d& coordinate(std::size_t index);
    const Vector3d& coordinate(std::size_t index) const;
    BeadType& type(std::size_t index);
    const BeadType& type(std::size_t index) const;
    void add_bond(std::size_t i, std::size_t j);
    std::set<bond_pair> list_bonds() const;

protected:
    std::vector<Vector3d> _coordinates;
    std::vector<BeadType> _types;
    std::set<bond_pair> _bonds;
};

#endif /* __MOLECULE_HPP */
