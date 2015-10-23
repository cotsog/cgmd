#ifndef __MODEL_HPP
#define __MODEL_HPP

#include "bead_type.hpp"
#include "force_field.hpp"
#include <map>
#include <vector>
#include <memory>

class LangevinModel {
public:
    using force_field_container = std::vector<std::shared_ptr<ForceField> >;

    void set_dt(double dt);
    bool add_bead(BeadType type, double mass, double friction);
    double get_dt() const;
    double get_mass(const BeadType& type) const;
    double get_friction(const BeadType& type) const;
    void add_force_field(std::shared_ptr<ForceField> ffield);
    const force_field_container& list_force_fields() const;

protected:
    double _dt;
    std::map<BeadType, double> _mass;
    std::map<BeadType, double> _frictions;
    force_field_container _force_fields;
};

#endif /* __MODEL_HPP */
