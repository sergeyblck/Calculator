#include <iostream>
#include <string>
#include <set>
#include "Parser.hpp"
#include "Variable.hpp"

using namespace std;

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    Parser parser(expression);
    INode* problem = parser.parse();

    set<string> variables;

    for (int i = 0; i < expression.size(); i++) {
        if (isalpha(expression[i])) {
            string varName;
            while (i < expression.size() && (isalpha(expression[i]) || isdigit(expression[i]))) {
                varName += expression[i++];
            }
            variables.insert(varName);
        }
    }

    for (const auto& var : variables) {
        double value;
        cout << "Enter value for " << var << ": ";
        cin >> value;
        Variable::setValue(var, value);
    }

    cout << "\nExpression: ";
    problem->print();
    cout << endl;

    cout << "Output: " << problem->calc() << endl;

    delete problem;
    return 0;
}
