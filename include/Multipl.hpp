#pragma once
#include "INode.hpp"

class Multipl : public INode {
private:
    INode* left;
    INode* right;

public:
    Multipl(INode* lhs, INode* rhs);
    double calc() const override;
    void print() const override;
};
