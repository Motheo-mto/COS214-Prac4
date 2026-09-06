#ifndef TRIPFEATURE_H
#define TRIPFEATURE_H

#include "UberOperation.h"
#include "OperationIterator.h"
#include <iostream>

class TripFeature : public UberOperation
{
protected:
    UberOperation *operation;

public:
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override = 0;
    ~TripFeature() override;
};

#endif