#include <gtest/gtest.h>
#include "bead_type.hpp"

namespace {

TEST(BeadTypeTest, SortedPair) {
    BeadType type0("abcde"),
             type1("bacde");
    EXPECT_EQ(std::make_pair(type0, type1), make_sorted_pair(type0, type1));
    EXPECT_EQ(std::make_pair(type0, type1), make_sorted_pair(type1, type0));
    EXPECT_EQ(std::make_pair(type0, type0), make_sorted_pair(type0, type0));
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
