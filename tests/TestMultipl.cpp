#include <gtest/gtest.h>
#include "Multipl.hpp"
#include "Value.hpp"

TEST(A_MultiplicationTest, SimpleMultiplication) {
    INode* left = new Value(21);
    INode* right = new Value(7);
    Multipl result(left, right);

    EXPECT_EQ(result.calc(), 147);

    delete left;
    delete right;
}
