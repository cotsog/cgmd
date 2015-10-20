#ifndef __MOLECULE_HPP
#define __MOLECULE_HPP

#include "vector3d.hpp"
#include <string>
#include <vector>

struct Molecule {
    Molecule();
    Molecule(std::size_t num_beads);

    std::size_t num_beads() const;
    Vector3d& coordinate(std::size_t index);
    std::string& type(std::size_t index);

protected:
    std::vector<Vector3d> _coordinates;
    std::vector<std::string> _types;
};

#endif /* __MOLECULE_HPP */
