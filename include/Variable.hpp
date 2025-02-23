#pragma once

#include "INode.hpp"
#include <string>
#include <map>

class Variable : public INode {
    std::string name;
    static std::map<std::string, double> values;

public:
    Variable(const std::string& name);
    
    double calc() const override;
    void print() const override;

    static void setValue(const std::string& name, double value);
    static double getValue(const std::string& name);
};