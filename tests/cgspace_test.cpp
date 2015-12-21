#include <gtest/gtest.h>
#include "cgspace.hpp"

class CGSpaceTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        space.reset(15);
        for (int i(0); i < 10; ++i)
            space.coordinate(i) = Vector3d(i,0,0);

        space.coordinate(10) = Vector3d(2,2,2);
        space.coordinate(11) = Vector3d(2,1,2);
        space.coordinate(12) = Vector3d(2,3,2);
        space.coordinate(13) = Vector3d(2,2,1);
        space.coordinate(14) = Vector3d(2,2,3);

        for (int i(0); i < 15; ++i) {
            space.symbol(i) = "A";
        }
    }

    // virtual void TearDown() {}

    CGSpace space;
};

TEST_F(CGSpaceTest, NumBeads) {
    EXPECT_EQ(15, space.num_beads());
}

TEST_F(CGSpaceTest, Symbols) {
    EXPECT_EQ("A", space.symbol(1));
    space.symbol(1) = "B";
    EXPECT_EQ("B", space.symbol(1));
}

TEST_F(CGSpaceTest, Coordinates) {
    EXPECT_EQ(Vector3d(4,0,0), space.coordinate(4));
    EXPECT_EQ(Vector3d(2,2,3), space.coordinate(14));
}

TEST_F(CGSpaceTest, Veclotities) {
    EXPECT_EQ(Vector3d(0,0,0), space.velocity(11));
    space.velocity(11) = Vector3d(1,1,1);
    EXPECT_EQ(Vector3d(1,1,1), space.velocity(11));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
