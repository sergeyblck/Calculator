#pragma once

#include "INode.hpp"

//class for doing subtraction
class Substr : public INode {
private:
    INode* left;
    INode* right;

public:
    //Constructor
    Substr(INode* ileft, INode* iright);

    //Doing subtraction operation
    double calc() const override;
    
    //printing subtr.
    void print() const override;
};
