#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <stack>
#include <cctype>
#include "INode.hpp"
#include "Value.hpp"
#include "Sum.hpp"
#include "Multipl.hpp"

class Parser {
private:
    std::string expression;
    size_t pos = 0;

public:
    Parser(const std::string& expr);
    INode* parse();

private:
    double parseNumber();
    int precedence(char op);
    void processOperator(std::stack<char>& ops, std::stack<INode*>& values);
};

#endif
