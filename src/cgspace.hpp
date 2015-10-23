#ifndef __CGSPACE_HPP
#define __CGSPACE_HPP

#include <vector>
#include <map>
#include <set>
#include "vector3d.hpp"
#include "molecule.hpp"

class CGSpace {
public:

    using bond_pair = Molecule::bond_pair;

    CGSpace();
    void add_molecule(const Molecule& molecule);
    bool add_bond(std::size_t i, std::size_t j);
    Vector3d& coordinate(std::size_t index);
    const Vector3d& coordinate(std::size_t index) const;
    Vector3d& velocity(std::size_t index);
    const Vector3d& velocity(std::size_t index) const;
    BeadType type(std::size_t index) const;
    std::size_t num_beads() const;
    std::set<bond_pair> list_bonds() const;
    double& t();
    const double& t() const;

protected:
    std::vector<Vector3d> _coordinates;
    std::vector<Vector3d> _velocities;
    std::vector<BeadType> _types;
    std::set<bond_pair> _bonds;
    double _t;
};

#endif /* __CGSPACE_HPP*/
