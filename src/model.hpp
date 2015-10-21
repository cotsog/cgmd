#ifndef __MODEL_HPP
#define __MODEL_HPP

#include "bead_type.hpp"
#include <map>
#include <vector>

class LangevinModel {
public:
    void set_dt(double dt);
    bool add_bead(BeadType type, double mass, double friction);
    double get_dt() const;
    double get_mass(const BeadType& type) const;
    double get_friction(const BeadType& type) const;

protected:
    double _dt;
    std::map<BeadType, double> _mass;
    std::map<BeadType, double> _frictions;
};

#endif /* __MODEL_HPP */
