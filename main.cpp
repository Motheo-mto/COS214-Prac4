#include <iostream>

#include "ActiveTripIterator.h"
#include "CompletedState.h"
#include "CompleteHierarchyIterator.h"
#include "DriverAssignedState.h"
#include "InTransitState.h"
#include "OperationIterator.h"
#include "PriorityTripFeature.h"
#include "Region.h"
#include "RequestedState.h"
#include "Trip.h"
#include "TripFeature.h"
#include "TripState.h"
#include "UberBlackFeature.h"
#include "UberOperation.h"

int main() {

    // Setting up all the locations

    UberOperation *Gauteng = new Region("Gauteng");
    UberOperation *Pretoria = new Region("Pretoria");
    UberOperation *Hatfield = new Region("Hatfield");
    UberOperation *UP_Campus = new Region("UP_Campus");
    UberOperation *Brooklyn = new Region("Brooklyn");
    UberOperation *Johannesburg = new Region("Johannesburg");

    Gauteng->setDescription("Gauteng province");
    Pretoria->setDescription("City of Pretoria");
    Johannesburg->setDescription("City of Johannesburg");
    Hatfield->setDescription("Suburb in Pretoria");
    Brooklyn->setDescription("Suburb in Preoria");
    UP_Campus->setDescription("Main Campus of UP");

    Hatfield->add(UP_Campus);
    Pretoria->add(Hatfield);
    Pretoria->add(Brooklyn);
    Gauteng->add(Pretoria);
    Gauteng->add(Johannesburg);

    // setting up all the trips

    UberOperation *Sudud = new Trip();
    UberOperation *Motheo = new Trip();
    UberOperation *Tshego = new Trip();

    Tshego->setCost(30.0);
    Sudud->setCost(60.0);
    Motheo->setCost(90.0);

    UberOperation *UBMotheo = new UberBlackFeature(Motheo);
    UberOperation *PSudud = new PriorityTripFeature(Sudud);

}