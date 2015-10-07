#ifndef __MY_STEP_LANGEVIN_HPP
#define __MY_STEP_LANGEVIN_HPP

#include <vector>
#include "vector3d.hpp"

/*
 * Using Verlet method
 */
class LangevinStepper {
public:
    LangevinStepper(double time_step, double temperature,
            std::vector<double> mass, std::vector<double> friction);
    void step();

protected:
    vector_list position;
    vector_list velocity;
    vector_list acceleration;

    std::vector<double> rlan_const1;
    std::vector<double> rlan_const2;
    std::vector<double> rlan_const3;
    std::vector<double> rlan_const4;
};

#endif /* __MY_STEP_LANGEVIN_HPP */
