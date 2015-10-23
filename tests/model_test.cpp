#include <gtest/gtest.h>
#include <memory>
#include "bead_type.hpp"
#include "force_field.hpp"
#include "model.hpp"

namespace {

class ModelTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        model.set_dt(0.2);
        model.add_bead(BeadType("Bead0"),
            /* mass= */ 1.0, /* friction= */ 0.4);
        model.add_bead(BeadType("Bead1"),
            /* mass= */ 1.5, /* friction= */ 0.3);
    }

    // virtual void TearDown() {}

    LangevinModel model;
};

TEST_F(ModelTest, TimeInterval) {
    EXPECT_EQ(0.2, model.get_dt());
    model.set_dt(0.5);
    EXPECT_EQ(0.5, model.get_dt());
}

TEST_F(ModelTest, AddBead) {
    EXPECT_TRUE(model.add_bead(BeadType("Bead2"),
        /* mass= */ 1.1, /* friction= */ 0.6));
    EXPECT_FALSE(model.add_bead(BeadType("Bead0"),
        /* mass= */ 1.1, /* friction= */ 0.4));
}

TEST_F(ModelTest, Mass) {
    EXPECT_EQ(1.0, model.get_mass(BeadType("Bead0")));
    EXPECT_EQ(1.5, model.get_mass(BeadType("Bead1")));
}

TEST_F(ModelTest, Friction) {
    EXPECT_EQ(0.4, model.get_friction(BeadType("Bead0")));
    EXPECT_EQ(0.3, model.get_friction(BeadType("Bead1")));
}

TEST_F(ModelTest, ForceField) {
    std::shared_ptr<BondingForceField> bfield(new BondingForceField());
    bfield->add_bond(BeadType("Bead0"), BeadType("Bead1"),
        /* r= */ 0.5, /* k= */ 2.0);
    model.add_force_field(bfield);
    EXPECT_EQ(1, model.list_force_fields().size());
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
