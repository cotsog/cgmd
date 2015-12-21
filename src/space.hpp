#ifndef __CGSPACE_HPP
#define __CGSPACE_HPP

#include <vector>
#include <map>
#include <set>
#include "vector3d.hpp"

class Space {
public:

    Space();
    Space(const std::size_t& size);
    void reset(const std::size_t& size);
    std::string& symbol(std::size_t index);
    const std::string& symbol(std::size_t index) const;
    Vector3d& coordinate(std::size_t index);
    const Vector3d& coordinate(std::size_t index) const;
    Vector3d& velocity(std::size_t index);
    const Vector3d& velocity(std::size_t index) const;
    std::size_t num_beads() const;
    double& t();
    const double& t() const;

protected:
    std::vector<std::string> _symbols;
    vector_list _coordinates;
    vector_list _velocities;
    double _t;
};

#endif /* __CGSPACE_HPP*/
