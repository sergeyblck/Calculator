#pragma once

#include "INode.hpp"

//class for doing multiplication
class Multipl : public INode {
private:
    INode* left;
    INode* right;

public:
    //Constructor
    Multipl(INode* ileft, INode* iright);

    //Doing multiplication operation
    double calc() const override;

    //printing mult.
    void print() const override;
};
