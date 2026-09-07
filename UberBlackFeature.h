#ifndef UBERBLACKFEATURE_H
#define UBERBLACKFEATURE_H

#include "TripFeature.h"
#include <iostream>

class UberBlackFeature : public TripFeature
{
public:
    UberBlackFeature(UberOperation *op);
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override;
};

#endif