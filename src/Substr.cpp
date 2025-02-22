#include "Substr.hpp"
#include <iostream>
using namespace std;

Substr::Substr(INode* ileft, INode* iright) : left(ileft), right(iright) {}

double Substr::calc() const {
    return left->calc() - right->calc();
}

void Substr::print() const {
    cout << "(";
    left->print();
    cout << " - ";
    right->print();
    cout << ")";
}
