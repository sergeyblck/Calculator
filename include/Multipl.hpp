#pragma once

#include "INode.hpp"

class Multipl : public INode {
private:
    INode* left;
    INode* right;

public:
    Multipl(INode* ileft, INode* iright);
    double calc() const override;
    void print() const override;
};
