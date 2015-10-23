#include <gtest/gtest.h>
#include <cmath>
#include "cgspace.hpp"
#include "force_field.hpp"

namespace {

class BondingForceFieldTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        field.add_bond(BeadType("Bead0"), BeadType("Bead1"),
            /* r= */ 0.5, /* k= */ 2.0);
        field.add_bond(BeadType("Bead0"), BeadType("Bead2"),
            /* r= */ 0.6, /* k= */ 2.5);
    }

    // virtual void TearDown() {}

    BondingForceField field;
};

TEST_F(BondingForceFieldTest, AddBond) {
    EXPECT_TRUE(field.add_bond(BeadType("Bead3"), BeadType("Bead2"),
        /* r= */ 0.6, /* k= */ 2.5));
    EXPECT_FALSE(field.add_bond(BeadType("Bead1"), BeadType("Bead0"),
        /* r= */ 0.57, /* k= */ 2.0));
}

TEST_F(BondingForceFieldTest, R) {
    EXPECT_EQ(0.5, field.get_r(BeadType("Bead0"), BeadType("Bead1")));
    EXPECT_EQ(0.5, field.get_r(BeadType("Bead1"), BeadType("Bead0")));
    EXPECT_EQ(0.6, field.get_r(BeadType("Bead0"), BeadType("Bead2")));
    EXPECT_EQ(0.6, field.get_r(BeadType("Bead2"), BeadType("Bead0")));
    EXPECT_EQ(0.0, field.get_r(BeadType("Bead1"), BeadType("Bead2")));
    EXPECT_EQ(0.0, field.get_k(BeadType("Bead2"), BeadType("Bead1")));
}

TEST_F(BondingForceFieldTest, K) {
    EXPECT_EQ(2.0, field.get_k(BeadType("Bead0"), BeadType("Bead1")));
    EXPECT_EQ(2.0, field.get_k(BeadType("Bead1"), BeadType("Bead0")));
    EXPECT_EQ(2.5, field.get_k(BeadType("Bead0"), BeadType("Bead2")));
    EXPECT_EQ(2.5, field.get_k(BeadType("Bead2"), BeadType("Bead0")));
    EXPECT_EQ(0.0, field.get_k(BeadType("Bead1"), BeadType("Bead2")));
    EXPECT_EQ(0.0, field.get_k(BeadType("Bead2"), BeadType("Bead2")));
}

TEST_F(BondingForceFieldTest, CalculateEnergy) {
    Molecule mol(2);
    mol.type(0) = BeadType("Bead0");
    mol.type(1) = BeadType("Bead1");
    mol.coordinate(0) = Vector3d(0,0,0);
    mol.coordinate(1) = Vector3d(2,0,0);
    mol.add_bond(0,1);
    CGSpace space;
    space.add_molecule(mol);

    EXPECT_EQ(2.0*pow(2-0.5,2), field.calculate_energy(space));
}

TEST_F(BondingForceFieldTest, CalculateForce) {
    Molecule mol(2);
    mol.type(0) = BeadType("Bead0");
    mol.type(1) = BeadType("Bead1");
    mol.coordinate(0) = Vector3d(0,0,0);
    mol.coordinate(1) = Vector3d(2,0,0);
    mol.add_bond(0,1);
    CGSpace space;
    space.add_molecule(mol);

    const double strength(2.0*2.0*(2-0.5));
    vector_list expected(2);
    expected.at(0) = Vector3d(1,0,0) * strength;
    expected.at(1) = expected.at(0) * (-1);
    EXPECT_EQ(expected, field.calculate_force(space));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
