#include "Variable.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

map<string, double> Variable::values;

Variable::Variable(const string& name) : name(name) {}

std::set<string> Variable::extractVariables(const string& expression) {
    set<string> variables;
    for (size_t i = 0; i < expression.size(); i++) {
        if (isalpha(expression[i])) {
            string varName;
            while (i < expression.size() && (isalpha(expression[i]) || isdigit(expression[i]))) {
                varName += expression[i++];
            }
            variables.insert(varName);
        }
    }
    return variables;
}


double Variable::calc() const {
    auto it = values.find(name);
    return it->second;
}

void Variable::print() const {
    cout << name;
}

void Variable::setValue(const string& name, double value) {
    values[name] = value;
}
