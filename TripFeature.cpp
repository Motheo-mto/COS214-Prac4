#include "TripFeature.h"

TripFeature::TripFeature(UberOperation *op) : operation(op) {}

double TripFeature::getCost()
{
    return operation->getCost();
}

std::string TripFeature::getDescription()
{
    return operation->getDescription();
}

TripFeature::~TripFeature()
{
    if (operation)
    {
        delete operation;
    }
}
