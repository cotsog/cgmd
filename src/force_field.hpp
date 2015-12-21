#ifndef __FORCE_FIELD_HPP
#define __FORCE_FIELD_HPP

#include "vector3d.hpp"
#include "cgspace.hpp"
#include <vector>
#include <map>

class ForceField {
public:
    virtual double calculate_energy(const CGSpace& space) const = 0;
    virtual vector_list calculate_force(const CGSpace& space) const = 0;
};

class BondingForceField : public ForceField {
public:
    bool add_bond(const std::size_t& id0, const std::size_t& id1, double r, double k);
    double get_r(const std::size_t& id0, const std::size_t& id1) const;
    double get_k(const std::size_t& id0, const std::size_t& id1) const;
    virtual double calculate_energy(const CGSpace& space) const;
    virtual vector_list calculate_force(const CGSpace& space) const;

protected:
    std::map<std::pair<std::size_t, std::size_t>,
        std::pair<double, double> > _map;
};

std::pair<std::size_t, std::size_t> make_sorted_pair(
    const std::size_t& id0, const std::size_t& id1);

#endif /* __FORCE_FIELD_HPP */
