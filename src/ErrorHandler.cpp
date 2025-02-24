#include "ErrorHandler.hpp"

using namespace std;

void ErrorHandler::printErrorAndExit(const string& errorMessage) {
    //cerr << endl << "Error: " << errorMessage << endl;
    throw runtime_error(errorMessage);
    //exit(EXIT_FAILURE);
}