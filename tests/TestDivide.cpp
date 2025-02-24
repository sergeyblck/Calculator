#include <gtest/gtest.h>
#include "Divide.hpp"
#include "Value.hpp"
using namespace std;

TEST(A_DivideTest, SimpleDivision) {
    INode* left = new Value(21);
    INode* right = new Value(7);
    Divide result(left, right);

    EXPECT_DOUBLE_EQ(result.calc(), 3);

    delete left;
    delete right;
}

TEST(A_DivideTest, FloatDivision) {
    INode* left = new Value(2.52);
    INode* right = new Value(1.2);
    Divide result(left, right);

    EXPECT_DOUBLE_EQ(result.calc(), 2.1);

    delete left;
    delete right;
}

TEST(A_DivideTest, DivisionByZero) {
    INode* left = new Value(21);
    INode* right = new Value(0);
    Divide result(left, right);

    EXPECT_THROW(result.calc(), runtime_error);

    delete left;
    delete right;
}

