#pragma once

//main interface
class INode {
public:
    virtual ~INode() = default;
    virtual double calc() const = 0;
    virtual void print() const = 0;
};
