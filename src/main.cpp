#include <iostream>
#include <string>
#include <set>
#include "Parser.hpp"
#include "Variable.hpp"
#include "VariableInputer.hpp"
#include "ErrorHandler.hpp"

using namespace std;



int main() {
    while(true){
        string expression;
        cout << "Enter an expression: ";
        getline(cin, expression);

        Parser parser(expression);
        INode* problem = parser.parse();

        
        set<string> variables = Variable::extractVariables(expression);
        VariableInputer::requestVariableValues(variables);

        cout << "\nExpression: ";
        problem->print();
        cout << endl;

        cout << "Output: " << problem->calc() << endl;

        delete problem;
    }
    return 0;
}