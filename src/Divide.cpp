#include "Divide.hpp"
#include <iostream>
using namespace std;

Divide::Divide(INode* ileft, INode* iright) : left(ileft), right(iright) {}

double Divide::calc() const {
    return left->calc() / right->calc();
}

void Divide::print() const {
    cout << "(";
    left->print();
    cout << " / ";
    right->print();
    cout << ")";
}
