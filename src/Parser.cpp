#include "Parser.hpp"
#include <iostream>
#include <cctype>
#include <stdexcept>
using namespace std;

Parser::Parser(const string& exp) : expression(exp) {}

INode* Parser::parse() {
    stack<INode*> values;
    stack<char> sign;

    while (index < expression.size()) {
        char symbol = expression[index];

        if (isspace(symbol)) {
            index++;
            continue;
        }

        if (isdigit(symbol)) {
            values.push(new Value(parseNumber()));
        }
        else if (isalpha(symbol)) {
            values.push(new Variable(parseVariable()));
        }
        else if (symbol == '(') {
            sign.push('(');
            index++;
        }
        else if (symbol == ')') {
            while (!sign.empty() && sign.top() != '(') {
                processOperator(sign, values);
            }
            sign.pop();
            index++;
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            while (!sign.empty() && precedence(sign.top()) >= precedence(symbol)) {
                processOperator(sign, values);
            }
            sign.push(symbol);
            index++;
        }
        else {
            index++;
        }
    }

    while (!sign.empty()) {
        processOperator(sign, values);
    }

    if (values.size() != 1) {
        throw std::runtime_error("Error: Invalid expression, too many values left.");
    }

    return values.top();
}


int Parser::precedence(char sign) {
    if (sign == '*' || sign == '/') {
        return 2;
    }
    if (sign == '+' || sign == '-') {
        return 1;
    }
    return 0;
}


double Parser::parseNumber() {
    string num;
    while (index < expression.size() && (isdigit(expression[index]) || expression[index] == '.')) {
        num += expression[index++];
    }
    if (num.empty()) {
        throw runtime_error("Error: Expected a number.");
    }
    return stod(num);
}


void Parser::processOperator(stack<char>& sign, stack<INode*>& values) {
    if (values.size() < 2) {
        throw runtime_error("Error: Not enough operands for operator.");
    }

    char firstSign = sign.top();
    sign.pop();

    INode* right = values.top();
    values.pop();
    INode* left = values.top();
    values.pop();

    if (firstSign == '+') {
        values.push(new Sum(left, right));
    } else if (firstSign == '-') {
        values.push(new Substr(left, right));
    } else if (firstSign == '*') {
        values.push(new Multipl(left, right));
    }else if (firstSign == '/') {
        values.push(new Divide(left, right));
    }
}

string Parser::parseVariable() {
    string varName;

    while (index < expression.size() && (isalpha(expression[index]) || isdigit(expression[index]))) {
        varName += expression[index++];
    }

    if (varName.empty()) {
        throw runtime_error("Error: Expected variable name.");
    }

    return varName;
}