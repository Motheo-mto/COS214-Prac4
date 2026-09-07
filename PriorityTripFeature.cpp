#include "PriorityTripFeature.h"

PriorityTripFeature::PriorityTripFeature(UberOperation *op) : TripFeature(op) {}

double PriorityTripFeature::getCost()
{
    return TripFeature::getCost() * 1.10; // 10% extra for priority
}

std::string PriorityTripFeature::getDescription()
{
    return TripFeature::getDescription() + " - Priority";
}

OperationIterator *PriorityTripFeature::createIterator()
{
    return operation->createIterator();
}
