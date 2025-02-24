#pragma once

#include <iostream>

// class for handling errors
class ErrorHandler {
public:
    //method can be used in various ways
    //at the moment simply throws an exception
    static void printErrorAndExit(const std::string& errorMessage);
};

