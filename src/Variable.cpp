#include "Variable.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

map<string, double> Variable::values;

Variable::Variable(const string& name) : name(name) {}

double Variable::calc() const {
    auto it = values.find(name);
    if (it == values.end()) {
        throw runtime_error("No value for " + name);
    }
    return it->second;
}

void Variable::print() const {
    cout << name;
}

void Variable::setValue(const string& name, double value) {
    values[name] = value;
}
