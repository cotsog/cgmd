#include "langevin_stepper.hpp"
#include "constants.hpp"

LangevinStepper::LangevinStepper() {
}

LangevinStepper::LangevinStepper(std::shared_ptr<CGSpace> space,
    std::shared_ptr<LangevinModel> model, std::mt19937 random_generator, double dt, double T) :
    _space(space), _model(model), _dist(0,1), _gen(random_generator), _dt(dt), _T(T) {
    const std::size_t num_beads(_space->num_beads());

    _acceleration_list = vector_list(num_beads, Vector3d(0,0,0));
    _deviation = std::vector<double>(num_beads);
    _const_term2 = std::vector<double>(num_beads);
    _const_term3 = std::vector<double>(num_beads);
    _const_term4 = std::vector<double>(num_beads);
    _mass_list = std::vector<double>(num_beads);

    for (std::size_t i(0); i < num_beads; ++i) {
        const BeadType type(_space->type(i));
        const double friction(_model->get_friction(type));
        const double mass(_model->get_mass(type));
        _deviation[i] = sqrt(2*friction*kB*_T/mass/_dt);
        _const_term2[i] = (1-friction*_dt/2)*(1-friction*_dt/2+pow(friction*dt/2,2));
        _const_term3[i] = _dt/2*(1-friction*_dt/2);
        _const_term4[i] = _dt*(1-friction*_dt/2);
        _mass_list[i] = mass;
    }
}

void LangevinStepper::step() {
    const std::size_t num_beads(_space->num_beads());

    // Update Coordinate
    for (std::size_t i(0); i < num_beads; ++i)
        _space->coordinate(i) += _space->velocity(i) * _const_term4.at(i)
            + _acceleration_list.at(i) * _dt*_dt/2;

    // Update Force
    vector_list force_list(num_beads, Vector3d(0,0,0));
    for (auto itr(_model->list_force_fields().begin()); itr != _model->list_force_fields().end(); ++itr)
        force_list += (*itr)->calculate_force(*(_space.get()));

    vector_list new_acceleration(num_beads, Vector3d(0,0,0));
    for (std::size_t i(0); i < num_beads; ++i) {
        new_acceleration[i] = force_list.at(i) / _mass_list.at(i)
            + get_unit_random_force() * _deviation.at(i);
    }

    // Update Velocity
    for (std::size_t i(0); i < num_beads; ++i)
        _space->velocity(i) = _space->velocity(i) * _const_term4.at(i)
            + (_acceleration_list.at(i) + new_acceleration.at(i)) * _const_term3.at(i);

    _space->t() += _dt;
}

double LangevinStepper::get_unit_white_noise() {
    return _dist(_gen);
}

Vector3d LangevinStepper::get_unit_random_force() {
    return Vector3d(
            get_unit_white_noise(),
            get_unit_white_noise(),
            get_unit_white_noise());
}
