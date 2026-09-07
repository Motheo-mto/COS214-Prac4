#include "UberBlackFeature.h"

UberBlackFeature::UberBlackFeature(UberOperation *op) : TripFeature(op) {}

double UberBlackFeature::getCost()
{
    return TripFeature::getCost() * 1.20; // 20% extra for UberBlack
}

std::string UberBlackFeature::getDescription()
{
    return TripFeature::getDescription() + " - UberBlack";
}

OperationIterator *UberBlackFeature::createIterator()
{
    return operation->createIterator();
}
