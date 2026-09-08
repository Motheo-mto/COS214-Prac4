#ifndef DRIVER_ASSIGNED_STATE_H
#define DRIVER_ASSIGNED_STATE_H

#include "TripState.h"
#include "Trip.h"

#include <string>

class DriverAssignedState: public TripState{

    public:
    void assignDriver(std::string driverName);
    void getDriver() override;
    void rideStatus() override;
    void startRide() override;
    void endRide() override;
    void cancelRide() override;

};
#endif