#ifndef __LANGEVIN_STEPPER_HPP
#define __LANGEVIN_STEPPER_HPP

#include <memory>
#include <random>
#include "space.hpp"
#include "model.hpp"

class Stepper {
public:
    virtual void step() = 0;
};

class LangevinStepper : public Stepper {
public:
    LangevinStepper();
    LangevinStepper(
        std::shared_ptr<Space> space,
        std::shared_ptr<Model> model,
        std::mt19937 random_generator,
        double dt, double T);
    virtual void step();

protected:

    double get_unit_white_noise();
    Vector3d get_unit_random_force();

    std::shared_ptr<Space> _space;
    std::shared_ptr<Model> _model;
    std::normal_distribution<> _dist;
    std::mt19937 _gen;
    double _dt;
    double _T;
    vector_list _acceleration_list;
    std::vector<double> _deviation;   // == rlan_const(1)
    std::vector<double> _const_term2; // == rlan_const(2)
    std::vector<double> _const_term3; // == rlan_const(3)
    std::vector<double> _const_term4; // == rlan_const(4)
    std::vector<double> _mass_list;
};

#endif /* __LANGEVIN_STEPPER_HPP */
