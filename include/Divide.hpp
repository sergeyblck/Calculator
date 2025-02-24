#pragma once

#include "INode.hpp"

//class for doing division
class Divide : public INode {
private:
    INode* left;
    INode* right;

public:
    //Constructor
    Divide(INode* ileft, INode* iright);

    //Do a division operation
    double calc() const override;

    // print division operation in paranthesis
    void print() const override;
};
