#ifndef SPLITTER_H
#define SPLITTER_H

#include <vector>
#include <string>
#include <cctype>

enum SymbolType { NUMBER, VARIABLE, OPERATOR, LPAREN, RPAREN };

struct Symbol {
    SymbolType type;
    std::string value;
};

class Splitter {
public:
    static std::vector<Symbol> split(const std::string& expression) {
        std::vector<Symbol> symbols;
        std::string numBuffer;

        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (std::isdigit(c) || c == '.') { // Handle numbers
                numBuffer += c;
            } else {
                if (!numBuffer.empty()) {  // Push the number symbol
                    symbols.push_back({ NUMBER, numBuffer });
                    numBuffer.clear();
                }

                if (std::isalpha(c)) {  // Handle variables
                    symbols.push_back({ VARIABLE, std::string(1, c) });
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {  // Operators
                    symbols.push_back({ OPERATOR, std::string(1, c) });
                } else if (c == '(') {
                    symbols.push_back({ LPAREN, "(" });
                } else if (c == ')') {
                    symbols.push_back({ RPAREN, ")" });
                }
            }
        }

        if (!numBuffer.empty()) {  // Push the last number if any
            symbols.push_back({ NUMBER, numBuffer });
        }

        return symbols;
    }
};

#endif
