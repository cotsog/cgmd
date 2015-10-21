#include <gtest/gtest.h>
#include "force_field.hpp"

namespace {

class BondingForceFieldTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        field.add_bond(BeadType("Bead0"), BeadType("Bead1"),
            /* r= */ 0.5, /* K= */ 2.0);
        field.add_bond(BeadType("Bead0"), BeadType("Bead2"),
            /* r= */ 0.6, /* K= */ 2.5);
    }

    // virtual void TearDown() {}

    BondingForceField field;
};

TEST_F(BondingForceFieldTest, AddBond) {
    EXPECT_TRUE(field.add_bond(BeadType("Bead3"), BeadType("Bead2"),
        /* r= */ 0.6, /* K= */ 2.5));
    EXPECT_FALSE(field.add_bond(BeadType("Bead1"), BeadType("Bead0"),
        /* r= */ 0.57, /* K= */ 2.0));
}

TEST_F(BondingForceFieldTest, R) {
    EXPECT_EQ(0.5, field.get_r(BeadType("Bead0"), BeadType("Bead1")));
    EXPECT_EQ(0.5, field.get_r(BeadType("Bead1"), BeadType("Bead0")));
    EXPECT_EQ(0.6, field.get_r(BeadType("Bead0"), BeadType("Bead2")));
    EXPECT_EQ(0.6, field.get_r(BeadType("Bead2"), BeadType("Bead0")));
}

TEST_F(BondingForceFieldTest, K) {
    EXPECT_EQ(2.0, field.get_k(BeadType("Bead0"), BeadType("Bead1")));
    EXPECT_EQ(2.0, field.get_k(BeadType("Bead1"), BeadType("Bead0")));
    EXPECT_EQ(2.5, field.get_k(BeadType("Bead0"), BeadType("Bead2")));
    EXPECT_EQ(2.5, field.get_k(BeadType("Bead2"), BeadType("Bead0")));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
