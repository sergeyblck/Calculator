#include "ErrorHandler.hpp"
#include <cmath>

using namespace std;

void ErrorHandler::printErrorAndExit(const string& errorMessage) {
    cerr << endl << "Error: " << errorMessage << endl;
    throw runtime_error(errorMessage);
    //exit(EXIT_FAILURE);
}

bool isNumber(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}