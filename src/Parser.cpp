#include "Parser.hpp"
#include <iostream>
#include <stdexcept>

Parser::Parser(const std::string& expr) : expression(expr) {}

INode* Parser::parse() {
    std::stack<INode*> values;  // Stack for values
    std::stack<char> ops;       // Stack for operators

    while (pos < expression.size()) {
        char currentChar = expression[pos];

        // Skip any whitespace characters
        if (isspace(currentChar)) {
            pos++;
            continue;
        }

        // Handle numbers
        if (isdigit(currentChar)) {
            values.push(new Value(parseNumber()));
        }
        // Handle opening parenthesis
        else if (currentChar == '(') {
            ops.push('(');
            pos++;
        }
        // Handle closing parenthesis
        else if (currentChar == ')') {
            // Process all operators until a '(' is encountered
            while (!ops.empty() && ops.top() != '(') {
                processOperator(ops, values);
            }
            ops.pop(); // Pop the '(' from the operator stack
            pos++;
        }
        // Handle operators (+ or *)
        else if (currentChar == '+' || currentChar == '*') {
            // Apply operators with higher or equal precedence
            while (!ops.empty() && precedence(ops.top()) >= precedence(currentChar)) {
                processOperator(ops, values);
            }
            // Push the current operator onto the operator stack
            ops.push(currentChar);
            pos++;
        }
        else {
            // Skip any unrecognized characters
            pos++;
        }
    }

    // Process any remaining operators
    while (!ops.empty()) {
        processOperator(ops, values);
    }

    // The final result should be the only value left in the stack
    if (values.size() != 1) {
        throw std::runtime_error("Error: Invalid expression, too many values left.");
    }

    return values.top();
}

// Helper function to determine operator precedence
int Parser::precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;  // Higher precedence
    }
    if (op == '+' || op == '-') {
        return 1;  // Lower precedence
    }
    return 0;  // No precedence for '(' or other operators
}


double Parser::parseNumber() {
    std::string num;
    while (pos < expression.size() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        num += expression[pos++];
    }
    if (num.empty()) {
        throw std::runtime_error("Error: Expected a number.");
    }
    return std::stod(num);
}


void Parser::processOperator(std::stack<char>& ops, std::stack<INode*>& values) {
    if (values.size() < 2) {
        throw std::runtime_error("Error: Not enough operands for operator.");
    }

    char op = ops.top();
    ops.pop();

    INode* right = values.top();
    values.pop();
    INode* left = values.top();
    values.pop();

    if (op == '+') {
        values.push(new Sum(left, right));
    } else if (op == '*') {
        values.push(new Multipl(left, right));
    }
}
