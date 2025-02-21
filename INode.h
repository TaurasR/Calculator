#ifndef INODE_H
#define INODE_H

#include <iostream>
#include <map>

class INode {
public:
    virtual ~INode() = default;
    virtual double calc(std::map<std::string, double>& variables) const = 0;
    virtual void print() const = 0;
};

#endif