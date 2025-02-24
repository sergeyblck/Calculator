#pragma once

#include "INode.hpp"

//Class for storing value
class Value : public INode {
private:
    double value;

public:
    //Constructor
    Value(double val);

    //Return value
    double calc() const override;

    //Prints value
    void print() const override;
};
