#include "RequestedState.h"
#include "DriverAssignedState.h"
#include <iostream>

void RequestedState::getDriver()
{
   std::cout << "Driver found!" << std::endl;
   TripState *state = new DriverAssignedState();
   state->assignDriver(driverName);
   context->changeState(state);
}

void RequestedState::startRide()
{
   std::cout << "Cannot start ride yet still searching for driver" << std::endl;
}

void RequestedState::endRide()
{
   std::cout << "Ride does not exist yet" << std::endl;
}

void RequestedState::rideStatus()
{
   std::cout << "Ride does not exist yet" << std::endl;
}

void RequestedState::cancelRide()
{
   std::cout << "Ride cancelled" << std::endl;
}

void RequestedState::assignDriver(std::string driver)
{
   this->driverName = driver;
}