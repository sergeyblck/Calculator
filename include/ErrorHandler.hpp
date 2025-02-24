#pragma once

#include <iostream>

class ErrorHandler {
public:
    static void printErrorAndExit(const std::string& errorMessage);
};

