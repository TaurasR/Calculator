#ifndef DIVIDE_H
#define DIVIDE_H

#include "INode.h"

class Divide : public INode {
private:
    INode* left;
    INode* right;
public:
    Divide(INode* l, INode* r) : left(l), right(r) {}

    double calc(std::map<std::string, double>& variables) const override {
        double denominator = right->calc(variables);
        if (denominator == 0) {
            throw std::runtime_error("Error: Division by zero!");
        }
        return left->calc(variables) / denominator;
    }

    void print() const override {
        std::cout << "(";
        left->print();
        std::cout << " / ";
        right->print();
        std::cout << ")";
    }
};

#endif