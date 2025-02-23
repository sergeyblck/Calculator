#pragma once

#include <iostream>
#include <cstdlib> 

class ErrorHandler {
public:
    static void printErrorAndExit(const std::string& errorMessage);
};
bool isNumber(const std::string& str);

