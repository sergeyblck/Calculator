#include <iostream>
#include <string>
#include <set>
#include "Parser.hpp"
#include "Variable.hpp"
#include "VariableInputer.hpp"
#include "ErrorHandler.hpp"

using namespace std;


// Start of the program
int main() {

    //Entering expression
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    //Initializing and parsing the expression into a tree
    Parser parser(expression);
    INode* problem = parser.parse();

    //Searchig for names of varaibles
    set<string> variables = Variable::extractVariables(expression);

    //Entering values for variables
    VariableInputer::requestVariableValues(variables);

    //Printing exspression with paranthesis
    cout << "\nExpression: ";
    problem->print();
    cout << endl;

    //Printing result of the expression
    cout << "Output: " << problem->calc() << endl;

    delete problem;
    
    return 0;
}