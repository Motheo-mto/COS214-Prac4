#include "TripFeature.h"

TripFeature::TripFeature(UberOperation *op) : operation(op) {}

double TripFeature::getCost()
{
    return operation->getCost();
}

void TripFeature::setCost(double cost)
{
    operation->setCost(cost);
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
