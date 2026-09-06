#ifndef PRIORITYTRIPFEATURE
#define PRIORITYTRIPFEATURE

#include "TripFeature.h"
#include <iostream>

class PriorityTripFeature : public TripFeature
{
public:
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override;
};

#endif