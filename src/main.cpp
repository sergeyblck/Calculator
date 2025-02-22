#include <iostream>
#include <string>
#include "Parser.hpp"
using namespace std;

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    //cout << expression;
    Parser parser(expression);
    INode* problem = parser.parse();

    cout << endl << "Expression: ";
    problem->print();
    cout << endl;

    cout << "Output: " << problem->calc() << endl;

    delete problem;
    return 0;
}
