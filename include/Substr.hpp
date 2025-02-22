#pragma once

#include "INode.hpp"

class Substr : public INode {
private:
    INode* left;
    INode* right;

public:
    Substr(INode* ileft, INode* iright);
    double calc() const override;
    void print() const override;
};
