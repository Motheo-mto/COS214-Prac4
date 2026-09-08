#ifndef TRIPSTATE_H
#define TRIPSTATE_H

#include <string>
#include "Trip.h"

class TripState
{
protected:
    Trip *context;
    std::string driverName = "unknown";

public:
    void setContext(Trip* ctx);
    virtual void getDriver() = 0;
    virtual void assignDriver(std::string) = 0;
    virtual void startRide() = 0;
    virtual void endRide() = 0;
    virtual void cancelRide() = 0;
    virtual void rideStatus() = 0;
    virtual ~TripState() = default;
};

#endif