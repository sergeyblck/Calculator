

#include <gtest/gtest.h>
#include "Parser.hpp"
#include "Variable.hpp"
using namespace std;


TEST(ParserTest, SimpleExpression) {
    string expression = "2 + 3";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 5);
    delete resultNode;
}

TEST(ParserTest, ExpressionWithVariables) {
    string expression = "x + 3";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    Variable::setValue("x", 2);

    EXPECT_EQ(resultNode->calc(), 5);
    delete resultNode;
}

TEST(ParserTest, ComplexExpression) {
    string expression = "(2 + 3) * 4";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 20);
    delete resultNode;
}

TEST(ParserTest, InvalidExpression) {
    string expression = "2 +";
    Parser parser(expression);

    try {
        INode* resultNode = parser.parse();
        FAIL() << "Expected runtime error due to invalid expression.";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Invalid expression, not enough values");
    }
}

TEST(MultiplTest, MultiplicationTest) {
    string expression = "2 * 3";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 6);
    delete resultNode;
}

TEST(MultiplTest, NestedMultiplication) {
    string expression = "2 * (3 * 4)";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 24);
    delete resultNode;
}
    

