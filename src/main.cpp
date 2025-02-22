#include <iostream>
#include <string>
#include "Parser.hpp"

int main() {
    std::string expr;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expr);

    std::cout << expr;
    Parser parser(expr);
    INode* root = parser.parse();

    std::cout << "Expression: ";
    root->print();
    std::cout << std::endl;

    std::cout << "Result: " << root->calc() << std::endl;

    delete root;
    return 0;
}
