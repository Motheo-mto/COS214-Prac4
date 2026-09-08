#ifndef OPERATIONITERATOR_H
#define OPERATIONITERATOR_H

#include <list>
class UberOperation;
#include <iostream>

using namespace std;

class OperationIterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual UberOperation *currentItem() = 0;
    virtual ~OperationIterator();
};

#endif // OPERATIONITERATOR_H