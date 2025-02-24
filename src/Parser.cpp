#include "Parser.hpp"
#include "ErrorHandler.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cctype>
#include <locale>
#include <stdexcept>
#include <iomanip>
using namespace std;

Parser::Parser(const string& exp) : expression(exp) {}

INode* Parser::parse() {
    stack<INode*> values;
    stack<char> sign;
    int state = 0;
    int letsLookAtHowOurPatanthesisBehave = 0;

    while (index < expression.size()) {
        char symbol = expression[index];

        //skipping if space
        if (isspace(symbol)) {
            index++;
            continue;
        }

        // pushing value into values stack
        if (isdigit(symbol)) {
            if(state == 1 || state == 3){
                ErrorHandler::printErrorAndExit("Invalid expression: digit in a wrong place");
            }
            state=1;
            values.push(new Value(parseNumber()));
        }
        // pushing variable into values stack
        else if (isalpha(symbol)) {
            if(state == 1 || state == 3){
                ErrorHandler::printErrorAndExit("Invalid expression: variable in a wrong place");
            }
            state = 1;
            values.push(new Variable(parseVariable()));
        }
        // pushing '(' into sign stack
        else if (symbol == '(') {
            if(state == 1 || state == 3){
                ErrorHandler::printErrorAndExit("Invalid expression: open parentheses in a wrong place");
            }
            state = 2;
            letsLookAtHowOurPatanthesisBehave++;
            sign.push('(');
            index++;
        }
        // pushing into tree and poping last '('
        else if (symbol == ')') {
            if(state != 1 && state != 3){
                ErrorHandler::printErrorAndExit("Invalid expression: close parentheses in a wrong place");
            }
            state = 3;
            letsLookAtHowOurPatanthesisBehave--;
            if(letsLookAtHowOurPatanthesisBehave < 0){
                ErrorHandler::printErrorAndExit("Invalid expression: bad boi is closing before opening");
            }

            // Popping signs and values in matter of precedence to push them into a tree
            while (!sign.empty() && sign.top() != '(') {
                processOperator(sign, values);
            }
            sign.pop();
            index++;
        }
        // pushing a sign into sign stack
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            if(state != 1 && state != 3){
                ErrorHandler::printErrorAndExit("Invalid expression: sign in a wrong place");
            }
            state = 4;

            // pushing values and operations into a tree if previous precedence sign is more or equal
            while (!sign.empty() && precedence(sign.top()) >= precedence(symbol)) {
                processOperator(sign, values);
            }
            sign.push(symbol);
            index++;
        }
        else {
            ErrorHandler::printErrorAndExit("Invalid expression: unknown character");
        }
    }

    // Add the rest of signs and values into a tree
    while (!sign.empty()) {
        processOperator(sign, values);
    }

    //return the root node
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
    string number;
    while (index < expression.size() && (isdigit(expression[index]) || expression[index] == '.')) {
        number += expression[index++];
    }
    if (!Utils::isNumber(number)) {
        ErrorHandler::printErrorAndExit("Invalid expression, not a correct number");
    }
    std::setlocale(LC_NUMERIC, "C");
    std::cout << std::setprecision(10);
    return stod(number);
}


void Parser::processOperator(stack<char>& sign, stack<INode*>& values) {
    if (values.size() < 2) {
        ErrorHandler::printErrorAndExit("Invalid expression, not enough values");
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

    return varName;
}