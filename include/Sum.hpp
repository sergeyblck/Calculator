#pragma once

#include "INode.hpp"

class Sum : public INode {
private:
    INode* left;
    INode* right;

public:
    Sum(INode* ileft, INode* iright);
    double calc() const override;
    void print() const override;
};
