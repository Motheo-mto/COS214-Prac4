#include "Trip.h"
#include "TripState.h"
#include "ActiveTripIterator.h"

Trip::Trip()
{
    // currentState = new RequestedState(this);
}

double Trip::getCost()
{
    return 50.0; // Base cost
}

std::string Trip::getDescription()
{
    return "Standard Trip";
}

OperationIterator *Trip::createIterator()
{
    return new ActiveTripIterator(this); // generic iterator
}

void Trip::changeState(TripState *s)
{
    if (currentState)
    {
        delete currentState;
    }
    currentState = s;
}

void Trip::assignDriver()
{
    // currentState->assignDriver();
}

void Trip::startRide()
{
    // currentState->startRide();
}

void Trip::endRide()
{
    // currentState->endRide();
}

Trip::~Trip()
{
    if (currentState)
    {
        delete currentState;
    }
}
