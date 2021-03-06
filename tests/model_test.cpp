#include <gtest/gtest.h>
#include <memory>
#include "force_field.hpp"
#include "model.hpp"

namespace {

class ModelTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        model.set_dt(0.2);
        model.reset(2);
        model.set_property(0,/* mass= */1.0,/* friction= */0.4);
        model.set_property(1,/* mass= */1.5,/* friction= */0.3);
    }

    // virtual void TearDown() {}

    Model model;
};

TEST_F(ModelTest, TimeInterval) {
    EXPECT_EQ(0.2, model.get_dt());
    model.set_dt(0.5);
    EXPECT_EQ(0.5, model.get_dt());
}

TEST_F(ModelTest, Mass) {
    EXPECT_EQ(1.0, model.get_mass(0));
    EXPECT_EQ(1.5, model.get_mass(1));
}

TEST_F(ModelTest, Friction) {
    EXPECT_EQ(0.4, model.get_friction(0));
    EXPECT_EQ(0.3, model.get_friction(1));
}

TEST_F(ModelTest, Potential) {
    std::shared_ptr<BondingForceField> bfield(new BondingForceField());
    bfield->add_bond(0, 1,/* r= */ 0.5, /* k= */ 2.0);
    model.add_potential(bfield);
    EXPECT_EQ(1, model.list_potentials().size());
    EXPECT_TRUE(model.remove_potential(0));
    EXPECT_EQ(0, model.list_potentials().size());
    EXPECT_FALSE(model.remove_potential(0));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
