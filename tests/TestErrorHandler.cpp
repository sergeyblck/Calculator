#include <gtest/gtest.h>
#include "Parser.hpp"
using namespace std;


TEST(D_ErrorHandlerTest, DivisionByZeroError) {
    string expression = "3/0";
    Parser parser(expression);
    INode* resultNode = parser.parse();
    
    try {
        resultNode->calc();
        FAIL() << "Error";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Division by zero");
    }

    delete resultNode;
}

TEST(D_ErrorHandlerTest, DigitInWrongPlace) {
    string expression = "3+4*5 5-3";
    Parser parser(expression);
    
    try {
        INode* resultNode = parser.parse();
        delete resultNode;
        FAIL() << "Error";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Invalid expression: digit in a wrong place");
    }

}


TEST(D_ErrorHandlerTest, VariableInWrongPlace) {
    string expression = "x+34-3 x";
    Parser parser(expression);
    Variable::setValue("x", 2);
    
    try {
        INode* resultNode = parser.parse();
        delete resultNode;
        FAIL() << "Error";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Invalid expression: variable in a wrong place");
    }

}

TEST(D_ErrorHandlerTest, OpenParanthesisWrongPlace) {
    string expression = "3+4(4+4)";
    Parser parser(expression);
    
    try {
        INode* resultNode = parser.parse();
        delete resultNode;
        FAIL() << "Error";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Invalid expression: open parentheses in a wrong place");
    }

}

TEST(D_ErrorHandlerTest, CloseParanthesisWrongPlace) {
    string expression = "3+4*(4+)4";
    Parser parser(expression);
    
    try {
        INode* resultNode = parser.parse();
        delete resultNode;
        FAIL() << "Error";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Invalid expression: close parentheses in a wrong place");
    }

}
