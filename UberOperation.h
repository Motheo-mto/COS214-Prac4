#ifndef UBEROPERATION_H
#define UBEROPERATION_H

#include "OperationIterator.h"
#include <iostream>

using namespace std;

class UberOperation
{
    double cost;
public:
    virtual double getCost() = 0;
    virtual void setCost(double) = 0;
    virtual string getDescription() = 0;
    virtual OperationIterator *createIterator() = 0;
    virtual void add(UberOperation *a);
    virtual void remove(UberOperation *r);
    virtual ~UberOperation();
};

#endif // UBEROPERATION_H