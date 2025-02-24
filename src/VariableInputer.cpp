#include "VariableInputer.hpp"
#include "Variable.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;

void VariableInputer::requestVariableValues(const set<string>& variables) {
    for (const auto& var : variables) {
        string value;
        while(true){
            cout << "Enter value for " << var << ": ";
            cin >> value;
            if (!Utils::isNumber(value)) {
                cout << endl << "Value is not a number, try again" << endl;
            }
            else{
                Variable::setValue(var, stod(value));
                break;
            }
        }
    }
}
