#pragma once

#include "INode.hpp"

class Divide : public INode {
private:
    INode* left;
    INode* right;

public:
    Divide(INode* ileft, INode* iright);
    double calc() const override;
    void print() const override;
};
