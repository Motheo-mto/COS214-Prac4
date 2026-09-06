#ifndef REGION_H
#define REGION_H

#include "UberOperation.h"
#include <list>
#include <string>

class Region : public UberOperation
{
private:
    std::list<UberOperation *> operations;

public:
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override;
    void add(UberOperation *a) override;
    void remove(UberOperation *r) override;
    ~Region() override;
};

#endif // REGION_H
