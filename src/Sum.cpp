#include "Sum.hpp"
#include <iostream>
using namespace std;

Sum::Sum(INode* ileft, INode* iright) : left(ileft), right(iright) {}

double Sum::calc() const {
    return left->calc() + right->calc();
}

void Sum::print() const {
    cout << "(";
    left->print();
    cout << " + ";
    right->print();
    cout << ")";
}
