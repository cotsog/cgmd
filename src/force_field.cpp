#include "force_field.hpp"

bool BondingForceField::add_bond(const BeadType& type0, const BeadType& type1,
        double r, double k) {
    auto key(make_sorted_pair(type0, type1));
    if (_r_map.find(key) != _r_map.end())
        return false;
    if (_k_map.find(key) != _k_map.end())
        return false;

    _r_map.insert(make_pair(key, r));
    _k_map.insert(make_pair(key, k));

    return true;
}

double BondingForceField::get_r(const BeadType& type0, const BeadType& type1) const {
    auto key(make_sorted_pair(type0, type1));
    auto itr(_r_map.find(key));
    if (itr == _r_map.end())
        return 0.0; // Throwing the Exception is better.
    return (*itr).second;
}

double BondingForceField::get_k(const BeadType& type0, const BeadType& type1) const {
    auto key(make_sorted_pair(type0, type1));
    auto itr(_k_map.find(key));
    if (itr == _k_map.end())
        return 0.0; // Throwing the Exception is better.
    return (*itr).second;
}
