#include "InTransitState.h"
#include "CompletedState.h"
#include <iostream>

void InTransitState::getDriver(){
    std::cout << "Your driver is " + driverName  << std::endl;
}

// void InTransitState::startRide(){
//     std::cout<< "Ride in progress" << std::endl;
// }

void InTransitState::endRide(){
    std::cout << "You have arrived at your destination, ride complete!" << std::endl;
    TripState* state = new CompletedState();
    context->changeState(state);
}

void InTransitState::rideStatus(){
    std::cout<< "Ride in progress" << std::endl;
}

void InTransitState::cancelRide(){
    double cost = context->getCost();
    double charge = cost*0.6;
   
    context->setCost(charge);

    std::cout << "Ride cancelled, charge = " << charge << std::endl;
}