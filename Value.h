#ifndef VALUE_H
#define VALUE_H

#include "INode.h"

class Value : public INode {
private:
    double value;
public:
    Value(double val) : value(val) {}

    double calc(std::map<std::string, double>& variables) const override {
        return value;
    }

    void print() const override {
        std::cout << value;
    }
};

#endif 