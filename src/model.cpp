#include "model.hpp"

void LangevinModel::set_dt(double dt) {
    _dt = dt;
}

bool LangevinModel::add_bead(BeadType type, double mass, double friction) {
    if (_mass.find(type) != _mass.end())
        return false;
    if (_frictions.find(type) != _frictions.end())
        return false;
    _mass.insert(std::pair<BeadType, double>(type, mass));
    _frictions.insert(std::pair<BeadType, double>(type ,friction));
    return true;
}

double LangevinModel::get_dt() const {
    return _dt;
}

double LangevinModel::get_mass(const BeadType& type) const {
    auto itr(_mass.find(type));
    if (itr == _mass.end())
        return 0.0; // Throwing the Exception is better.
    return (*itr).second;
}

double LangevinModel::get_friction(const BeadType& type) const {
    auto itr(_frictions.find(type));
    if (itr == _frictions.end())
        return 0.0; // Throwing the Exception is better.
    return (*itr).second;
}

