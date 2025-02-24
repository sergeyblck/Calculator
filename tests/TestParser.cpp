#include <gtest/gtest.h>
#include "Parser.hpp"
#include "Variable.hpp"
using namespace std;


TEST(C_ParserTest, SimpleExpression) {
    string expression = "2 + 3";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 5);
    delete resultNode;
}

TEST(C_ParserTest, ExpressionWithVariable) {
    string expression = "x + 3";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    Variable::setValue("x", 2);

    EXPECT_EQ(resultNode->calc(), 5);
    delete resultNode;
}

TEST(C_ParserTest, ComplexExpression) {
    string expression = "(2 + 3) * 4-6/2*(6-2*1-(2*4-6))";
    Parser parser(expression);
    INode* resultNode = parser.parse();

    EXPECT_EQ(resultNode->calc(), 14);
    delete resultNode;
}