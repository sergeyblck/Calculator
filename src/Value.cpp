#include "Value.hpp"
#include <iostream>

Value::Value(double val) : value(val) {}

double Value::calc() const {
    return value;
}

void Value::print() const {
    std::cout << value;
}
