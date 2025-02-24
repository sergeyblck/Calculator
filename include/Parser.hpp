#pragma once

#include <string>
#include <stack>
#include "INode.hpp"
#include "Value.hpp"
#include "Sum.hpp"
#include "Multipl.hpp"
#include "Substr.hpp"
#include "Divide.hpp"
#include "Variable.hpp"

//class for parsing an expression into a tree
class Parser {
private:
    std::string expression;
    int index = 0;

public:
    //Constructor
    Parser(const std::string& exp);

    //parses an expression into a tree
    //handles exceptions
    //Returns root node of the tree
    INode* parse();

private:
    //parses number from the expression by combining sequential digits 
    double parseNumber();

    //method for checking which sign is superior
    int precedence(char sign);

    //parsing variable from expression (x34df can be a variable)
    std::string parseVariable();

    //pops superior operation and pushes it to add to a tree
    void processOperator(std::stack<char>& sign, std::stack<INode*>& values);
};
