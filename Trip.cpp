#include "Trip.h"
#include "TripState.h"
#include "ActiveTripIterator.h"
#include "RequestedState.h"

Trip::Trip()
{
    currentState = new RequestedState();
}

double Trip::getCost()
{
    return cost; // Base cost
}

void Trip::setCost(double cost){
    this->cost = cost;
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

// void Trip::assignDriver()
// {
//      currentState->assignDriver();
// }

// void Trip::startRide()
// {
//      currentState->startRide();
// }

// void Trip::endRide()
// {
//      currentState->endRide();
// }

void Trip::rideStatus(){
    currentState->rideStatus();
}

Trip::~Trip()
{
    if (currentState)
    {
        delete currentState;
    }
}
