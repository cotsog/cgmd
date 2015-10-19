#include <gtest/gtest.h>
#include "lipid.hpp"

namespace {

class LipidTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        lipid = Lipid(3);
        lipid.coordinate(0) = Vector3d(0,0,0);
        lipid.coordinate(1) = Vector3d(1,0,0);
        lipid.coordinate(2) = Vector3d(3,0,0);
        lipid.velocity(0) = Vector3d(0,1,0);
        lipid.velocity(1) = Vector3d(0,0,0);
        lipid.velocity(2) = Vector3d(0,-1,0);
    }

    // virtual void TearDown() {}

    Lipid lipid;
};

TEST_F(LipidTest, NumBeads) {
    EXPECT_EQ(3, lipid.num_beads());
}

TEST_F(LipidTest, Coordinate) {
    EXPECT_EQ(Vector3d(0,0,0), lipid.coordinate(0));
    EXPECT_EQ(Vector3d(1,0,0), lipid.coordinate(1));
    EXPECT_EQ(Vector3d(3,0,0), lipid.coordinate(2));
    lipid.coordinate(0) = Vector3d(0,1,0);
    EXPECT_EQ(Vector3d(0,1,0), lipid.coordinate(0));
}

TEST_F(LipidTest, Velocity) {
    EXPECT_EQ(Vector3d(0,1,0), lipid.velocity(0));
    EXPECT_EQ(Vector3d(0,0,0), lipid.velocity(1));
    EXPECT_EQ(Vector3d(0,-1,0), lipid.velocity(2));
    lipid.velocity(2) = Vector3d(0,0,1);
    EXPECT_EQ(Vector3d(0,0,1), lipid.velocity(2));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
