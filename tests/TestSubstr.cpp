#include <gtest/gtest.h>
#include "Substr.hpp"
#include "Value.hpp"

TEST(A_SubstractionTest, SimpleSubstractionTest) {
    INode* left = new Value(21);
    INode* right = new Value(7);
    Substr result(left, right);

    EXPECT_EQ(result.calc(), 14);

    delete left;
    delete right;
}
