#include "Multipl.hpp"
#include <iostream>
using namespace std;

Multipl::Multipl(INode* ileft, INode* iright) : left(ileft), right(iright) {}

double Multipl::calc() const {
    return left->calc() * right->calc();
}

void Multipl::print() const {
    cout << "(";
    left->print();
    cout << " * ";
    right->print();
    cout << ")";
}
