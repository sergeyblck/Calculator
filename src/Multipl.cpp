#include "Multipl.hpp"
#include <iostream>

Multipl::Multipl(INode* lhs, INode* rhs) : left(lhs), right(rhs) {}

double Multipl::calc() const {
    return left->calc() * right->calc();
}

void Multipl::print() const {
    std::cout << "(";
    left->print();
    std::cout << " * ";
    right->print();
    std::cout << ")";
}
