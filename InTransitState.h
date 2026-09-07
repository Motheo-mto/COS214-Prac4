#ifndef INTRANSITSTATE_H
#define INTRANSITSTATE_H

#include "Trip.h"
#include "TripState.h"

class InTransitState: public TripState{

    public:
    void getDriver() override;
    void rideStatus() override;
    // void startRide() override;
    void endRide();
    void cancelRide() override;
};
#endif