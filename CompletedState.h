#ifndef COMPLETEDSTATE_H
#define COMPLETEDSTATE_H

#include "Trip.h"
#include "TripState.h"

#include <string>

class CompletedState : public TripState {
public:
  void getDriver() override;
  void rideStatus() override;
  void startRide() override;
  void endRide() override;
  void cancelRide() override;
  void assignDriver(std::string name) override;
};

#endif