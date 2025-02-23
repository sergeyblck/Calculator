#include "Divide.hpp"
#include "ErrorHandler.hpp"
#include <iostream>
using namespace std;

Divide::Divide(INode* ileft, INode* iright) : left(ileft), right(iright) {}

double Divide::calc() const {
    double denominator = right->calc();
    if (denominator == 0) {
        ErrorHandler::printErrorAndExit("Division by zero");
    }
    return left->calc() / denominator;
}


void Divide::print() const {
    cout << "(";
    left->print();
    cout << " / ";
    right->print();
    cout << ")";
}
