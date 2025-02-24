#include <gtest/gtest.h>
#include "Sum.hpp"
#include "Value.hpp"
#include "Variable.hpp"

TEST(B_VaruableTest, SimpleVariableTest) {
    INode* left = new Value(21);
    INode* right = new Variable("x");
    Variable::setValue("x", 2);
    Sum result(left, right);

    EXPECT_EQ(result.calc(), 23);

    delete left;
    delete right;
}

TEST(B_VaruableTest, AdvancedVariableTest) {
    INode* left = new Variable("k34");
    INode* right = new Variable("x");
    Variable::setValue("x", 2);
    Variable::setValue("k34", 5);
    Sum result(left, right);

    EXPECT_EQ(result.calc(), 7);

    delete left;
    delete right;
}
