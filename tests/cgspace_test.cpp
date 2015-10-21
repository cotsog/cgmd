#include <gtest/gtest.h>
#include "cgspace.hpp"

class CGSpaceTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        mol0 = Molecule(10);
        for (int i(0); i < 10; ++i) {
            mol0.coordinate(i) = Vector3d(i,0,0);
            mol0.type(i) = BeadType("BEAD0");
            if (i > 0)
                mol0.add_bond(i-1, i);
        }

        mol1 = Molecule(5);
        for (int i(0); i < 5; ++i) {
            mol1.coordinate(i) = Vector3d(0,i,-1);
            mol1.type(i) = BeadType("BEAD1");
        }
        mol1.add_bond(0,1);
        mol1.add_bond(0,2);
        mol1.add_bond(0,3);
        mol1.add_bond(0,4);
    }

    // virtual void TearDown() {}

    Molecule mol0, mol1;
    CGSpace space;
};

TEST_F(CGSpaceTest, NumBeads) {
    EXPECT_EQ(0, space.num_beads());
    space.add_molecule(mol0);
    EXPECT_EQ(10, space.num_beads());
    space.add_molecule(mol1);
    EXPECT_EQ(15, space.num_beads());
}

TEST_F(CGSpaceTest, AddBond) {
    space.add_molecule(mol0);
    ASSERT_EQ(10, space.num_beads());

    EXPECT_EQ(9, space.list_bonds().size());
    EXPECT_EQ(true, space.add_bond(9,0));
    EXPECT_EQ(10, space.list_bonds().size());
}

TEST_F(CGSpaceTest, Coordinates) {
    space.add_molecule(mol0);
    space.add_molecule(mol1);
    ASSERT_EQ(15, space.num_beads());

    EXPECT_EQ(Vector3d(4,0,0), space.coordinate(4));
    EXPECT_EQ(Vector3d(0,4,-1), space.coordinate(14));
}

TEST_F(CGSpaceTest, Veclotities) {
    space.add_molecule(mol0);
    space.add_molecule(mol1);
    ASSERT_EQ(15, space.num_beads());

    EXPECT_EQ(Vector3d(0,0,0), space.velocity(11));
    space.velocity(11) = Vector3d(1,1,1);
    EXPECT_EQ(Vector3d(1,1,1), space.velocity(11));
}

TEST_F(CGSpaceTest, Bond) {
    space.add_molecule(mol1);
    ASSERT_EQ(5, space.num_beads());

    std::set<CGSpace::bond_pair> bonds;
    bonds.insert(CGSpace::bond_pair(0,1));
    bonds.insert(CGSpace::bond_pair(0,2));
    bonds.insert(CGSpace::bond_pair(0,3));
    bonds.insert(CGSpace::bond_pair(0,4));
    EXPECT_EQ(bonds, space.list_bonds());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
