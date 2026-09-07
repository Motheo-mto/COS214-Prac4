#ifndef TRIPFEATURE_H
#define TRIPFEATURE_H

#include "OperationIterator.h"
#include "UberOperation.h"
#include <iostream>

class TripFeature : public UberOperation
{
    friend class ActiveTripIterator;

protected:
    UberOperation *operation;

public:
    TripFeature(UberOperation *op);
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override = 0;
    ~TripFeature() override;
};

#endif