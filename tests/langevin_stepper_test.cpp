#include <gtest/gtest.h>
#include <memory>
#include <random>
#include "cgspace.hpp"
#include "model.hpp"
#include "langevin_stepper.hpp"

namespace {

class LangevinStepperTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        gen = std::mt19937(rnd());
        space = std::make_shared<CGSpace>();
        model = std::make_shared<LangevinModel>();
        stepper = LangevinStepper(space, model, gen,
                /* dt= */0.2, /* T= */200);
    }

    // virtual void TearDown() {}

    std::random_device rnd;
    std::mt19937 gen;
    std::shared_ptr<LangevinModel> model;
    std::shared_ptr<CGSpace> space;
    LangevinStepper stepper;
};

TEST_F(LangevinStepperTest, Step) {
    stepper.step();
    EXPECT_EQ(0.2, space->t());
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
