#include <iostream>
#include "Parser.h"

int main() {
    std::string input;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, input);

    try {
        INode* expr = Parser::parse(input);
        std::map<std::string, double> variables;

        // Ask for variable values if any exist
        for (char c : input) {
            if (std::isalpha(c)) {
                if (variables.find(std::string(1, c)) == variables.end()) {
                    std::cout << "Enter value for " << c << ": ";
                    std::cin >> variables[std::string(1, c)];
                }
            }
        }

        std::cout << "Parsed expression: ";
        expr->print();
        std::cout << "\nResult: " << expr->calc(variables) << std::endl;

        delete expr;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}