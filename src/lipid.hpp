#ifndef __MY_LIPID_HPP
#define __MY_LIPID_HPP

#include <vector>
#include "vector3d.hpp"

struct Lipid {
    Lipid();
    Lipid(const std::size_t num_beads);
    Lipid(const Lipid &lipid);
    std::size_t num_beads() const;
    Vector3d& coordinate(std::size_t index);
    const Vector3d& coordinate(std::size_t index) const;
    Vector3d& velocity(std::size_t index);
    const Vector3d& velocity(std::size_t index) const;

protected:
    std::vector<Vector3d> _coordinate;
    std::vector<Vector3d> _velocity;
};

#endif /* __MY_LIPID_HPP */
