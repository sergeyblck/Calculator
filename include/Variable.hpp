#pragma once

#include "INode.hpp"
#include <string>
#include <map>
#include <set>

//Class for managing variables
class Variable : public INode {
    std::string name;

    // storing name of the variable and its value
    static std::map<std::string, double> values;

public:
    //Constructor
    Variable(const std::string& name);
    
    //returning value
    double calc() const override;

    //printing name of the variable
    void print() const override;

    // setting value for the named variable
    static void setValue(const std::string& name, double value);

    //Searches for variables and returns their names
    static std::set<std::string> extractVariables(const std::string& expression);
};