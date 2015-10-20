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
        mol.type(0) = "HYDROPHILIC";
        mol.type(1) = "HYDROPHOBIC";
        mol.type(2) = "HYDROPHOBIC";
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
    EXPECT_EQ("HYDROPHILIC", mol.type(0));
    EXPECT_EQ("HYDROPHOBIC", mol.type(1));
    EXPECT_EQ("HYDROPHOBIC", mol.type(2));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
