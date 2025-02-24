#include <gtest/gtest.h>
#include "Sum.hpp"
#include "Value.hpp"

TEST(A_SumTest, SimpleSumTest) {
    INode* left = new Value(21);
    INode* right = new Value(7);
    Sum result(left, right);

    EXPECT_EQ(result.calc(), 28);

    delete left;
    delete right;
}
