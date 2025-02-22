#include "Sum.hpp"
#include <iostream>

Sum::Sum(INode* lhs, INode* rhs) : left(lhs), right(rhs) {}

double Sum::calc() const {
    return left->calc() + right->calc();
}

void Sum::print() const {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")";
}
