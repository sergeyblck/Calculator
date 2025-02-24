#pragma once

#include <set>
#include <string>

class VariableInputer {
public:
    static void requestVariableValues(const std::set<std::string>& variables);
};
    