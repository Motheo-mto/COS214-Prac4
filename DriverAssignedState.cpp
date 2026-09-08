#include "DriverAssignedState.h"
#include "InTransitState.h"
#include <iostream>

void DriverAssignedState::assignDriver(std::string driver){
    driverName = driver;
}

void DriverAssignedState::getDriver(){
    std::cout << "Your driver is " + driverName <<std::endl;
  
}

 void DriverAssignedState::endRide(){
     std::cout << "Ride has not started yet" << std::endl;
 }

void DriverAssignedState::rideStatus(){
    std::cout << "Driver on their way, ride not started" << std::endl;

}
void DriverAssignedState::startRide(){
    std::cout << driverName +" has arrived, starting uber ride..." << std::endl;
    TripState* state = new InTransitState();
    context->changeState(state);
}

void DriverAssignedState::cancelRide(){
    double cost = context->getCost();
    double charge = cost*0.6;
   
    context->setCost(charge);

    std::cout << "Ride cancelled, charge = " << charge << std::endl;
}