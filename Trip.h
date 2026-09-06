#ifndef TRIP_H
#define TRIP_H

#include "UberOperation.h"
#include <string>

class TripState; // Forward declaration for State Pattern

class Trip : public UberOperation
{
private:
    TripState *currentState;

public:
    double getCost() override;
    std::string getDescription() override;
    OperationIterator *createIterator() override;
    void changeState(TripState *s);
    void assignDriver();
    void startRide();
    void endRide();
    ~Trip() override;
};

#endif // TRIP_H
