#include "CompletedState.h"
#include <iostream>

void CompletedState::getDriver(){
    std::cout << "Your driver for the completed ride was " + driverName << std::endl;
}

void CompletedState::rideStatus(){
    std::cout << "You have arrived at your destination, ride complete" << std::endl;
}

void CompletedState::cancelRide(){
    std::cout << "Cannot cancel ride, ride is already complete" << std::endl;
}

void CompletedState::assignDriver(std::string name){
    std::cout << "Cannot assign driver, ride is already complete" << std::endl;
}

void CompletedState::startRide(){
    std::cout << "Cannot start ride, ride is already complete" << std::endl;
}

void CompletedState::endRide(){
    std::cout << "Cannot end ride, ride is already complete" << std::endl;
}