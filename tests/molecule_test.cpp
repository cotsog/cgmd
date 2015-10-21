#include <gtest/gtest.h>
#include "molecule.hpp"

namespace {

class MoleculeTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        mol = Molecule(3);
        mol.coordinate(0) = Vector3d(1,0,0);
        mol.coordinate(1) = Vector3d(2,0,0);
        mol.coordinate(2) = Vector3d(4,0,0);
        mol.type(0) = BeadType("HYDROPHILIC");
        mol.type(1) = BeadType("HYDROPHOBIC");
        mol.type(2) = BeadType("HYDROPHOBIC");

        mol.add_bond(0,1);
        mol.add_bond(1,2);
    }

    // virtual void TearDown() {}

    Molecule mol;
};

TEST_F(MoleculeTest, NumBeads) {
    EXPECT_EQ(3, mol.num_beads());
}

TEST_F(MoleculeTest, Coordinate) {
    ASSERT_EQ(3, mol.num_beads());
    EXPECT_EQ(Vector3d(1,0,0), mol.coordinate(0));
    mol.coordinate(0) = Vector3d(2,1,0);
    EXPECT_EQ(Vector3d(2,1,0), mol.coordinate(0));
    EXPECT_EQ(Vector3d(2,0,0), mol.coordinate(1));
    EXPECT_EQ(Vector3d(4,0,0), mol.coordinate(2));
}

TEST_F(MoleculeTest, Type) {
    ASSERT_EQ(3, mol.num_beads());
    EXPECT_EQ(BeadType("HYDROPHILIC"), mol.type(0));
    EXPECT_EQ(BeadType("HYDROPHOBIC"), mol.type(1));
    EXPECT_EQ(BeadType("HYDROPHOBIC"), mol.type(2));
}

TEST_F(MoleculeTest, Bond) {
    std::set<Molecule::bond_pair> bonding_set;
    bonding_set.insert(Molecule::bond_pair(0,1));
    bonding_set.insert(Molecule::bond_pair(1,2));
    EXPECT_EQ(bonding_set, mol.list_bonds());
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
