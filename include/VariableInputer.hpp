#pragma once

#include <set>
#include <string>

// Class for entering a value for variables
class VariableInputer {
public:
    // Requesting value for variables
    static void requestVariableValues(const std::set<std::string>& variables);
};
    