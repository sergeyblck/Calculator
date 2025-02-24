#pragma once

#include "INode.hpp"

//class for doing sum
class Sum : public INode {
private:
    INode* left;
    INode* right;

public:
    //Constructor
    Sum(INode* ileft, INode* iright);

    //Doing sum operation
    double calc() const override;

    //printing sum
    void print() const override;
};
