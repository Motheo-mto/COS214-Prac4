#ifndef REQUESTEDSTATE_H
#define REQUESTEDSTATE_H

#include <string>
#include "TripState.h"

class RequestedState: public TripState{
    public:
    void getDriver() override;
    // void startRide() override;
    // void endRide() override;
    void rideStatus() override;
    void cancelRide() override;
};


#endif