#pragma once

#include "INode.hpp"

class Value : public INode {
private:
    double value;

public:
    Value(double val);
    double calc() const override;
    void print() const override;
};
