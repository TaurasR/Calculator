#ifndef PARSER_H
#define PARSER_H

#include "INode.h"
#include "Value.h"
#include "Variable.h"
#include "Sum.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Splitter.h"

#include <stack>
#include <vector>
#include <stdexcept>

class Parser {
public:
    static INode* parse(const std::string& expression) {
        std::vector<Symbol> symbols = Splitter::split(expression);
        std::stack<INode*> values;
        std::stack<std::string> ops;

        for (const Symbol& symbol : symbols) {
            if (symbol.type == NUMBER) {
                values.push(new Value(std::stod(symbol.value)));
            } 
            else if (symbol.type == VARIABLE) {
                values.push(new Variable(symbol.value));
            } 
            else if (symbol.type == OPERATOR) {
                while (!ops.empty() && precedence(ops.top()) >= precedence(symbol.value)) {
                    applyOperation(values, ops);
                }
                ops.push(symbol.value);
            } 
            else if (symbol.type == LPAREN) {
                ops.push(symbol.value);
            } 
            else if (symbol.type == RPAREN) {
                while (!ops.empty() && ops.top() != "(") {
                    applyOperation(values, ops);
                }
                ops.pop(); // Remove '('
            }
        }

        while (!ops.empty()) {
            applyOperation(values, ops);
        }

        return values.top();
    }

private:
    static int precedence(const std::string& op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        return 0;
    }

    static void applyOperation(std::stack<INode*>& values, std::stack<std::string>& ops) {
        if (values.size() < 2) throw std::runtime_error("Invalid expression");

        INode* right = values.top(); values.pop();
        INode* left = values.top(); values.pop();
        std::string op = ops.top(); ops.pop();

        if (op == "+") values.push(new Sum(left, right));
        else if (op == "-") values.push(new Subtract(left, right));
        else if (op == "*") values.push(new Multiply(left, right));
        else if (op == "/") values.push(new Divide(left, right));
    }
};

#endif
