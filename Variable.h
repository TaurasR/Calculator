#ifndef VARIABLE_H
#define VARIABLE_H

#include "INode.h"
#include <string>

class Variable : public INode {
private:
    std::string name;
public:
    Variable(std::string varName) : name(varName) {}

    double calc(std::map<std::string, double>& variables) const override {
        return variables[name]; // Look up variable value
    }

    void print() const override {
        std::cout << name;
    }
};

#endif
