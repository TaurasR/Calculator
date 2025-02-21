#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "INode.h"

class Multiply : public INode {
private:
    INode* left;
    INode* right;
public:
    Multiply(INode* l, INode* r) : left(l), right(r) {}

    double calc(std::map<std::string, double>& variables) const override {
        return left->calc(variables) * right->calc(variables);
    }

    void print() const override {
        std::cout << "(";
        left->print();
        std::cout << " * ";
        right->print();
        std::cout << ")";
    }
};

#endif