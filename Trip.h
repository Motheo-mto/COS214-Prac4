#ifndef TRIP_H
#define TRIP_H

#include "UberOperation.h"
#include <string>

class TripState; // Forward declaration for State Pattern

class Trip : public UberOperation
{
private:
    friend class ActiveTripIterator;
    TripState *currentState;
    double cost = 50.0;

public:
    Trip();
    double getCost() override;
    void setCost(double) override;
    std::string getDescription() override;
    OperationIterator *createIterator() override;
    void changeState(TripState *s);
    // void assignDriver();
    // void startRide();
    // void endRide();
    void rideStatus();
    ~Trip() override;
};

#endif // TRIP_H
