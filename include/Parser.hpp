#pragma once

#include <string>
#include <stack>
#include "INode.hpp"
#include "Value.hpp"
#include "Sum.hpp"
#include "Multipl.hpp"
#include "Substr.hpp"
#include "Divide.hpp"

class Parser {
private:
    std::string expression;
    int index = 0;

public:
    Parser(const std::string& exp);
    INode* parse();

private:
    double parseNumber();
    int precedence(char sign);
    void processOperator(std::stack<char>& sign, std::stack<INode*>& values);
};
